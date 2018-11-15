#include <stdio.h>
#include <string.h>

#define INTERVAL_SIZE 5

int print_number (int number, int interval) {

    printf("%d ", number);

    if(number <= 0)
        return 0;

    print_number(number-interval, interval);

    printf("%d ", number);

    return 0;
}


int main()
{
    int  number   = 0;

    printf("Enter the number:");
    scanf("%d", &number);


    print_number(number, INTERVAL_SIZE);
    printf("\n");
    return 0;
}
