class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
            
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==1)
            {
                q.push(i);
            }
        }
      
        while(n>2)
        {
               
            int sz=q.size();
            n=n-sz;
            for(int i=0;i<sz;i++)
            {
                int cur=q.front();
                q.pop();
                for(auto it:adj[cur])
                {
                    adj[it].erase(cur);
                    if(adj[it].size()==1)
                    {
                        q.push(it);
                    }
                }
            }
            
        }
        vector<int>mhts;
        while(!q.empty())
        {
            mhts.push_back(q.front());
            q.pop();
        }
        return mhts;
        
        
    }
};