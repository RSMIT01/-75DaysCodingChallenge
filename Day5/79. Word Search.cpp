class Solution {
public:
    bool checkother(vector<vector<char>>& board,int i,int j,int count, string &word)
    {
        if(count==word.length())
        {
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || word[count]!=board[i][j])
        {
            return false;
        }
        char temp=board[i][j];
        board[i][j]=' ';
        bool found= checkother(board,i+1,j,count+1,word) ||
                    checkother(board,i-1,j,count+1,word) ||
                    checkother(board,i,j+1,count+1,word) || 
                    checkother(board,i,j-1,count+1,word);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[i].size();j++)
           {
               if(word[0]==board[i][j] && checkother(board,i,j,0,word))
               {
                   return true;
               }
           }
       }
        return  false;
    }
};