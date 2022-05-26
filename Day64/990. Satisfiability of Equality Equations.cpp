class Solution {
public:
    int find_parent(int node,vector<int>&parent)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return find_parent(parent[node],parent);
    }
    void union_op(int var1,int var2,vector<int>  &parent)
    {
      int par1=find_parent(var1,parent);
        int par2=find_parent(var2,parent);
         parent[par1]=par2;
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        int n=equations.size();
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
            {
                union_op((equations[i][0]-'a'),(equations[i][3]-'a'),parent);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!' && (find_parent((equations[i][0]-'a'),parent)==find_parent((equations[i][3]-'a'),parent)))
            {
                return false;
            }
        }
        return true;
    }
};