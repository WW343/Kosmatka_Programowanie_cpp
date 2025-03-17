#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>

using namespace std;



int Board_Size_define(int argc, char *argv[]){
    int Board_Size;
    if(argc == 2){
        if(atoi(argv[1]) < 3){
            cout<<"Board size must be greater than 3"<<endl;
            return 3;
        }
        Board_Size = atoi(argv[1]);
    }
    else{
        Board_Size = 3;
    }
    return Board_Size;
}
void clearBoeard(char **board,int Board_Size){
    for (int i = 0; i < Board_Size; i++){  
        for(int j = 0;j<Board_Size;j++)
        {
             board[i][j] = ' ';
            
        };
        };
}

void showBoard(char **board,int Board_Size){
    for (int i = 0; i < Board_Size; i++) {
        
        for(int j = 0;j<Board_Size;j++)
        {
            cout<<"|"<<board[i][j];  
        };
        cout<<"|"<<endl;
        };
}

bool isFinished(char **board,int Board_Size,char *winner){
    
    int sum_one = 0;
    for(int counter_vertically=0;counter_vertically<Board_Size;counter_vertically++){
        for (int i = 0; i <Board_Size; i++) {

            if (board[i][counter_vertically] == 'X'){
                sum_one++;
            }
            if (board[i][counter_vertically] == 'O'){
                sum_one--;
            }
            if(sum_one == Board_Size*-1){
                *winner = 'O';
                return true;
            }
            if(sum_one ==Board_Size){
                *winner = 'X';
                return true;
            }  
        }
        sum_one = 0;
    }

    int sum_two = 0;
    for(int counter_horizontally = 0;counter_horizontally<Board_Size;counter_horizontally++){
        for (int i = 0; i <Board_Size; i++) {
            
            if (board[counter_horizontally][i] == 'X'){
                sum_two++;
            }
            if (board[counter_horizontally][i] == 'O'){
                sum_two--;
            }
            if(sum_two == Board_Size*-1){
                *winner = 'O';
                return true;
            }
            if(sum_two ==Board_Size){
                *winner = 'X';
                return true;
            }
        }
        sum_two = 0;
    }

    int sum_three = 0;

    for (int i = 0; i <Board_Size; i++){
        if(board[i][i] =='X'){
            sum_three++;
        }
        if(board[i][i] =='O'){
            sum_three--;
        }
        if(sum_three == Board_Size*-1){
            *winner = 'O';
            return true;
        }
        if(sum_three ==Board_Size){
            *winner = 'X';
            return true;
        }
    }

    int sum_four = 0;
    int counter = 0;
    for (int i = Board_Size-1;i>=0;i--){
        if(board[i][counter] == 'X'){
            sum_four++;
        }
        if(board[i][counter] == 'O'){
            sum_four--;
        }
        if(sum_four == Board_Size*-1){
            *winner = 'O';
            return true;
        }
        if(sum_four ==Board_Size){
            *winner = 'X';
            return true;
        }
        counter++;
        
    }
    sum_four = 0;
    counter = 0;

    return false;
}

bool setPoint(char **board, unsigned int x, unsigned int y, char player){
    if(board[x][y] == ' '){
        board[x][y] = player;
        return true;
    }
        return false;
    
}
bool setPoint_computer(char **board, unsigned int x, unsigned int y, char player){
    if(board[x][y] == ' ' || board[x][y] !='O'){
        board[x][y] = player;
        return true;
    }
        return false;
    
}
bool check_if_digit(unsigned int number, int size){
    if(number < size){
        return true;
    }
    return false;
}

int getRandomNumber(int n) {
    n--;
    if (n < 0) {
        std::cerr << "Error: n must be non-negative." << std::endl;
        return -1; // Return an error code
    }

    return rand() % (n + 1);
}

int main(int argc, char *argv[]){
    srand(time(0));
    char **board;
    char winner = ' ';
    int turn = 0;
    char player = 'O';
    int size = Board_Size_define(argc,argv);
    board = new char *[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
        }
    
    clearBoeard(board,size);
    showBoard(board,size);
    
    while(!isFinished(board,size,&winner)){
        unsigned int row=100,col=100;
        if(player == 'O'){
            while (!check_if_digit(row,size)){
                cout<<"Podaj numer wiersza";
                scanf("%u", &row);
            }
            while (!check_if_digit(col,size)){
                cout<<"Podaj numer kolumny";
                scanf("%u", &col);
            }

            if(setPoint(board,row,col,player)){
                player = 'X';
            };
        }
        else if(player == 'X'){
            if(setPoint(board,getRandomNumber(size),getRandomNumber(size),player)){
                player = 'O';
            };

        }
        showBoard(board,size);
        cout<<turn<<endl;
        
        if(turn == size*size){
            cout<<"Remis"<<endl;
            break;
        }
    if (isFinished(board,size,&winner))
    {
        cout<<winner<<" won."<<endl;
    }
    
    
    
}
}


// 2.gracz-komputer
// komendy pomocnicze:
// rand()
// man 3 rand
// #include <cstdlib>
// rand()%(boardSize*boarSize)

// napraw isfinished bo źle liczy