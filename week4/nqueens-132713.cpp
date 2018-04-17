#include <iostream>
using namespace std;
struct box {
    int queenExist;
    box(){
        queenExist=0;
    }
};

bool canPutQ(int row, int column, box** board, int n){
    int cWest=column - 1;
    int rSouth=row + 1;
    int rNorth=row - 1;
    while ((cWest >= 0)||(rSouth <n)||(rNorth >= 0)){
        bool attackNW=(rNorth >= 0)&&(cWest >= 0)&&board[rNorth][cWest].queenExist;
        bool attackSW=(rSouth <n)&&(cWest >= 0)&&board[rSouth][cWest].queenExist;
        bool attackW=(cWest >= 0)&&board[row][cWest].queenExist;
        if (attackNW || attackSW || attackW){
            return false;
        } else {
            cWest--;
            rNorth--;
            rSouth++;
        }
    }
    return true;
}

bool BackTrack(box** board, int n){
    bool inBacktrack=false;
    int column=0;
    while (column <n){
        bool putQ=false;
        for (int row=0; row <n; row++){
            if (canPutQ(row, column, board, n)){
                if (inBacktrack){
                    if (board[row][column].queenExist){
                        board[row][column].queenExist=false;
                        inBacktrack=false;
                        continue;
                    }
                } else {
                    board[row][column].queenExist=true;
                    putQ=true;
                    break;
                }
            }
        }

        if (!putQ && !board[n-1][column].queenExist){
            column--;
            if (column < 0){
                return false;
            }
        inBacktrack=true;
        } else {
            column++;
        }
    }
    return true;
}
box** mkboard(box** board,int n){
    for (int i=0;i<n;i++){
        board[i]=new box[n];
    }
    return board;
}
box** rmboard(box** board,int n){
    for (int i=0;i<n;i++){
            delete[] board[i];
    }
    delete[] board;
    return board;
}
void printBoard(box** board, int n){
    for (int row=0; row <n; row++){
        for (int column=0; column <n; column++){
            if (board[row][column].queenExist){
                cout<<'q';
            } else {
                cout<<'.';
            }
        }
        cout<<endl;
    }
}
int main(){
    int n=0;
    cin >> n;
    box** board=new struct box*[n];
    board=mkboard(board,n);
    bool canDo=BackTrack(board, n);
    printBoard(board, n);
    board=rmboard(board,n);
}
