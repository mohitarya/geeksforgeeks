#include <stdio.h>

#define ROWS        4 
#define COLUMNS     4

/* Function Declaration */
void print_2d_array(int arr[ROWS][COLUMNS]);
void print_2d_array_spiral(int arr[ROWS][COLUMNS]);
void print_row_left_to_right(int arr[ROWS][COLUMNS], int row, int column_start, int column_end);
void print_row_right_to_left(int arr[ROWS][COLUMNS], int row, int column_start, int column_end);
void print_column_up_to_down(int arr[ROWS][COLUMNS], int column, int row_start, int row_end);
void print_column_down_to_up(int arr[ROWS][COLUMNS], int column, int row_start, int row_end);

void print_column_down_to_up(int arr[ROWS][COLUMNS], int column, int row_start, int row_end)
{
    int i;
    for(i = row_start; i >= row_end; i--)
    {
        printf("%d\t", arr[i][column]);
    }
}

void print_column_up_to_down(int arr[ROWS][COLUMNS], int column, int row_start, int row_end)
{
    int i;
    for(i = row_start; i <= row_end; i++)
    {
        printf("%d\t", arr[i][column]);
    }
    
}

void print_row_right_to_left(int arr[ROWS][COLUMNS], int row, int column_start, int column_end)
{
    int i;
    for(i = column_start; i >= column_end; i--)
    {
        printf("%d\t", arr[row][i]);
    }
}

void print_row_left_to_right(int arr[ROWS][COLUMNS], int row, int column_start, int column_end)
{
    int i;
    for(i = column_start; i <= column_end; i++)
    {
        printf("%d\t", arr[row][i]);
    }
}


void print_2d_array_spiral(int arr[ROWS][COLUMNS])
{
    int lru, lcu, rru, rcu, lrd, lcd, rrd, rcd;
    lru = 0;                    // Left rows from UP
    lcu = 0;                    // Left column from UP
    rru = 0;                    // Right row from up
    rcu = COLUMNS - 1;          // Right column from up 
    lrd = ROWS - 1;             // Left rows from Down
    lcd = 0;                    // Left column from Down
    rrd = ROWS - 1;             // Right row from Down
    rcd = COLUMNS - 1;          // Right column from Down

    printf("lru=%d, lcu=%d, rru=%d, rcu=%d, lrd=%d, lcd=%d, rrd=%d, rcd=%d\n", lru, lcu, rru, rcu, lrd, lcd, rrd, rcd);
    if(lcu < rcu)
    {
        // Print row left to right
        print_row_left_to_right(arr, lru, lcu, rcu);        
        // Update the index
        lru++;
        rru++;
    }
    if(rru < rrd)
    {
        // Print column up to down
        print_column_up_to_down(arr, rcu, rru, rrd);
        // Update Index
        rcu--;
        rcd--;
    }
    if(rcd > lcd)
    {
        // Print row right to left
        print_row_right_to_left(arr, rrd, rcd, lcd);
        // Update Index
        rrd--;
        lrd--;
    }
    if(lrd > lru)
    {
        // Print column down to up
        print_column_down_to_up(arr, lcd, lrd, lru);
        // update index
        lcd++;
        lcu++;
    }
    printf("\nlru=%d, lcu=%d, rru=%d, rcu=%d, lrd=%d, lcd=%d, rrd=%d, rcd=%d\n", lru, lcu, rru, rcu, lrd, lcd, rrd, rcd);
}

void print_2d_array(int arr[ROWS][COLUMNS])
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        printf("\t\t");
        for(j = 0; j < COLUMNS; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    // Define a 2-D array
    int arr[ROWS][COLUMNS] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}, {13, 14, 15, 16}};
    print_2d_array(arr);

    // Print 2-D array in spiral format
    print_2d_array_spiral(arr);
    printf("\n");
    return 0;
}
