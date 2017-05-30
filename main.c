#include <stdio.h>

void presentProgram();
void loadSudokuFromFileToArray(int sudokuArray[9][9], char path[255]);
void presentEnteredSudoku(int sudokuArray[9][9]);
void createNumberedArray(int array1[]);

// Utilities
void getBlockFromPuzzleByIndex(int sudokuArray[9][9], int block[9], int blockIndex);
//void getRowFromPuzzleByIndex(int sudokuArray[9][9])
int allNumbersInArray(int array[]);
int digitIsInArray(int digits[9], int digit);

// Checking sudoku solution
int legitSudokuSolution(int sudokuarray[9][9]);

// Solving sudoku
void solveSudoku(int sudokuArray[9][9])


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

    solveSudoku(sudokuArray);

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
    //printf("\t");

    return 1;
}

void getBlockFromPuzzleByIndex(int sudokuArray[9][9], int block[9], int blockIndex) {
    int r, c, n, x;

    // Set row and column starting values depending on which
    // block to get
    switch (blockIndex) {
        case 0 :
            r = 0;
            c = 0;
            break;
        case 1 :
            r = 0;
            c = 3;
            break;
        case 2 :
            r = 0;
            c = 6;
            break;
        case 3 :
            r = 3;
            c = 0;
            break;
        case 4 :
            r = 3;
            c = 3;
            break;
        case 5 :
            r = 3;
            c = 6;
            break;
        case 6 :
            r = 6;
            c = 0;
            break;
        case 7 :
            r = 6;
            c = 3;
            break;
        case 8 :
            r = 6;
            c = 6;
            break;
    }



    // Get the values from the block that spans over 3 rows
    // And add that to the block array
    for (n=0; n<3; n++) {
        // Iterate over row columns
        for (x=0; x<3; x++) {
            block[n*3+x] = sudokuArray[r+n][c+x];
        }
    }
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
    //printf("all rows ok!\n");

    // Check that all columns include correct numbers
    for (c=0; c<9; c++) {
        for (r=0; r<9; r++) {
            column_array[r] = sudokuArray[r][c];
        }
        if (allNumbersInArray(column_array) != 1) {
            printf("Faulty column nr: %i \n", c+1);
            return 0;
        }
    }
    //printf("all columns ok!\n");


    for (r=0; r<9; r++) {
        getBlockFromPuzzleByIndex(sudokuArray, blocks[r], r);
    }

    //printf("blocks: \n");
    for (c=0; c<9; c++) {
        for (r=0; r<9; r++) {
            printf("%i", blocks[c][r]);
        }
        if (allNumbersInArray(blocks[c]) != 1) {
            printf("Faulty block index: %i \n", c);
            return 0;
        }
        //printf("\t");
    }
    //printf("All blocks ok!\n");

    return 1;
    // Kolla att alla rader innehåller siffrorna 1-9
    // Kolla att alla kolumner innehåller 1-9
    // Kolla att alla boxarna
}

int digitIsInArray(int digits[9], int digit) {
    int c;
    for (c=0; c<9; c++) {
        if (digits[c] == digit) {
            return 1;
        }
    }
    return 0;
}

// Skulle kanske kunna återanvända digit in array och hämta varje rad block och kolumn
void getDigitFrequencyCount(int sudokuArray[9][9], digitFrequencyCount[9]) {
    int r, c;

    for ()
}

void solveSudoku(int sudokuArray[9][9]) {
    // Kanske implementera en stack struktur för att kunna lägga på vad som
    // skall göras härnäst

    // Ha någon typ av timeout
    // Scannar av arrayen och ser vilka siffror som det finns flest av
    // och försöker lösa någon av dom
    // Lösning utan något optimerings tänk och lösning med optimeringstänk
    // Dvs strategiska beslut som avgör t.ex vilken siffra man vill lösa efter först

    //

    int digitFrequencyCount[9];



}


// C klasser, pointers
// Borde funktioner returnera något när det gäller arrayer
