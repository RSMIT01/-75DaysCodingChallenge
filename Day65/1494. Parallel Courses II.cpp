// 69 / 81 test cases passed. 
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
      vector<int>indegree(n+1,0);
        vector<int>adj[n+1];
      for(auto it:relations)
      {
          adj[it[0]].push_back(it[1]);
          indegree[it[1]]++;
      }
        queue<int>q;
        
       for(int i=1;i<=n;i++)
       {
           if(indegree[i]==0)
           {
               q.push(i);
           }
       }
        int sem=0;
        while(!q.empty())
        {
            int sz=min((int)q.size(),k);
            sem++;
            while(sz--)
            {
                int cur=q.front();
                q.pop();
                for(auto it:adj[cur])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return sem;
    }
};