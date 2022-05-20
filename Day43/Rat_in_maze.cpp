class Solution{
    public:
     void solve(vector<vector<int>> &m,int i,int j,int n,string &move,vector<vector<int>> &dir,vector<string> &ans,string path)
     {
         if(i==n-1 && j==n-1)
         {
            
             ans.push_back(path);
             return;
         }
         
         for(int k=0;k<4;k++){
             int x=dir[k][0]+i;
             int y=dir[k][1]+j;
             
             if(x>=0 && y>=0 && x<n && y<n && m[x][y]==1)
             {
                 m[i][j]=0;
                 solve(m,x,y,n,move,dir,ans,path+move[k]);
                 m[i][j]=1;
             }
         }
         
         
     }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        string move="DRUL";
        vector<string>ans;
        if(m[0][0])
        {
             solve(m,0,0,n,move,dir,ans,"");
        }
        return ans;
    }
};