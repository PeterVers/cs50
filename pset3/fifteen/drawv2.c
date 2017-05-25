#include <cs50.h>
#include <stdio.h>
#define DIM_MIN 3
#define DIM_MAX 9

//Implements the functions to be used within the Game of Fifteen

int board[DIM_MAX][DIM_MAX];

void init(int dim)
{
    int board_value = (dim*dim)-1;
    int num_swap;
    board[0][0] = board_value;
    {
        for(int i = 0; i < dim; i++)
        {
            for(int j = 0; j < dim; j++)
            {
                board[i][j] = board_value;
                board_value--;
                if(board[i][j] == 0)
                board[i][j] = (dim*dim);
            }
        }
        if((dim*dim-1) % 2)
        {    
            num_swap = board[dim-1][dim-3];
            board[dim-1][dim-3] = board[dim-1][dim-2];
            board[dim-1][dim-2] = num_swap;
        }
    }
}     

int draw(int dim)
{
   int init_start;
   char c = '_';
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {   
           if(board[i][j] == (dim*dim))
           {
               printf("%2c ", c);
               init_start = board[i][j];
           }
           else
               printf("%2i ", board[i][j]);
        }
        printf("\n");
    }
    return init_start;
}

bool move(int target_num, int current_blank_space, int dim)
{
    int blank_space = current_blank_space;
    int num_swap = 0;
    int bs_row, bs_column, cn_row, cn_column;
    int chosen_num = target_num;
    int range = (dim*dim)-1;
    if(chosen_num < 0 || chosen_num > range)
    {
        printf("Error: That number is not among the possible choices.\n");
        return false;
    }
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(target_num == board[i][j])
            {
                cn_row = i;
                cn_column = j;
                for(int k = 0; k < dim; k++)
                {
                    for(int l = 0; l < dim; l++)
                    {
                        if(blank_space == board[k][l])
                        {
                            bs_row = k;
                            bs_column = l; 
                        }
                    }
                }
            }
        }
    }
    if(((bs_row == cn_row + 1 || bs_row == cn_row - 1) && bs_column == cn_column) || ((bs_column == cn_column + 1 || bs_column == cn_column - 1) && bs_row == cn_row))
    {
        num_swap = board[bs_row][bs_column];
        board[bs_row][bs_column] = board[cn_row][cn_column];
        board[cn_row][cn_column] = num_swap;
        draw(dim);
        return true;
    }
                            
    else
    {
        printf("That is not a legal move.\n");
        return false;
    }
}

bool won(int dim)
{
    bool win_config;
    int true_count = 0;
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if((board[i][j] < board[i][j+1] || board[i][j] < board[i+1][j-(dim-1)]) && i <= dim-1 && j <= dim-1)
            {
                win_config = true;
                true_count++;
            }
            else
                win_config = false;
        }
        
        if(true_count == (dim*dim)-1)
        {
            win_config = true;
        }
    }
    return win_config;
}
    
int main(void)
{
    int d, target_num, blank_space;
    printf("Please enter the dimensions of the board.\n");
    scanf("%i", &d);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    init(d);
    blank_space = draw(d);
    while(!(won(d)))
    {
        printf("Please choose a target number.\n");
        scanf("%i", &target_num);
        move(target_num, blank_space, d);
            
    }
    printf("Congratulations! You've won!\n");
    return 0;
}

