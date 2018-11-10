#include<stdio.h>

int fibonocci_series(unsigned long num, unsigned long next_num, unsigned long index, unsigned long length) {

    if(index >= length)
        return 0;

    printf("%lu ",num);
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

    printf("unsigned long %d ", sizeof(unsigned long));

    fibonocci_series(0, 1, 0, (unsigned long)size);

    printf("\n");

    return 0;
}
