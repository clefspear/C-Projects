/*
 * Sodoku Solver created by Peter Azmy
 */

#include <stdio.h>

int solveSudoku (int SodokuBoard[][9]);
int findAnUnassignedSpot (int SodokuBoard[][9], int row, int column);
int isValid (int number, int SodokuBoard[][9], int row, int column);
int sudokuHelper (int SodokuBoard[][9], int row, int column);
void printSudoku (int SodokuBoard[][9]);

int
main (int argc, char **argv)
{
    printf
    ("Welcome to Peter Azmy's Final Project, a Sodoku Solver!\nI can read Sodoku from both text files\nOr by simply typing the numbers line by line!\nBe sure to use 0 for blanks if you type it in\nand I'll do the rest of the work!\n");
    int SodokuBoard[9][9];
    char *fileName;
    FILE *sudokuFile;
    int i = 0;
    
    
    if (argc > 1)
    {
        fileName = argv[1];
        sudokuFile = fopen (fileName, "r");
    }
    else
    {
        sudokuFile = stdin;
    }
    
    if (sudokuFile == NULL)
    {
        puts ("Eror reading sudoku file!");
        return 1;
    }
    
    /* If grabbed from a text file */
    for (i = 0; i < 9; i++)
    {
        fscanf (sudokuFile, "%d %d %d %d %d %d %d %d %d", &SodokuBoard[i][0],
                &SodokuBoard[i][1], &SodokuBoard[i][2], &SodokuBoard[i][3],
                &SodokuBoard[i][4], &SodokuBoard[i][5], &SodokuBoard[i][6],
                &SodokuBoard[i][7], &SodokuBoard[i][8]);
    }
    
    /* Print out the original Puzzle, then starts to solve. */
    puts ("Original Puzzle:");
    
    printSudoku (SodokuBoard);
    
    puts ("Solving...");
    puts ("");
    
    /* If successful, then prints the solution */
    if (solveSudoku (SodokuBoard))
    {
        puts ("Sudoku Solved!");
        printSudoku (SodokuBoard);
    }
    else
    {
        puts ("Illegal sudoku (or a broken algorithm [not likely])");
    }
    
    return 0;
}

int
solveSudoku (int SodokuBoard[][9])
{
    return sudokuHelper (SodokuBoard, 0, 0);
}


int
sudokuHelper (int SodokuBoard[][9], int row, int column)
{
    int nextNumber = 1;
    /*
     *Checks to see if puzzle is done.
     */
    if (9 == row)
    {
        return 1;
    }
    
    
    if (SodokuBoard[row][column])
    {
        if (column == 8)
        {
            if (sudokuHelper (SodokuBoard, row + 1, 0))
                return 1;
        }
        else
        {
            if (sudokuHelper (SodokuBoard, row, column + 1))
                return 1;
        }
        return 0;
    }
    
    for (; nextNumber < 10; nextNumber++)
    {
        if (isValid (nextNumber, SodokuBoard, row, column))
        {
            SodokuBoard[row][column] = nextNumber;
            if (column == 8)
            {
                if (sudokuHelper (SodokuBoard, row + 1, 0))
                    return 1;
            }
            else
            {
                if (sudokuHelper (SodokuBoard, row, column + 1))
                    return 1;
            }
            SodokuBoard[row][column] = 0;
        }
    }
    return 0;
}

/*
 * Prints out the Sodoku Board.
 */
void
printSudoku (int SodokuBoard[][9])
{
    int i = 0, j = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (2 == j || 5 == j)
            {
                printf ("%d | ", SodokuBoard[i][j]);
            }
            else if (8 == j)
            {
                printf ("%d\n", SodokuBoard[i][j]);
            }
            else
            {
                printf ("%d ", SodokuBoard[i][j]);
            }
        }
        if (2 == i || 5 == i)
        {
            puts ("------+-------+------");
        }
    }
}

/*
 * Checks to see certain number is in a
 * certain part of puzzle.
 */
int
isValid (int number, int SodokuBoard[][9], int row, int column)
{
    int i = 0;
    int modRow = 3 * (row / 3);
    int modCol = 3 * (column / 3);
    int Row1 = (row + 2) % 3;
    int Row2 = (row + 4) % 3;
    int Col1 = (column + 2) % 3;
    int Col2 = (column + 4) % 3;
    
    /* Check for the value in the given row and column */
    for (i = 0; i < 9; i++)
    {
        if (SodokuBoard[i][column] == number)
            return 0;
        if (SodokuBoard[row][i] == number)
            return 0;
    }
    
    /* Check the remaining four spaces in this sector */
    if (SodokuBoard[Row1 + modRow][Col1 + modCol] == number)
        return 0;
    if (SodokuBoard[Row2 + modRow][Col1 + modCol] == number)
        return 0;
    if (SodokuBoard[Row1 + modRow][Col2 + modCol] == number)
        return 0;
    if (SodokuBoard[Row2 + modRow][Col2 + modCol] == number)
        return 0;
    return 1;
}
