#include <stdio.h>
#include <string.h>



int palindrome (char *string, int index, int len) {

    if(index >= (len/2)) {
        return 1;
    }

    if (string[index] == string[len - index])
        return palindrome(string, index + 1, len);

    return 0;
}


int main()
{
    int size   = 0;
    char string[100] = {0};
    int  len      = 0;

    printf("Enter the string:");
    scanf("%s", string);

    len = strlen(string);

    if(palindrome(string, 0, len-1)) {
        printf("Yes %s is palindrome\n", string);
        return 0;
    }

    printf("Not palindrome");

    return 0;
}
