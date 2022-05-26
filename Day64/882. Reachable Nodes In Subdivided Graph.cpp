class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
     vector<vector<int>>graph(n,vector<int>(n,-1));
        for(auto it:edges)
        {
           graph[it[0]][it[1]]=it[2]; 
            graph[it[1]][it[0]]=it[2]; 
        }
        vector<bool>visited(n,false);
        priority_queue<pair<int,int>>pq;
        pq.push({maxMoves,0});
        int ans=0;
        while(!pq.empty())
        {
            auto[rem_mov,cur]=pq.top();
            pq.pop();
            
            if(visited[cur])
            {
                continue;
            }
            
            visited[cur]=true;
            ans++;
            
            for(int i=0;i<n;i++)
            {
                if(graph[cur][i]!=-1)
                {
                    if(!visited[i] && rem_mov>=graph[cur][i]+1)
                    {
                        pq.push({rem_mov-graph[cur][i]-1,i});
                    }
                    int moves=min(rem_mov,graph[cur][i]);
                    graph[cur][i]-=moves;
                    graph[i][cur]-=moves;
                    ans+=moves;
                }
            }
            
        }
        return ans;
    }
};