class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        int n=graph.size();
        vector<int>adj[n];
        vector<int>indegree(n,0);
     
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
           queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>safe_nodes;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            safe_nodes.push_back(cur);
            for(auto it:adj[cur])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};