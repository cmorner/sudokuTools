#include <stdio.h>

void presentProgram();
void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]);
void presentEnteredSudoku(int sudokuArray[9][9]);
void createNumberedArray(int array1[]);
void legitSudokuSolution(int sudokuarray[9][9]);
int allNumbersInArray(int array[9])




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

void createNumberedArray(int array[]) {
    int c;
    // Add numbers 1-9
    for (c=0; c<9; c++) {
        array[c] = c+1;
    }
}

int allNumbersInArray(int array[9]) {

}

void legitSudokuSolution(int sudokuArray[9][9]) {
    // One array to remove each checked number and one
    // to restore the array
    int numbers_checklist[9];
    int c, r, number, number2;

    createNumberedArray(numbers_checklist);

    //Check that all rows contain 1-9
    for (r = 0; r<9; r++) {
        for (c = 0; c<9; c++) {
            number = sudokuArray[r][c];

            if (numbers_checklist[number-1] == number) {
                // check off the number
                numbers_checklist[number-1] = 0;
            } else {
                printf("Faulty row. Row:%d, Col:%d\n", r+1, c+1);
                return 0;
            }
        }
        createNumberedArray(numbers_checklist);
    }
    printf("all rows ok!\n");


    return 1;
    // Kolla att alla rader innehåller siffrorna 1-9
    // Kolla att alla kolumner innehåller 1-9
    // Kolla att alla boxarna
}


