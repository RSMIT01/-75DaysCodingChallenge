#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<string> &board,int n,int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col; i<n && j>=0; i++,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
bool nqueen(vector<vector<string>> &ans,vector<string> &board,int n,int col)
{
    if(col==n)
    {
        return true;
    }
    for(int row=0;row<n;row++)
    {
        if(issafe(board,n,row,col))
        {
            board[row][col]='Q';
            if(nqueen(ans,board,n,col+1))
            {
                 return true;
            }
            board[row][col]='-';
        }
    }
    return false;
}
int main()
{
int n;
cin>>n;
vector<vector<string>>ans;
vector<string>board(n);
string s(n,'-');
for (int i = 0; i < n; i++)
{
    board[i]=s;
}
if(nqueen(ans,board,n,0))
{
   for(int i=0;i<n;i++)
   {
       for(auto it:board[i])
       {
           cout<<it<<" ";
       }
       cout<<endl;
   }
}
else{
    cout<<"not posible";
}
return 0;
}