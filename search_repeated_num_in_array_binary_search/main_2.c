#include<stdio.h>

int find_repeated_number(int *a, int *number, int start, int end) {
    
    int pivot_index = 0, pivot = 0;

    if(start == end) {
        return -1;
    }

    pivot_index = (start + end)/2;
    pivot       = a[pivot_index];

    if ( (pivot_index < end) && (pivot == a[pivot_index + 1]) ) {
        if(number != NULL) 
            *number = pivot;
        return pivot_index;
    }

    if ( (pivot_index > start) && (pivot == a[pivot_index - 1]) ) {
        if(number != NULL) 
            *number = pivot;
        return pivot_index;
    }

    if(pivot_index == (pivot - 1)) {
        return find_repeated_number(a, number, pivot_index + 1, end);
    } else {
        return find_repeated_number(a, number, start, pivot_index - 1);
    }

}


int main()
{
    int i = 0;
    int number = 0;
    int a[100] = {0};
    int size   = 0;

    printf("Enter the size of array:");
    scanf("%d",&size);

    printf("Enter the array:");
    for(i = 0; i < size; i++) {
        scanf("%d",&a[i]);
    }

    i = find_repeated_number(a, &number, 0, size-1);
    printf("index = %d\n",i);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;

}
