#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
//std::ofstream testing("test.test");
#include <vector>
using std::cout;
typedef std::vector<char> linearBoard;
linearBoard Board(9);

void initBoard(){
    for(int i = 0; i < 9; i++) Board[i]=0;
}
void debugBoard() {
    // Printing the board with X and O symbols
    cout << " " << (Board[0] == 1 ? 'X' : (Board[0] == -1 ? 'O' : ' ')) << " |" 
         << " " << (Board[1] == 1 ? 'X' : (Board[1] == -1 ? 'O' : ' ')) << " |"
         << " " << (Board[2] == 1 ? 'X' : (Board[2] == -1 ? 'O' : ' ')) << "\n";
    
    cout << "-----------\n";
    
    cout << " " << (Board[3] == 1 ? 'X' : (Board[3] == -1 ? 'O' : ' ')) << " |" 
         << " " << (Board[4] == 1 ? 'X' : (Board[4] == -1 ? 'O' : ' ')) << " |"
         << " " << (Board[5] == 1 ? 'X' : (Board[5] == -1 ? 'O' : ' ')) << "\n";
    
    cout << "-----------\n";
    
    cout << " " << (Board[6] == 1 ? 'X' : (Board[6] == -1 ? 'O' : ' ')) << " |" 
         << " " << (Board[7] == 1 ? 'X' : (Board[7] == -1 ? 'O' : ' ')) << " |"
         << " " << (Board[8] == 1 ? 'X' : (Board[8] == -1 ? 'O' : ' ')) << "\n";
}
void debugBoard2() {
    // Printing the board with X and O symbols
    cout << " " << (Board[0] == 1 ? 'O' : (Board[0] == -1 ? 'X' : ' ')) << " |" 
         << " " << (Board[1] == 1 ? 'O' : (Board[1] == -1 ? 'X' : ' ')) << " |"
         << " " << (Board[2] == 1 ? 'O' : (Board[2] == -1 ? 'X' : ' ')) << "\n";
    
    cout << "-----------\n";
    
    cout << " " << (Board[3] == 1 ? 'O' : (Board[3] == -1 ? 'X' : ' ')) << " |" 
         << " " << (Board[4] == 1 ? 'O' : (Board[4] == -1 ? 'X' : ' ')) << " |"
         << " " << (Board[5] == 1 ? 'O' : (Board[5] == -1 ? 'X' : ' ')) << "\n";
    
    cout << "-----------\n";
    
    cout << " " << (Board[6] == 1 ? 'O' : (Board[6] == -1 ? 'X' : ' ')) << " |" 
         << " " << (Board[7] == 1 ? 'O' : (Board[7] == -1 ? 'X' : ' ')) << " |"
         << " " << (Board[8] == 1 ? 'O' : (Board[8] == -1 ? 'X' : ' ')) << "\n";
}

bool isFull(){
    for(int i = 0; i < 9; i++) if(Board[i]==0) return false;
    return true;
}
bool isCorrect(){
    int cx=0,c0=0;
    for(int i = 0; i < 9; i++) if(Board[i]==1)cx++;
    for(int i = 0; i < 9; i++) if(Board[i]==-1)c0++;
    if(cx==c0+1)
        return true;
    else return false;
}

short whoWon(){
    if(
        (Board[0]==1 && Board[1]==1 && Board[2]==1) ||
        (Board[3]==1 && Board[4]==1 && Board[5]==1) ||
        (Board[6]==1 && Board[7]==1 && Board[8]==1) ||
        (Board[0]==1 && Board[3]==1 && Board[6]==1) ||
        (Board[1]==1 && Board[4]==1 && Board[7]==1) ||
        (Board[2]==1 && Board[5]==1 && Board[8]==1) ||
        (Board[0]==1 && Board[4]==1 && Board[8]==1) ||
        (Board[2]==1 && Board[4]==1 && Board[6]==1)
    ) return 1;
    else
    if(
        (Board[0]==-1 && Board[1]==-1 && Board[2]==-1) ||
        (Board[3]==-1 && Board[4]==-1 && Board[5]==-1) ||
        (Board[6]==-1 && Board[7]==-1 && Board[8]==-1) ||
        (Board[0]==-1 && Board[3]==-1 && Board[6]==-1) ||
        (Board[1]==-1 && Board[4]==-1 && Board[7]==-1) ||
        (Board[2]==-1 && Board[5]==-1 && Board[8]==-1) ||
        (Board[0]==-1 && Board[4]==-1 && Board[8]==-1) ||
        (Board[2]==-1 && Board[4]==-1 && Board[6]==-1)
    ) return -1;
    else return 0;
}
short x = -1;
int cnt = 0;
long long v[9];
int moveScore = 0;

void back(short index){
    for(int i = 0; i < 9; i++)
    {
        
        if((isFull() && isCorrect) || whoWon()!=0)
        {//cnt++; 
        //testBoard();
        whoWon()==1?moveScore++:(whoWon==0)?moveScore:moveScore-=1;
        return;
        }
        if(Board[i]==0)
        {
            if(Board[index]==1) x = -1;
            else x = 1;
            Board[i]=x;
        back(i);
        Board[i] = 0;

        }
    }

}
void CopyBoard(linearBoard board){
    for(int i = 0; i < 9; i++)
    {
        Board[i]=board[i];
    }
}

short GetSolutions(int last, linearBoard board, bool unk=false){
    int x = -1;
    if(Board[last]==-1 || Board[last]==0) x= 1;
    if(unk) x=-1;
    bool analysed_first = false;
    long long maxScore;
 //   cout << x;
    short iToReturn=-1;
    for(int i = 0; i < 9; i++)
    {
        if(Board[i]==0)
        {
            
            Board[i] = x;
            back(i);
           // cout << i << " ";
           
           board[i] = x;
           CopyBoard(board);
           
           if((whoWon() == 1 && x==1) || (whoWon()==-1 && x==-1)) return i;
           if((whoWon() == 1 && x!=1) || (whoWon()==-1 && x!=-1)) continue;
            
           if(whoWon())
            if(!analysed_first)
            {
                analysed_first = true;
                maxScore = moveScore;
                iToReturn = i;
            }
            if((moveScore > maxScore && x==1) || (moveScore < maxScore && x==-1)) maxScore = moveScore, iToReturn=i;
          //E  cout << moveScore << " ";
            v[i] = moveScore;
            moveScore = 0;
            board[i] = 0;
           CopyBoard(board);
            
        }
    }
    return iToReturn;
}




