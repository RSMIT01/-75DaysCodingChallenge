class Solution {
public:
    int dijkashtra(vector<pair<int,int>>adj[],int n,int k)
    {
       vector<int>visited(n+1,-1);
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
       multiset<pair<int,int>>s;
        s.insert({0,k});
        while(!s.empty())
        {
            auto node=*s.begin();
            int cur=node.second;
            s.erase(s.begin());
            if(visited[cur]!=-1)
            {
               continue;
            }
            visited[cur]=1;
            for(auto it:adj[cur])
            {
                if(dist[cur]+it.second<dist[it.first])
                {
                    dist[it.first]= dist[cur]+it.second;
                    s.insert({dist[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==-1)
            {
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        return dijkashtra(adj,n,k);
    }
};