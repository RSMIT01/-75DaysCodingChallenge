class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=grid.size() || i<0 || j<0 || j>=grid[i].size() || grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j]=0;
        return (1+solve(grid,i+1,j)+solve(grid,i,j+1)+solve(grid,i-1,j)+solve(grid,i,j-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                     ans=max(ans,solve(grid,i,j)); 
                }
             
            }
        }
        return ans;
    }
};