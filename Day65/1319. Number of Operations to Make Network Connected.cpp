class Solution {
public:
    void dfs(vector<int>adj[],vector<bool> &visited,int node)
    {
        visited[node]=true;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                
                  dfs(adj,visited,it);
            }
           
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<bool>visited(n,false);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
           
        }
        int component=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                component++;
                dfs(adj,visited,i);
            }
        }
        
          if(n-1>connections.size())
          {
              return -1;
          }
            return component-1;
        
    }
};