#include<stdio.h>
#include <string.h>

int ascii_to_num(char c) {
    if ((c >= '0') && (c <= '9'))
        return c - '0';
    else
        return 0;
}


int str_to_int(char *str, int index) {

    if(index < 0)
        return 0;

    return (str_to_int(str, index-1) * 10) + ascii_to_num(str[index]);
}


int main()
{
    char str[100] = {0};
    int number    = 0;

    printf("Enter the string:");
    scanf("%s",str);

    number = str_to_int(str, strlen(str)-1);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;
}
