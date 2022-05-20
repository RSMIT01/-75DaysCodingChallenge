#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> &board,int i,int j,int n,vector<vector<int>> &dir,int move)
{
   if(move==n*n)
   {
       return true;
   }
  
   for(int k=0;k<8;k++)
   {
       int x=dir[k][0]+i;
       int y=dir[k][1]+j;
       if(x>=0 && y>=0 && x<n && y<n && board[x][y]==-1)
       {
           board[x][y]=move;
           if(solve(board,x,y,n,dir,move+1))
           {
               return true;
           }
           else{

            board[x][y]=-1;
           }
       }
   }
return false;

}
int main()
{
vector<vector<int>>dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n;
cin>>n;
vector<vector<int>>board(n,vector<int>(n,-1));
board[0][0]=0;
solve(board,0,0,n,dir,1);


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}