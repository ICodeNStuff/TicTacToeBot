#include "funct.h"

int main(int argc, const char** argv){
    puts("Enter the first move! (1,2,3): ");
    initBoard();
    //debugBoard();
    
    linearBoard myboard={0,0,0,0,0,0,0,0,0};
    CopyBoard(myboard);
   // debugBoard();
    int x=1, pos;
    //cin >> pos;
    bool computerplays = true;
    if(argc==2)
    {
    if(argv[1]=="1") computerplays = false;
    if(argv[1]=="2") computerplays = true;
    }
    if(!computerplays)
    for(int i = 0; i < 5; i++){
        debugBoard();
        cout << "Enter the next position: ";
        std::cin >> pos;
        myboard[pos-1]=x;
        CopyBoard(myboard);
        
        int sol = GetSolutions(pos-1, myboard);
       // cout << sol << " ";
        myboard[sol] = -x;
        CopyBoard(myboard);
        
        if(whoWon()!=0)
        {
            debugBoard();
            if(whoWon()==1)
            {
                cout << "Player won! Good job!";
                return 0;
            }else{
                cout << "The computer won!";
                return 0;
            }
        }
        //x*=-1;
    }
    else{
        CopyBoard(myboard);
        int sol = GetSolutions(0, myboard,true);
        x=1;
        myboard[sol]=-x;
        CopyBoard(myboard);
        debugBoard2();
         for(int i = 0; i < 4; i++){
        cout << "Enter the next position: ";
        std::cin >> pos;
        myboard[pos-1]=x;
        CopyBoard(myboard);
        
        int sol = GetSolutions(pos-1, myboard);
       // cout << sol << " ";
        myboard[sol] = -x;
        CopyBoard(myboard);
        debugBoard2();
        if(whoWon()!=0)
        {
            if(whoWon()==1)
            {
                 cout << "Player won! Good job!";
               
                return 0;
            }else{
                
                cout << "The computer won!";
                return 0;
            }
        }
        //x*=-1;
    }
        // for(int i = 0; i < 4; i++)
        // {
            
        //     std::cin >> pos;
        //     myboard[pos-1]=x;
        //     CopyBoard(myboard);
        //     sol = GetSolutions(pos-1, myboard);
        
        // myboard[sol]=-x;
        // CopyBoard(myboard);
        // debugBoard();
        //     if(whoWon()!=0)
        //  {
        //     if(whoWon()==1)
        //     {
        //         cout << "The computer won!";
              
        //         return 0;
        //     }else{
        //           cout << "Player won! Good job!";
        //         return 0;
        //     }
        // }
        // }
    }

    debugBoard();
    cout << "Draw!";
   // cout << GetSolutions(8, myboard);;
    return 0;
}