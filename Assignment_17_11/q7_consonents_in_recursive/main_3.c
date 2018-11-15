#include <stdio.h>
#include <string.h>

int is_consonents(char element) {

    if( (element != 'a') && 
        (element != 'e') && 
        (element != 'i') &&
        (element != 'o') &&
        (element != 'u') )
        return 1;

    return 0;
}


char print_consonents (char *strings, int index, int *count) {

    char ret = '0';

    if(index <= 0)
        return strings[0];

    ret = print_consonents(strings, index-1, count);

    if (is_consonents(ret)) 
        (*count)++;

    return strings[index];
}


int main()
{
    char string[100] = {0};
    int  count = 0;

    printf("Enter the string:");
    scanf("%s", string);


    print_consonents(string, strlen(string), &count);
    printf("count: %d\n", count);
    return 0;
}
