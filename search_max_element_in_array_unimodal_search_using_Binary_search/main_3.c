#include<stdio.h>

int find_max_number(int *a, int *number, int start, int end) {

    int pivot = 0;
    int pivot_index = 0;

    pivot_index = (start+ end) /2;
    pivot       = a[pivot_index];

    if (pivot_index == 0) {
        /* 
         * pivot_index at the begining of array 
         */
        if( pivot > a[pivot_index +1]) { 
            if(number != NULL) 
                *number = pivot;
            return pivot_index;
        } else {
            return -1;
        }
    }

    if ((start == end) && (end != 0)) {
        /* 
         * pivot_index at the end of array 
         */
        if( pivot > a[pivot_index - 1]) { 
            if(number != NULL) 
                *number = pivot;
            return pivot_index;
        } else {
            return -1;
        }
    }

    if ((pivot > a[pivot_index + 1]) && (pivot > a[pivot_index - 1])) {
        if(number != NULL)
            *number = pivot;
        return pivot_index;
    }

    if ((a[pivot_index - 1] < pivot) && (pivot < a[pivot_index + 1])) {
        /* 
         * search to the right of the array 
         */
        return find_max_number(a, number, pivot_index+1, end);
    }

    if ((pivot < a[pivot_index - 1]) && (a[pivot_index + 1] < pivot)) {
        /* 
         * search left side of array 
         */
        return find_max_number(a, number, start, pivot_index-1);
    }

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
    printf("index = %d\n",i);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;
}
