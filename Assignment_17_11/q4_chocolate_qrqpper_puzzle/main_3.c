#include <stdio.h>
#include <string.h>


int chocolate_count (int *total_chocolate, int current_no_of_wrap, int warp_for_chocolate) {

    int i = 0;
    int new_chocolate_cnt = 0;
    int nw_wraps = 0;

    if (current_no_of_wrap < warp_for_chocolate)
        return 0; 

    for(current_no_of_wrap; (current_no_of_wrap - warp_for_chocolate) >= 0; current_no_of_wrap-=warp_for_chocolate)
        new_chocolate_cnt++;

    nw_wraps = new_chocolate_cnt + current_no_of_wrap/*This denotes pending count */; 

    (*total_chocolate) = (*total_chocolate) + new_chocolate_cnt;

    return chocolate_count (total_chocolate, nw_wraps, warp_for_chocolate);
}


int main()
{
    int  money   = 0;
    int  price   = 0;
    int  warp_for_chocolate   = 0;
    int  total_chocolate   = 0;
    int  current_wrap   = 0;

    printf("Enter the total money:");
    scanf("%d", &money);

    printf("Enter the price chocolate:");
    scanf("%d", &price);

    printf("Enter the wrap for chocolate:");
    scanf("%d", &warp_for_chocolate);

    total_chocolate = money / price;

    current_wrap = total_chocolate;

    chocolate_count(&total_chocolate, current_wrap, warp_for_chocolate);

    printf("total chocolate cnt %d\n", total_chocolate);
    return 0;
}
