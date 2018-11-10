#include<stdio.h>

int fibonocci_series(int num, int next_num, int index, int length) {

    if(index >= length)
        return 0;

    printf("%d ",num);
    return fibonocci_series(next_num, num + next_num, index+1, length);
}

int main()
{
    int size   = 0;

    printf("Enter the length of series:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    fibonocci_series(0, 1, 0, size);

    printf("\n");

    return 0;
}
