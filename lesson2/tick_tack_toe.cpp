#include <iostream>
#include <stdio.h>
using namespace std;

void clearBoeard(char board[3][3]){
    for (int i = 0; i < 3; i++) {
        for(int j = 0;j<3;j++)
        {
             board[i][j] = ' ';
            
        };
        };
}

void showBoard(char board[3][3]){
    for (int i = 0; i < 3; i++) {
        
        for(int j = 0;j<3;j++)
        {
            cout<<"|"<<board[i][j];  
        };
        cout<<"|"<<endl;
        };
}
bool isFinished(char board[3][3],char *winner){
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0;j<3;j++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] !=' '){
                cout<<board[i][0]<<" won"<<endl;
                *winner = board[i][0];
                return true;
                break;
            }
            else if(board[0][j] == board[1][j]&& board[1][j] == board[2][j] &&board[1][j]!= ' '){
                cout<<board[0][j]<<" won"<<endl;
                *winner = board[0][j];
                return true;
                break;
            }
            else if(board[0][0] == board[1][1]&& board[1][1] == board[2][2] &&board[1][1] !=' '){
                cout<<board[0][0]<<" won"<<endl;
                *winner = board[0][0];
                return true;
                break;
            }
            else if(board[0][2] == board[1][1]&& board[1][1] == board[0][2] &&board[1][1] !=' '){
                cout<<board[0][0]<<" won"<<endl;
                *winner = board[0][0];
                return true;
                break;
        }
        cout<<endl;
        }
    }
    return false;
}

bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player){
    if(board[x][y] == ' '){
        board[x][y] = player;
        return true;
    }
    
        return false;
    
}
bool check_if_digit(unsigned int number){
    if(number <3){
        return true;
    }
    return false;
}
int main(){
    char board[3][3];
    char winner = ' ';
    int turn = 0;
    char player = 'O';
    clearBoeard(board);
    showBoard(board);
    
    while(!isFinished(board,&winner)){
        unsigned int row=100,col=100;
        while (!check_if_digit(row)){
            cout<<"Podaj numer wiersza";
            scanf("%u", &row);
        }
        while (!check_if_digit(col)){
            cout<<"Podaj numer kolumny";
            scanf("%u", &col);
        }

        if(setPoint(board,row,col,player)){
            if(player == 'X'){
                player = 'O';
            }
            else{
                player = 'X';
            }
        };
        showBoard(board);

        turn++;
    
    
}
}

// 1.Zmiana rozmiaru tabeli
// 2.gracz-komputer
// komendy pomocnicze:
// rand()
// man 3 rand
// #include <cstdlib>
// rand()%(boardSize*boarSize)