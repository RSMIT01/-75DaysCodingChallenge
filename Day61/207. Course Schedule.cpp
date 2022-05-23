class Solution {
public:
    bool iscycle(vector<int>adj[], vector<int> &dfsvisited,vector<int> &visited,int node)
    {
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                if(iscycle(adj,dfsvisited,visited,it))
                {
                    return true;
                }
            }
            else if(dfsvisited[it])
            {
                return true;
            }
        }
       dfsvisited[node]=0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>visited(numCourses,0);
        vector<int>dfsvisited(numCourses,0);
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                 if(iscycle(adj,dfsvisited,visited,i))
                 {
                     return false;
                 }
            }
        }
       return true;
    }
};