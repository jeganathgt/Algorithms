#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;


typedef struct array_list {
    int size;
    node_t head;
} array_list_t;


void* retrieve (array_list_t *list, int pos) {
    node_t *cur_node = NULL;
    void   *data     = NULL;

    cur_node = list->head.next;
    while (cur_node != NULL) {
        pos--;
        if(!pos)
            break;

        cur_node = cur_node->next;
    }

    if(!pos)
        data = cur_node->data;

    return data;
}


void * update_at (array_list_t *list, int pos, void* data) {
    node_t *cur_node = NULL;
    void  *prev_data = NULL;

    cur_node = list->head.next;
    while(cur_node != NULL) {
        pos--;
        if(!pos)
            break;

        cur_node = cur_node->next;
    }

    if(!pos) {
        prev_data = cur_node->data;
        cur_node->data = data;
    }

    return prev_data;
}

int get_size(array_list_t *list) {
    return list->size;
}

void* delete_at (array_list_t *list, int pos) {
    node_t *cur_node = NULL;
    void   *data     = NULL;

    cur_node = list->head.next;
    while(cur_node != NULL) {
        pos--;
        if(!pos)
            break;

        cur_node = cur_node->next;
    }

    if(!pos) {
        data = cur_node->data;
        cur_node->data = cur_node->next->data;
        cur_node->next = cur_node->next->next;
        list->size--;
        free(cur_node->next);
    }

    return data;
}


int insert_at (array_list_t *list, void * data, int pos) {
    node_t *new_node = NULL;
    node_t *cur_node = NULL;

    new_node = (node_t *)calloc(1, sizeof(node_t));
    if(new_node == NULL)
        return -EINVAL;

    new_node->data = data;

    cur_node = list->head.next;
    while(cur_node != NULL) {
        pos--;
        if(!pos)
            break;

        cur_node = cur_node->next;
    }

    if(!pos) {
        new_node->next = cur_node->next;
        cur_node->next = new_node;
        list->size++;
    }

    return 0;
}


int add (array_list_t *list, void * data) {
    node_t *new_node = NULL; 
    node_t *cur_node = NULL; 

    new_node = (node_t *)calloc(1, sizeof(node_t));
    if(new_node == NULL)
        return -EINVAL;

    new_node->data = data;

    cur_node = &list->head;
    while(cur_node->next != NULL) cur_node = cur_node->next;

    cur_node->next = new_node;

    list->size++;
    return 0;
}


int main()
{
    int size   = 0;
    int i = 0;
    int *num = NULL;
    array_list_t list = {0};
    char *a = NULL;

    printf("Enter the length of series:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    for (i = 0; i<size; i++) {
       num = (int*)malloc(sizeof(int));
       scanf("%d",num);
       add(&list, num);
    }

    for (i = 1; i<=size; i++) {
       num = (int*)retrieve(&list, i);
       printf("%d, p = %d\n", *num, i);
    }

    for (i = 1; i<=size; i++) {
       a = (char*)malloc(sizeof(char));
       *a = 'a'+i ;

       num = (int*)insert_at(&list, a, i);
    }

    for (i = 1; i<=size; i++) {
       num = (int*)retrieve(&list, i);
       printf("%d, p = %d\n", *num, i);
    }

    printf("\n");

    return 0;
}
