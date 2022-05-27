class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size()==0 && n==1)
        {
            return 1.0;
        }
        vector<int>adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        
        vector<bool>visited(n+1,false);
        queue<pair<int,double>>q;
        
        q.push({1,1});
        visited[1]=true;
        bool found=false;
        double ans;
        int time=0;
       while(!q.empty())
       {
           int sz=q.size();
           time++;
           //not found in t time
            if(time>t && !found)
           {
               return 0.0;
           }
           while(sz--)
           {
               auto[cur,curprob]=q.front();
               q.pop();
               
               vector<int>temp;
               for(auto it:adj[cur])
               {
                   if(!visited[it])
                   {
                       //found before t but not leaf
                       if(found && cur==target)
                       {
                           return 0.0;
                       }
                       temp.push_back(it);
                       visited[it]=true;
                   }
                  
                  
               }
               double newprob=curprob/double(temp.size());
               
               for(auto it:temp)
               {
                    q.push({it,newprob});
                    if(it==target)
                   {
                        //found at exact t time
                        if(time==t)
                        {
                            return newprob;
                        }
                       ans=newprob;
                       found=true;
                   }
               }
           }
          
       }
      
        return ans;
    }
};