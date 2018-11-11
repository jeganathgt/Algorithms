#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int print_all_combinations (char *array, int arrey_len, int start, int length, char *output)
{
    int i;

    if(start >= length) {
        printf("%s\n",output);
        return 0;
    }

    for(i= 0; i <arrey_len; i++) {
        output[start] = array[i];
        print_all_combinations (array, arrey_len, start + 1, length, output);
    }


    return 0;
}

int main()
{
    int  size        =  0;
    char array[100]  = {0};
    char output[100] = {0};
    int  array_len    = 0;

    printf("Enter the length of combinations:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    scanf("%s",array);
    array_len = strlen(array);

    print_all_combinations (array, array_len, 0, size, output);

    printf("\n");

    return 0;
}
