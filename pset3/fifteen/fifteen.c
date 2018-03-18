
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
int d,x,y;
bool a;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void right(int);
void left(int);
void up(int);
void down(int); 

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
    {   a=0;
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
    usleep(20000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{   int s=1;
 if(d==3)
  for(int i=0;i<d;i++)
    for(int j=0;j<d;j++)
  {  board[i][j]=9-s;
     s++;
     }
 else{
    for(int i=0;i<d;i++)
    for(int j=0;j<d;j++)
    {
    board[i][j]=d*d-s;
    if(2==(d*d-s))
    board[i][j]=1;
    if(1==d*d-s)
    board[i][j]=2;
    s++;
    }
    
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
 {    
     for(int i=0;i<d;i++)
    {
      for(int j=0;j<d;j++)
      if(board[i][j]<10)
      printf("%i |",board[i][j]);
      else
      printf("%i|",board[i][j]);
      printf("\n");
    }
   }
 
  void right(int tile)
  { 
   if(board[x][y+1]==tile)
    {  a=1;
       board[x][y+1]=0;
       board[x][y]=tile;
      
     }
  
   }  
  void left(int tile)
  {
   if(board[x][y-1]==tile)
    { a=1;
       board[x][y-1]=0;
       board[x][y]=tile;
       
       }
     
   }
    
  void up(int tile)
  {
   if(board[x-1][y]==tile)
      { a=1;
       board[x-1][y]=0;
       board[x][y]=tile;
       
       }
   
   }
    
  void down(int tile)
  {
   if(board[x+1][y]==tile)
    { a=1;
       board[x+1][y]=0;
       board[x][y]=tile;
       
       }

   }
  bool move(int tile)
   {  
      for(int c=0;c<d;c++)
      for(int b=0;b<d;b++)
        if(board[c][b]==0)
       {  x=c;
          y=b; 
       }
      
     if(x==0||x==(d-1)||y==0||y==(d-1))   
       {
		 if(x==0)
         { 
            if(y==0)
          {
         right(tile);
        
         down(tile);
         
       
         }
          if(y==(d-1))
          {
          left(tile);
       
          down(tile);
       
       
      }
		  }
          
    if((x==0&&y>0)&&y<d)
       { right(tile);
       
        left(tile);
      
        down(tile);
      
        
        }
    
      if(x==(d-1))
       {
        if(y==0)
         {
         right(tile);
       
        up(tile);
      
       
         }
       if(y==(d-1))
          {
          left(tile);
         
          up(tile);
         
        
          }
      }
          if(x==(d-1)&&y>0&&y<d)
       { right(tile);
     
        left(tile);
         
        up(tile);
       
       
        }
       
        if((y==0&&x>0)&&x<d)
        { right(tile);
          up(tile);
          down(tile);
          }
        
        if(y==(d-1)&&(x>0&&x<d))
        { left(tile);
          up(tile);
          down(tile);
          }
        return a;
  }

    if((x>0&&x<d)&&(y>0&&y<d))
    {
       right(tile);
     
        down(tile);
       
        left(tile);
       
        up(tile);
        
       return a; 
     
    }
  
   return true;
    }
 
  bool won(void)
   { int s=1,c=1,correct[d][d];
     for(int i=0;i<d;i++)
     for(int j=0;j<d;j++)
   { 
     correct[i][j]=s;
     s++;
     }
     for(int i=0;i<d;i++)
    for(int j=0;j<d;j++)
   if(board[i][j]==correct[i][j])
      c++;
      
    if(c==d*d)
    return true;
    else
    return false;
}