#include<stdio.h>

int find_max_min_number(int *a, int *max_num, int *min_num, int index) {

    int num = 0;

    if (index <= 0) {
        *max_num = a[0];
        *min_num = a[0];
        return a[0];
    }

    num = find_max_min_number(a, max_num, min_num, index -1);
    if(num > *max_num)
        *max_num = num;
    else if (num < *min_num)
       *min_num = num;

    return a[index];
}


int main()
{
    int i      = 0;
    int max_num = 0;
    int min_num = 0;
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

    i = find_max_min_number(a, &max_num, &min_num, size);

    printf("max_num = %d, min_num %d\n", max_num, min_num);

    return 0;
}
