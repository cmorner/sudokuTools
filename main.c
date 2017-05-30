#include <stdio.h>

void presentProgram();
void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]);
void presentEnteredSudoku(int sudokuArray[9][9]);
void createNumberedArray(int array1[]);
int legitSudokuSolution(int sudokuarray[9][9]);
int allNumbersInArray(int array[]);


int main()
{
    int sudokuArray[9][9], c, r;

    presentProgram();

    loadSudokuFromFileToArray(sudokuArray, "./puzzles/puzzle_1.txt");

    //printf("Please enter the solved Sudoku to be controlled.\n\n");

    /** Iterate over gamefield rows
    for (r = 0; r<9; r++) {
        // Iterate over columns
        printf("Enter row nr: %d of the sudoku gamefield\n", r+1);
        for (c=0; c<9; c++) {
            scanf("%d", &sudokuArray[r][c]);
        }
    }
    **/

    presentEnteredSudoku(sudokuArray);

    legitSudokuSolution(sudokuArray);

    return 0;
}

void presentProgram(void) {
    printf("Welcome to Sudoku solver 2017!\n");
    printf("##############################\n\n");
}

void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]) {
    int r, c;
    FILE *fp;
    int buff;

    fp = fopen(path, "r");

    for (r = 0; r<9; r++) {
        for (c=0; c<9; c++) {
            fscanf(fp, "%1d", &buff);
            sudokuArray[r][c] = buff;
        }
    }

    fclose(fp);
}

void presentEnteredSudoku(int sudokuArray[9][9]) {
    int r, c;
    printf("The gamefield you entered was: \n\n");
    for (r=0 ; r < 9 ; r++) {
        for (c=0 ; c < 9 ; c++) {
            // Insert tab if three numbers has been entered
            if ( (((c) % 3) == 0) && c != 0) {
                printf("\t");
            }
            printf("%i ", sudokuArray[r][c]);
        }
        printf("\n");

        // Insert extra newline after three rows for nice formatting
        if (((r+1) % 3) == 0 )
            printf("\n");

    }
}

void createNumberedArray(int array[9]) {
    int c;
    // Add numbers 1-9
    for (c=0; c<9; c++) {
        array[c] = c+1;
    }
}

// Takes an array of 9 numbers and checks
// Too see that the array only holds 1-9
// each number one time
int allNumbersInArray(int array[]) {
    int numbers_checklist[9], c, number;

    createNumberedArray(numbers_checklist);

    for (c = 0; c<9; c++) {
        number = array[c];

        //printf(" %i", number);
        if (numbers_checklist[number-1] == number) {
            // check off the number
            numbers_checklist[number-1] = 0;
        } else {
            return 0;
        }
    }


    return 1;
}

int legitSudokuSolution(int sudokuArray[9][9]) {
    // One array to remove each checked number and one
    // to restore the array
    int r, c, column_array[9], blocks[9][9], x, y;

    //Check that all rows contain 1-9
    for (r = 0; r<9; r++) {
        if (allNumbersInArray(sudokuArray[r]) != 1) {
            printf("Faulty row nr: %i \n", r+1);
            return 0;
        }
    }
    printf("all rows ok!\n");

    // Check that all columns include correct numbers
    for (c=0; c<9; c++) {
        for (r=0; r<9; r++) {
            column_array[r] = sudokuArray[r][c];
        }
        if (allNumbersInArray(column_array) != 1) {
            printf("Faulty column nr: %i \n", c+1);
        }
    }
    printf("all columns ok!\n");

    // Check that each block holds the correct numbers
    for (r=0; r<9; r++) {
        // Add one number to each block
        if (r < 3) {
            y = 0;
        } else if (2 < r < 6) {
            y = 3;
        } else if (5 < r < 9) {
            y = 6;
        }
        for (c=0; c<9; c++) {
            if (c < 3) {
                x = 0;
            } else if (2 < c < 6) {
                x = 1;
            } else if (5 < c < 9) {
                x = 2;
            }


            blocks[y+x][(c%3)+(r%3)*3] = sudokuArray[r][c];
        }
    }

    getchar();
    //printf("block 1: %i", blocks[][]);
    for (c=0; c<9; c++) {
        printf(" %i", blocks[3][c]);
        //if (allNumbersInArray(blocks) != 1) {
        //    printf("Faulty block nr: %i \n", c+1);
        //}
    }

    return 1;
    // Kolla att alla rader innehåller siffrorna 1-9
    // Kolla att alla kolumner innehåller 1-9
    // Kolla att alla boxarna
}


