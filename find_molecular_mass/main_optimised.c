#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_node {
    struct stack_node *next;
};

struct stack_dm {
    struct stack_node *sp;
    unsigned int limit;
    unsigned int current_count;
};

struct stack_dm *init_stack(int limit) 
{
    struct stack_dm *stack = calloc(1, sizeof(struct stack_dm));
    stack->limit = limit;
    return stack;
}


int push(struct stack_dm *stack, struct stack_node *node)
{
    if ((stack == NULL) || (stack->current_count >= stack->limit))
	    return -1;

    if (stack->sp == NULL) {
        stack->sp = node;
    } else {
        node->next = stack->sp;
	stack->sp = node;
    }
    stack->current_count++;
    return 0;
}

int pop(struct stack_dm *stack, struct stack_node **node)
{
    if((stack == NULL) || (stack->sp == NULL) )
        return -1;

    *node                   = stack->sp;
    stack->sp               = stack->sp->next;
    stack->current_count--;
    return 0;
}

struct molecule_cnt{
	int C, H, O;
	struct stack_node node;
};

int push_stack(struct stack_dm *stack, int C, int H, int O)
{
    struct molecule_cnt *data = calloc(1, sizeof(struct molecule_cnt));
    data->C = C;
    data->H = H;
    data->O = O;
    return push(stack, &data->node);
}

#define OFFSET(type, variable) ((char *)(&(((type *)(0))->variable)))

int pop_stack (struct stack_dm *stack, int *C, int *H, int *O) {

    struct stack_node *node = NULL;

    if (pop(stack, &node) < 0)
	    return -1;

    struct molecule_cnt *data = NULL;

    data = (struct molecule_cnt *)((char *)(node) - OFFSET(struct molecule_cnt, node));
    
    *C = data->C;
    *H = data->H;
    *O = data->O;
    free(data);
    return 0;
}


#define INPUT_SIZE 0xffffffff

int dump_stack(struct stack_dm *stack) {

   int C = 0, H = 0, O = 0;

   struct stack_dm *stack2 = init_stack(INPUT_SIZE);

   while (pop_stack(stack, &C, &H, &O) >=0) {
       printf("C=%d, H=%d, O=%d\n", C, H, O);
       push_stack(stack2, C, H, O);
   }

   while(pop_stack(stack2, &C, &H, &O) >= 0) {
       push_stack(stack, C, H, O);
   }
   printf("\n");
   free(stack2);
   return 0;
}


char string[INPUT_SIZE] = {0};

int main()
{
    struct stack_dm *stack  = init_stack(INPUT_SIZE);
    int C = 0, H = 0, O = 0;

    scanf("%s", string);

    for (int i=0; i < strlen(string); i++) {
        if (string[i] == '(' ) {
	    push_stack(stack, C, H , O);
	    //dump_stack(stack);
            C=0; H=0; O=0;	
	} else if ((string[i] > '0') && (string[i] <='9' )) {
            if (( i - 1) >= 0) {
	        if (string[i-1] == 'C') C *= string[i] - '0';
                if (string[i-1] == 'H') H *= string[i] - '0' ;
                if (string[i-1] == 'O') O *= string[i] - '0';
	    }
	} else if (string[i] == ')') {
            int times = (((i+1) < strlen(string)) && (((string[i+1] > '0') && (string[i+1] <= '9')))) ? string[++i] - '0' : 1;
            C *= times;	
            H *= times;	
            O *= times;	
	    int C_temp = 0, H_temp = 0, O_temp = 0;
	    pop_stack(stack, &C_temp, &H_temp, &O_temp);
	    //dump_stack(stack);
	    C += C_temp;
	    H += H_temp;
	    O += O_temp;
	} else {
	    if (string[i] == 'C') C++;
	    if (string[i] == 'H') H++;
	    if (string[i] == 'O') O++;
	}
    }
    //printf("C=%d, H=%d, O=%d\n",C,H,O);
    printf("%lld\n", (long long )(( C * 12 ) + ( H ) + ( O * 16 )));
    free(stack);
    return 0;
}
