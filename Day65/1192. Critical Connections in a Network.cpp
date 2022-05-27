class Solution {
public:
    
    void dfs(int node,int time,vector<int>adj[],vector<vector<int>> &bridges,vector<int> &parent,vector<int>&low,vector<int>&disc)
    {
        low[node]=disc[node]=time;
         time++;
        
        for(int v:adj[node])
        {
            if(v==parent[node])
            {
                continue;
            }
            else if(disc[v]==-1)
            {
                parent[v]=node;
                 dfs(v,time,adj,bridges,parent,low,disc);
                 low[node]=min(low[node],low[v]);
                 
                 if(low[v]>disc[node])
                 {
                     bridges.push_back({node,v});
                 }
            }
            else if(v!=parent[node])
            {
              low[node]=min(low[node],disc[v]);
            }
        }
    }
   
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            int src=connections[i][0];
            int dest=connections[i][1];
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        vector<vector<int>>bridges;
        vector<int>parent(n,-1),low(n,-1),disc(n,-1);
        
         dfs(0,0,adj,bridges,parent,low,disc);
          return bridges;
        
    }
};