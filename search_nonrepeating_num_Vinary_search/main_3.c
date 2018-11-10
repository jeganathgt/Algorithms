#include<stdio.h>

int find_single_number(int *a, int *number, int start, int end) {

    int pivot = 0;
    int pivot_index = 0;

    pivot_index = (start+ end) /2;
    pivot       = a[pivot_index];

    if (pivot_index == 0) {
        /* 
         * pivot_index at the begining of array 
         */
        if( pivot != a[pivot_index +1]) { 
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
        if( pivot != a[pivot_index - 1]) { 
            if(number != NULL) 
                *number = pivot;
            return pivot_index;
        } else {
            return -1;
        }
    }

    if(pivot_index%2) {
        if (pivot == a[pivot_index - 1]) {
        /* 
         * search to the right of the array 
         */
            return find_single_number(a, number, pivot_index+1, end);
        } else if (pivot == a[pivot_index + 1]){
        /* 
         * search left side of array 
         */
            return find_single_number(a, number, start, pivot_index-1);
        }
    } else {
         if (a[pivot_index] == a[pivot_index + 1]) {
        /* 
         * search to the right of the array 
         */
            return find_single_number(a, number, pivot_index+1, end);
        } else if (pivot == a[pivot_index -1]){
        /* 
         * search left side of array 
         */
            return find_single_number(a, number, start, pivot_index-1);
        }
    }

    if(number != NULL) 
        *number = pivot;

    return pivot_index;
}


int main()
{
    int i      = 0;
    int number = 0;
    int a[100] = {0};
    int size   = 0;

    /* 
     * The size of array should be odd number
     * since only one element in array will be single 
     */ 
    printf("Enter the size of array in odd numbers:");
    scanf("%d",&size);

    if(size%2 == 0) {
        printf("Not a odd number\n");
        return 0;
    }

    printf("Enter the array:");
    for(i = 0; i < size; i++) {
        scanf("%d",&a[i]);
    }

    i = find_single_number(a, &number, 0, size-1);
    printf("index = %d\n",i);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;
}
