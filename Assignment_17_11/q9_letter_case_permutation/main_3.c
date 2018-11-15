#include<stdio.h>
#include<string.h>

int convert(char *element_ptr) {
    int ret = 0;
    char element = *element_ptr;

    if( (element >= 'a' ) && (element <= 'z')) {
        element = element - 'a' + 'A';
        ret = 1;
    } else if((element >= 'A') && (element <= 'z')) {
        element = element - 'A' + 'a';
        ret = 1;
    }

    *element_ptr = element;
    return ret;
}

int letter_case_perm(char *str, int index) {

    if (index < 0) {
        printf("%s\n",str);
        return 0;
    }

    letter_case_perm(str, index -1);

    if(convert(&str[index]))
        letter_case_perm(str, index -1);

    return 0;
}


int main()
{
    char str[100] = {0};

    printf("Enter the string:");
    scanf("%s",&str[0]);

    letter_case_perm (str, strlen(str)-1);

    return 0;
}
