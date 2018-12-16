#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int position[100]   = {0};

int board[20][20] = {0};


int dump_board (int *array, int dimension) 
{
    int i =0, j =0;
    static int count = 0;
    for(i = 0; i < dimension; i++) {
        board[i][array[i]] = 1;
    }

    printf("solution:%d:\n", ++count);
    printf("==================\n");
    for (i = 0; i <dimension; i++) {
        for (j = 0; j<dimension; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }

    printf("\n");
    for (i = 0; i <dimension; i++) {
        for (j = 0; j<dimension; j++)
            board[i][j] = 0;
    }

    return 0;

}

int willattack_downright(int row, int column, int *array, int dimension)
{
    int i = 0;
    int  r = 0, c = 0;
    int array_last_index = column;

    for(i = 0; i<array_last_index; i++) {
        r = array[i];
        c = i;

        while (r < dimension && c < dimension) {
            if(row == r && c == column) return 1;
            r++; c++;
        }
    }
    return 0;
}


int willattack_downleft(int row, int column, int *array, int dimension)
{
    int i = 0;
    int  r = 0, c = 0;
    int array_last_index = column;

    for(i = 0; i<array_last_index; i++) {
        r = array[i];
        c = i;

        while (r < dimension && c >= 0) {
            if(row == r && c == column) return 1;
            r++; c--;
        }
    }

    return 0;
}


int willattack_upright(int row, int column, int *array, int dimension)
{
    int i = 0;
    int  r = 0, c = 0;
    int array_last_index = column;

    for(i = 0; i<array_last_index; i++) {
        r = array[i];
        c = i;

        while (r >= 0 && c < dimension) {
            if(row == r && c == column) return 1;
            r--; c++;
        }
    }

    return 0;
}


int willattack_upleft(int row, int column, int *array, int dimension)
{
    int i = 0;
    int  r = 0, c = 0;
    int array_last_index = column;

    for(i = 0; i<array_last_index; i++) {
        r = array[i];
        c = i;

        while (r >= 0 && c >= 0) {
            if(row == r && c == column) return 1;
            r--; c--;
        }
    }

    return 0;
}


int willattack(int row, int column, int *array, int dimension)
{
    int i = 0;
    for (i = 0; i<column; i++) {
        if (array[i] == row || i == column) return 1;
        if (willattack_downright(row, column, array, dimension)) return 1;
        if (willattack_downleft (row, column, array, dimension)) return 1;
        if (willattack_upleft   (row, column, array, dimension)) return 1;
        if (willattack_upright  (row, column, array, dimension)) return 1;
    }

    return 0;
}


int place_queen(int column, int *array, int dimension) 
{

    int i = 0;
    int k = 0;

    if(column >= dimension) {
        dump_board(array, dimension);
        return 0;
    }

    for (i = 0; i < dimension; i++) {
        if (willattack(i, column, array, dimension)) continue;

        array[column] = i;
        place_queen(column+1, array, dimension);
    }

    return -1;
}


int main()
{
    int number    = 0;

    printf("Enter the number:");
    scanf("%d",&number);

    place_queen(0, position, number);

    return 0;
}
