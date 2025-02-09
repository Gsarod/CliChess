#include <stdio.h>
#include <iostream>

using namespace std;

//CHESS BOARD
//Layout
char chessboard[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
    };



//PIECES

//Initalises a piece with basic parameters : Symbol and position
class Piece{

public:
    Piece(char symbol, int ypos, int xpos, int team)
    :
    symbol(symbol),
    ypos(ypos),
    xpos(xpos),
    team(team)
    {}

    char symbol;
    int ypos, xpos, team;
    bool alive = true;

};

//Rook
Piece Rook('R', 7, 0, 1);



//BOARD UPDATING
void drawchessboard(){
    
    //
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            chessboard[y][x] = ((y + x) % 2 == 0) ? 'W' : 'B';
        }
    }
    
    //Pieces go here 
    chessboard[Rook.ypos][Rook.xpos] = Rook.symbol;    
    
    //summons the board
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){            
            cout<<chessboard[y][x]<<" "; 
        };
        cout<<endl; 
    
    }
}

void movepiece(){
    
    char direction; 
    int steps; 

    cout<<"Direction and how many steps"<<endl;
    cin>>direction>>steps; 
    
    //int oldY = Rook.ypos, oldX = Rook.xpos;

    
        if (direction == 'U' && Rook.ypos - steps >= 0) {
            Rook.ypos -= steps;
        } else if (direction == 'D' && Rook.ypos + steps < 8) {
            Rook.ypos += steps;
        } else if (direction == 'L' && Rook.xpos - steps >= 0) {
            Rook.xpos -= steps;
        } else if (direction == 'R' && Rook.xpos + steps < 8) {
            Rook.xpos += steps;
        } else {
            cout << "Invalid move!" << endl;
        }
    
}