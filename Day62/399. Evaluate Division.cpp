class Solution {
public:
    double bfs(string &src,string &dest,  unordered_map<string,vector<pair<string,double>>> &adj)
    {
        if(src==dest)
        {
            return 1.0;
        }
        queue<pair<string,double>>q;
        unordered_set<string>visited;
        q.push({src,1.0});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                
            
            auto[cur,val]=q.front();
            q.pop();
            if(cur==dest)
            {
                return val;
            }
           
            for(auto [v,dist]:adj[cur])
            {
                if(visited.find(v)==visited.end())
                {
                    q.push({v,dist*val});
                     visited.insert(v);
                }
            }
          }
        }
        return -1.0;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++)
        {
            string src=queries[i][0];
            string dest=queries[i][1];
            double q_res=-1.0;
            if(adj.find(src)!=adj.end() && adj.find(dest)!=adj.end())
            {
                q_res=bfs(src,dest,adj);
            }
            ans.push_back(q_res);
        }
        
        
        return ans;
    }
};