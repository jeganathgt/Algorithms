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

    cur_node = &list->head;
    while(cur_node->next != NULL) {
        pos--;
        if(!pos)
            break;
        cur_node = cur_node->next;
    }

    if(!pos)
        data = cur_node->data;
    return data;
}


int update_at (array_list_t *list, int pos, void* data) {
    node_t *cur_node = NULL;

    cur_node = &list->head;
    while(cur_node->next != NULL) {
        if(!pos)
            break;
        cur_node = cur_node->next;
        pos--;
    }

    if(cur_node->next != NULL) {
        cur_node->data = data;
    }
    return 0;
}

int get_size(array_list_t *list) {
    return list->size;
}

void* delete_at (array_list_t *list, int pos) {
    node_t *cur_node = NULL;
    void   *data     = NULL;

    cur_node = &list->head;
    while(cur_node->next != NULL) {
        if(!pos)
            break;
        cur_node = cur_node->next;
        pos--;
    }

    if(cur_node->next != NULL) {
        data = cur_node->data;
        cur_node->data = cur_node->next->data;
        cur_node = cur_node->next;

        free(cur_node);
        list->size--;
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

    cur_node = &list->head;
    while(cur_node->next != NULL) {
        if(!pos)
            break;
        cur_node = cur_node->next;
        pos--;
    }

    if(cur_node->next != NULL)
        new_node->next = cur_node->next->next;

    cur_node->next = new_node;

    list->size++;
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
    printf("%d\n", *(int *)new_node->data);

    list->size++;
    return 0;
}


int main()
{
    int size   = 0;
    int i = 0;
    int *num = NULL;
    array_list_t list = {0};

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

    for (i = 1; i<size; i++) {
       num = (int*)retrieve(&list, i);
       printf("%d, pos = %d\n", *num, i);
    } 

    printf("\n");

    return 0;
}
