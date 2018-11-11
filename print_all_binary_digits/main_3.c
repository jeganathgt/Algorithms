#include<stdio.h>
#include <stdlib.h>

int print_binary_digits(char *arr, int start, int length) {

    if(start >= length) {
        printf("%s\n",arr);
        return 0;
    }

    arr[start] = '0';

    print_binary_digits (arr, start+1, length);

    arr[start] = '1';

    print_binary_digits (arr, start+1, length);

    return 0;
}

int main()
{
    int  size    = 0;
    char *array = 0;

    printf("Enter the length of digits:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    array = (char *)calloc(1, (size));

    print_binary_digits(array, 0, size);

    printf("\n");

    return 0;
}
