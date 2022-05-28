class Solution {
public:
    int find_parent(int node,vector<int> &parent)
    {
        if(parent[node]==-1)
        {
            return node;
        }
        return find_parent(parent[node],parent);
    }

    void union_op(int from,int to,vector<int> &parent)
    {
            int fromp=find_parent(from,parent);
             int top=find_parent(to,parent);
             parent[top]=fromp;
    }
    bool iscycle(int cellno1,int cellno2,vector<int> &parent)
        {
            if(find_parent(cellno1,parent)==find_parent(cellno2,parent))
            {
                return true;
            }
          union_op(cellno1,cellno2,parent);
            return false;
        }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int nodes=n+1;
        vector<int>parent(nodes*nodes,-1);
        
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                 if(i==0 || j==0 || i==nodes-1 || j==nodes-1)
                 {
                      int cellno=(i*nodes)+j;
                       if(cellno!=0)
                       {
                           union_op(0,cellno,parent);
                       }
                 }
            }
        }
        
        int regions=1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                  if(grid[i][j]=='/')
                  {
                      int cellno1=(i*nodes)+(j+1);
                      int cellno2=(i+1)*nodes+j;
                      if(iscycle(cellno1,cellno2,parent))
                      {
                          
                          regions++;
                      }
                      
                  }
                 else if(grid[i][j]=='\\')
                  {
                      int cellno1=(i*nodes)+j;
                      int cellno2=(i+1)*nodes+(j+1);
                      
                      if(iscycle(cellno1,cellno2,parent))
                      {
                         
                          regions++;
                      }
                  }
            }
        }
      
        return regions;
        
    }
};