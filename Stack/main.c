#include <stdio.h> 
#include <stdlib.h> 

typedef struct stack_s
{ 
    int top; 
    int num_of_elements; 
    unsigned int size; 
    int* array; 
} stack_t;
  
stack_t* createStack(unsigned int size) 
{ 
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t)); 
    stack->size            = size;
    stack->num_of_elements = 0;
    stack->top      = 0;  // This is important, see the push 
    stack->array = (int*) malloc(stack->size * sizeof(int)); 
    return stack; 
}

int isFull(stack_t* stack) 
{  return ((stack->top) >= stack->size); }


int isEmpty(stack_t* stack) 
{  return (stack->top == 0); }
  

int push(stack_t* stack, int item) 
{
    
    if (isFull(stack)) 
        return -1;


    stack->array[stack->top] = item;
    stack->top++;

    stack->num_of_elements++;
    printf("%d pushd to stack\n", item);
    return 0;
} 
  

int pop(stack_t* stack) 
{ 
    int item = 0;

    if (isEmpty(stack)) 
        return -1; 

    stack->top--;
    item = stack->array[stack->top]; 

    stack->num_of_elements--;
    return item; 
} 
 
  
// Driver program to test above functions./ 
int main() 
{ 
    stack_t* stack = createStack(5); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
    push(stack, 40); 
    push(stack, 50); 
    printf("%d push\n", push(stack, 60)); 

    printf("isFull %d\n", isFull(stack));
  
    printf("%d popd from stack\n\n", pop(stack)); 
    printf("%d popd from stack\n\n", pop(stack)); 
    printf("%d popd from stack\n\n", pop(stack)); 
    printf("%d popd from stack\n\n", pop(stack)); 
    printf("%d popd from stack\n\n", pop(stack)); 
    printf("%d popd from stack\n\n", pop(stack)); 
  
  
    return 0; 
}  
 
