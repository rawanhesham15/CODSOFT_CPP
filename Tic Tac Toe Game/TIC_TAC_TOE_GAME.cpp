#include <bits/stdc++.h>
using namespace std;

char board[3][3];
int movements = 0;

void printBoard(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void updateBoard(char row, char column, int player){
    if(board[row-1][column-1] == '-'){
        if(player == 1){
            board[row-1][column-1] = 'X';
            movements++;
        }else {
            board[row-1][column-1] = 'O';
            movements++;
        }
    }
    printBoard();
}

bool checkPosition(int row, int column){
    if(row > 3 || row < 1 || column < 1 || column > 3 || board[row-1][column-1] != '-')
        return false;
    else
        return true;
}

bool checkWinner(){
    for (int i=0; i<=2; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!='-'){
            return true;
        }
    }

    for(int i=0; i<=2; i++){
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!='-'){
            return true;
        }
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='-'){
        return true;
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!='-'){
        return true;
    }

    if(board[0][0]==board[0][1] && board[0][1]==board[0][2]&& board[0][2]==board[0][1]&& board[1][0]==board [1][1]&& board[1][1]==board [1][2]&& board[1][2]==board[2][0]&&board[2][0]==board [2][1]&& board[2][1]==board [2][2] && board [0][0]!='-'){
        return false;
    }
    return false;
}

void playerOne(){
    int row, column;
    cout << " -> Player 1 turn (X)\n";
    do{
        cout << "Enter the position you want (row and column like this 1 1 (the first column in the first row)): ";
        cin >> row >> column;
    }while(!checkPosition(row, column));

    updateBoard(row, column, 1);
    if(checkWinner()){
        cout << "Player 1 win!\n";
        movements=10;
    }
}

void playerTwo(){
    int row, column;
    cout << " -> Player 2 turn (O)\n";
    do{
        cout << "Enter the position you want (row and column like this 1 1 (the first column in the first row)): ";
        cin >> row >> column;
    }while(!checkPosition(row, column));

    updateBoard(row, column, 2);
    if(checkWinner()){
        cout << "Player 2 win!\n";
        movements=10;
    }
}

void manager(){
    //initial state of the board.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }

    cout << "____________Welcome to Tic Tac Toe Game____________" << endl;
    cout << "Player 1 is X and Player 2 is O" << endl;
    printBoard();
    while(movements < 9){
        playerOne();
        if(movements < 9){
            playerTwo();
        }
    }
    if(movements != 10 && !checkWinner()){
        cout << "Draw!\n";
    }

    char YN;
    cout << "Want to play again? (Y/N): ";
    cin >> YN;
    if(YN == 'Y'){
        movements = 0;
        manager();
    }
}

int main() {
    manager();
}