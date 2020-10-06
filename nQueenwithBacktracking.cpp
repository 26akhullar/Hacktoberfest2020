#include<bits/stdc++.h>
using namespace std;

int count = 0;

//check if the given position is attacking or non-attacking
bool checkposition(int board[][10],int n,int x,int y)
{
    for(int i=0;i<=x;i++){
        if(board[i][y]==1){return false;}
    }

    int posx=x;
    int posy=y;
    while(posx>=0 && posy>=0){
        if(board[posx][posy]==1){return false;}
        posx--;posy--;
    }
    
    int xpos=x;
    int ypos=y;
    while(xpos>=0&&ypos<n){
        if(board[xpos][ypos]==1){return false;}
        xpos--;ypos++;
    }    
    return true;
}

bool solveNqueen(int board[][10],int n,int x)
{
    //base condition
    if(x==n)
    {
    	::count++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j]==1){cout<<"1 ";}
                else{cout<<"_ ";}
            }cout<<endl;
        }cout<<endl<<endl;
        return false;
    }
    //recursive case
    for (int j = 0; j < n; j++)
    {
       if(checkposition(board,n,x,j)){
            board[x][j]=1;
            if(solveNqueen(board,n,x+1))
				{return true;}
            board[x][j]=0;
        };
    }
    return false;
}

int main()
{
	cout<<"Enter the number of rows or columns"<<endl;
    int n;
    cin>>n;
    cout<<endl;
    
    int chessboard[10][10]={0};
    solveNqueen(chessboard,n,0);
    cout<<endl<<"Total number of count is "<<::count;
    return 0;

}
