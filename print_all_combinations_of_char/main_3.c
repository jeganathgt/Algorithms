#include<stdio.h>
#include <stdlib.h>

int print_all_combinations (char *array, int start, int length, char *output)
{
    int i;

    if(start >= length) {
        printf("%s\n",output);
        return 0;
    }

    for(i= 0; i<length; i++) {
        output[start] = array[i];
        print_all_combinations (array, start + 1, length, output);
    }


    return 0;
}

int main()
{
    int  size        =  0;
    char array[100]  = {0};
    char output[100] = {0};

    printf("Enter the length of combinations:");
    scanf("%d",&size);

    if(size == 0 ) {
        return 0;
    }

    scanf("%s",array);

    print_all_combinations (array, 0, size, output);

    printf("\n");

    return 0;
}
