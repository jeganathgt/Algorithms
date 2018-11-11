#include<stdio.h>
#include <string.h>


int find_substrings(char *str, int index, int length) {

    int count = 0;
    int i =0;

    if (index > length)
        return 0;

    for ( i=index; i<length; i++) {
        if(str[index] == str[i])
            count++;
    }

    return count + find_substrings(str, index+1, length);
}


int main()
{
    char str[100] = {0};
    int number    = 0;
    int length    = 0;

    printf("Enter the string:");
    scanf("%s",str);

    length = strlen(str);
    number = find_substrings(str, 0, length);

    if(number > 0) {
        printf("value = %d\n",number);
    }

    return 0;
}
