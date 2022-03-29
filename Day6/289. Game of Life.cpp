class Solution {
public:
    //In-place
   vector<vector<int>>dir={{-1,-1},{1,1},{-1,1},{1,-1},{0,1},{1,0},{-1,0},{0,-1}};
   int count_live(vector<vector<int>>& board,int i,int j)
   {
       int count=0;
       for(auto it:dir)
       {
           int row=i+it[0];
           int col=j+it[1];
           if(row>=0 && row<board.size() && col>=0 && col<board[i].size())
           {
               count+=(board[row][col]%10);  //getting cell value
           }
       }
       return count;
   }
    
    
    
    
    void gameOfLife(vector<vector<int>>& board) {
     
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[i].size();j++)
           {
               int live=count_live(board,i,j);
                board[i][j]+=(live*10);   //storing live neighbours by multiplying by 10 
           }
       }
        for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[i].size();j++)
           {
               int live=board[i][j]/10;  //taking neighbours which is live
                  int cur=board[i][j]%10; //taking current cell value
              
               if(cur==1 && live<2)
               {
                   board[i][j]=0;
               }
               else if(cur==1 && (live==2 || live==3))
               {
                   board[i][j]=1;
               }
                else if(cur==1 && live>3)
               {
                   board[i][j]=0;
               }
               else if(cur==0 && live==3)
               {
                    board[i][j]=1;
               }
               else
               {
                   board[i][j]=0;
               }
           }
       }
    
    
    }
};