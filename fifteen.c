/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d, x, y;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}


/**
 * Prints the board in its current state.
 */
void init(void)
{
    // TODO
    int dsquared = (d * d);
    int n = 0;
 
    // two for loops to iterate through 2d array - rows/columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // this will initialize the array counting from largest number down to d * d - 1
            // n is used as a counter so we are subtracting by one more each time 
            n = n + 1;
            board[i][j] = (dsquared - n);
        }
    }   
    // if d is even and the tiles on board odd, swap 1 and 2 so game can be won
    if ((d % 2) == 0)
    {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp; 
    }               
}
 
/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO nested loops to draw board initialized above
 
    // initialize variables
    int n = 0;
 
    // iterate over rows
    for (int i = 0; i < d; i++)
    {
        // iterate over columns
        for (int j = 0; j < d; j++)
        {
            // subtract by one more each time
            n = (n + 1); 
 
            // print the number of the tile except for the 0 tile
            if (board[i][j] > 0) 
            {
                printf("| %2d ", board[i][j]);
            }
 
            // for 0 tile, print the space for tiles to move
            if (board[i][j] == 0) 
            {
                printf("| __ ");
            }
        }
        // print two lines after each row to make board
        printf("|\n\n"); 
    }    
}
 
/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO 
    // search board for user tile
    // iterate through rows to find tile
    for (int i = 0; i < d; i++) 
    {
        // iterate through columns to find tile
        for (int j = 0; j < d; j++) 
        {
            // if user entered tile that exists on the board
            if(tile == board[i][j]) 
            {
                // initialize variable for 0 
                int blankspace = 0;       
 
                // test if tile is adjacent to blankspace
                if (((x == (i - 1)) && (j == y)) ||  ((x == (i + 1)) && (j == y)) ||
                ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
                {
                    // printf("before:  tile %d, blankspace %d\n", tile, blankspace)
 
                    // swap tile with blankspace if tile is adjacent to blankspace
                    board[x][y] = tile;
                    board[i][j] = blankspace;
                    x=i;
                    y=j;
 
                    // printf("The position of the tile is board[%d][%d] = %2d.  Tile is %d\n", i, j, board[i][j], tile);
                    // printf("Blankspace position is: board[%d][%d] = %d\n", x, y, blankspace);
 
                    return true;
                }   
            } 
        }
    }
    return false;
}
 
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    // initializes variables
    int n = -1;
 
    // iterates through board
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++)
        {
            // creates counter
            n = n + 1;
 
            // if any tile != counter, counting from 0, return false
            if (board[i][j] != n)
            {
            return false;
            }
        } 
    }
    // otherwise, all tiles count up from 0, game won
    return true;
}
 
/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";
 
    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }
 
    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }
 
    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");
 
    // close log
    fclose(p);
}