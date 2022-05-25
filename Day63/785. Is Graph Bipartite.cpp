class Solution {
public:
    bool bfscheck(vector<vector<int>>& graph,int node, vector<int> &color,int precol)
    {
        queue<int>q;
        q.push(node);
        color[node]=precol;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int i=0;i<graph[cur].size();i++)
            {
                int it=graph[cur][i];
                if(color[it]==-1)
                {
                    color[it]=1-color[cur];
                    q.push(it);
                }
                else if(color[it]==color[cur])
                {
                    return false;
                }
            }
        }
       return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
             if(color[i]==-1)
             {
                if(!bfscheck(graph,i,color,0))
                {
                       return false;
                }
             }
        }
        return true;
    }
};