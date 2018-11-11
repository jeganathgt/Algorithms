#include<stdio.h>

int find_max_number(int *a, int *number, int start, int end) {

    int big_num = *number;

    if(a[start] > *number) {
        *number = a[start];
    }

    if(a[end] > *number) {
        *number = a[end];
    }

    if(start >= end) {
        return 0;
    }

    return find_max_number(a, number, start+1, end-1);
}


int main()
{
    int i      = 0;
    int number = 0;
    int a[100] = {0};
    int size   = 0;

    printf("Enter the size of array:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    printf("Enter the array:");
    for(i = 0; i < size; i++) {
        scanf("%d",&a[i]);
    }

    i = find_max_number(a, &number, 0, size-1);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;
}
