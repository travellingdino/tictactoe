#include <stdio.h>

int checkIfGameOver(int board[]){

}

int checkIfCellOccupied(char board[][3], int row, int column){
    if (board[row][column] == '.')
        return 0;

    return 1;
}

void resetBoard(char board[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = '.';
        }
    }
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

int main(){
    char clear;
    int isRunning = 1;
    char board[3][3] =  {{'.', '.', '.'}, 
                        {'.', '.', '.'},
                        {'.', '.', '.'}};

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("-----------------------\n");
    printf("Press enter to play: ");
    scanf("%c", &clear);
    printf("-----------------------\n");

    // Clear input buffer
    while ((clear = getchar()) != '\n' && clear != EOF); 

    printBoard(board);

    printf("Enter the row you want to place: ");
    scanf("%c", &clear);

    while ((clear = getchar()) != '\n' && clear != EOF); 

    printf("Enter the column you want to place: ");
    scanf("%c", &clear);

    while ((clear = getchar()) != '\n' && clear != EOF); 


    return 0;
}