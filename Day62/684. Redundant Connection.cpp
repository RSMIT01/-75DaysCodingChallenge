class Solution {
public:
    int find_parent(vector<int> &parent,int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return find_parent(parent,parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        for(int i=0;i<edges.size()+1;i++)
        {
            parent[i]=i;
        }
        vector<int>visited(edges.size()+1,-1);
        vector<int>ans;
        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];
            int parent_src=find_parent(parent,src);
             int parent_deest=find_parent(parent,dest);
            if(parent_src==parent_deest)
            {
                ans.clear();
                ans.push_back(src);
                ans.push_back(dest);
            }
            else
            {
                 parent[parent_src]=parent_deest;
            }
        }
       
          return ans;
    }
};