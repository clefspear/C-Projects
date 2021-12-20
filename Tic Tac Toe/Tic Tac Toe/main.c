//
//  Extra Credit.c
//
//
//  Created by Peter Azmy on 12/08/17.
//
#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void displayboard(void);

int main(void)
{
    char done;
    
    printf("Welcome to Peter's Game of Tic-Tac-Toe!\n");
    printf("You will be playing against the computer.\n");
    
    done =  0;
    init_matrix();
    
    do {
        displayboard();
        get_player_move();
        done = check(); /*Check if there is a winner */
        if(done!= 0) break;
        get_computer_move();
        done = check();
    } while(done== 0);
    
    if(done=='X') printf("You won!\nYou are smarter than a code written by\na stressed coder on Red BUll!\n");
    else printf("Computer Wins!\nTry Better Next Time\n");
    displayboard();
    
    return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
    int i, j;
    
    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matrix[i][j] =  0;
}

/* Get a player's move. */
void get_player_move(void)
{
    int X, Y;
    
    printf("Enter the coordinates (X,Y) to put it on the board: ");
    scanf("%d%*c%d", &X, &Y);
    
    X--; Y--;
    
    if(matrix[X][Y]!= 0){
        printf("Invalid move, try again.\n");
        get_player_move();
    }
    else matrix[X][Y] = 'X';
}

/* Get a move from the computer. */
void get_computer_move(void)
{
    int i, j = 0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++)
            if(matrix[i][j]==0) break;
        if(matrix[i][j]==0) break;
    }
    
    if(i*j==9)  {
        printf("draw\n");
        exit(0);
    }
    else
        matrix[i][j] = 'O';
}

/*Display the Board*/
void displayboard(void)
{
    int i;
    
    for(i=0; i<3; i++)
    {
        printf(" %c | %c | %c ",matrix[i][0],matrix[i][1], matrix [i][2]);
        if(i!=2) printf("\n--|--|--\n");
    }
    printf("\n");
}

/* Checks if three in a row */
char check(void)
{
    int x;
    
    for(x=0; x<3; x++)  /*rows*/
        if(matrix[x][0]==matrix[x][1] &&
           matrix[x][0]==matrix[x][2]) return matrix[x][0];
    
    for(x=0; x<3; x++)  /*columns*/
        if(matrix[0][x]==matrix[1][x] &&
           matrix[0][x]==matrix[2][x]) return matrix[0][x];
    
    /*diagonals*/
    if(matrix[0][0]==matrix[1][1] &&
       matrix[1][1]==matrix[2][2])
        return matrix[0][0];
    
    if(matrix[0][2]==matrix[1][1] &&
       matrix[1][1]==matrix[2][0])
        return matrix[0][2];
    
    return 0;
}
