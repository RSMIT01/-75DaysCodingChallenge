class Solution {
public:
    bool dfs(vector<int>adj[],vector<int> &color,int curcolor,int node)
    {
        color[node]=1-curcolor;
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(!dfs(adj,color,color[node],it))
                {
                    return false;
                }
            }
            else if(color[node]==color[it])
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        vector<int>color(n+1,-1);
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
               adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1 &&  !dfs(adj,color,1,i))
            {
               return false;
            }
        }
        return true;
    }
};