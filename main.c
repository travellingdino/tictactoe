#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gameOver(char board[][3], int emptyCount){
    if (emptyCount != 0){
        return 0;
    }
    
    return 1;
}

int cellOccupied(char board[][3], int row, int column){
    if (board[row][column] != '.')
        return 1;

    return 0;
}

int invalidInput(char input){
    return input != '1' && input != '2' && input != '3';
}

void resetBoard(char board[][3], int* emptyCount){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = '.';
        }
    }

    *emptyCount = 9;
}

void printBoard(char board[][3]){
    printf("-------------\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("| %c ", board[i][j]);
        }

        printf("|\n");
        printf("-------------\n");
    }
}

void game(char board[][3], int* emptyCount, char clear){
    char row, column, userChar, oppChar;
    int invalid;
    int oppRow, oppColumn;

    srand(time(NULL));

    int random_num = rand() % 2;

    if(random_num){
        userChar = 'X';
        oppChar = 'O';
    }
    else{
        userChar = 'O';
        oppChar = 'X';
        board[rand() % 3][rand() % 3] = oppChar;
        *emptyCount -= 1;
    }

    while(!gameOver(board, *emptyCount)){
        printf("-------------\n");
        printf("  YOU ARE %c\n", userChar);
        printBoard(board);
        do
        {
            printf("Enter the row you want to place (1, 2, or 3): ");
            scanf("%c", &row);

            while ((clear = getchar()) != '\n' && clear != EOF); 
            invalid = invalidInput(row);

            if (invalid)
                printf("Invalid input. Please try again.\n");
        } 
        while (invalid);

        do
        {
            printf("Enter the column you want to place (1, 2, or 3): ");
            scanf("%c", &column);

            while ((clear = getchar()) != '\n' && clear != EOF); 
            invalid = invalidInput(column);

            if (invalid)
                printf("Invalid input. Please try again.\n");
        } 
        while (invalid);

        if (cellOccupied(board, row - 49, column - 49)){
            printf("--------------------------------\n");
            printf("Cell occupied. Please try again.\n");
        }
        else{
            board[row - 49][column - 49] = userChar;
            *emptyCount -= 1;

            if (*emptyCount > 0){
                do{
                    oppRow = rand() % 3;
                    oppColumn = rand() % 3;
                    invalid = cellOccupied(board, oppRow, oppColumn);

                    if (!invalid){
                        board[oppRow][oppColumn] = oppChar;
                        *emptyCount -= 1;
                    }
                }
                while(invalid);
            }
        }
    }

    
}

int main(){
    char clear, board[3][3], replay;
    int emptyCount, isRunning = 1;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("-----------------------\n");
    printf("Press enter to play: ");
    scanf("%c", &clear);
    printf("-----------------------\n");
    while ((clear = getchar()) != '\n' && clear != EOF); 

    while(isRunning){
        resetBoard(board, &emptyCount);
        game(board, &emptyCount, clear);

        
    }

    return 0;
}