#include <stdio.h>

void presentProgram();
void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]);
void presentEnteredSudoku(int sudokuArray[9][9]);
void checkSudokuForMistakes(int sudokuarray[9][9]);

int main()
{
    presentProgram();

    int sudokuArray[9][9], c, r;

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



    return 0;
}

void presentProgram(void) {
    printf("Welcome to Sudoku solver 2017!\n");
    printf("##############################\n\n");
}

void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]) {
    int r, c;
    FILE *fp;
    char buff[255];

    fp = fopen(path, "r");

    for (r = 0; r<9; r++) {
        fscanf(fp, "%s", buff);
        for (c=0; c<9; c++) {
            sudokuArray[r][c] = buff[c];
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
            printf("%c ", sudokuArray[r][c]);
        }
        printf("\n");

        // Insert extra newline after three rows for nice formatting
        if (((r+1) % 3) == 0 )
            printf("\n");

    }
}

void checkSudokuForMistakes(int sudokuArray[9][9]) {
    unsigned char numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c, r;

    // Check that all rows contain 1-9
    for (r = 0; r<9; r++) {

    }
    // Kolla att alla rader innehåller siffrorna 1-9
    // Kolla att alla kolumner innehåller 1-9
    // Kolla att alla boxarna
}


