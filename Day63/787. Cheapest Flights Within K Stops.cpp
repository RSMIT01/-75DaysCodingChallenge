class Solution {
public:
 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int ans=INT_MAX;
        vector<int>stops(n,INT_MAX);
        vector<int>dist(n,INT_MAX);
        multiset<pair<int,pair<int,int>>>s;
        s.insert({0,{src,0}});
        dist[src]=0;
        
        while(!s.empty())
        {
          pair<int,pair<int,int>>cur=*s.begin();
            s.erase(s.begin());
            
            if(cur.second.first==dst)
            {
                return cur.first;
            }
            if(stops[cur.second.first]<=cur.second.second || cur.second.second>=k+1)
            {
                continue;
            }
           stops[cur.second.first]=cur.second.second;
            
            for(auto it:adj[cur.second.first])
            {
                   s.insert({it.second+cur.first,{it.first,cur.second.second+1}});
            }
           
            
        }
        
       return -1;
    }
};