#include<bits/stdc++.h>
using namespace std;
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
         parent[fromp]=top;
}

bool iscycle(vector<pair<int,int>>edges,vector<int>&parent)
{
    for(auto p:edges)
    {
        int fromp=find_parent(p.first,parent);
         int top=find_parent(p.second,parent);

         if(fromp==top)
         {
             return true;
         }

         union_op(p.first,p.second,parent);
    }
    return false;
}

int main()
{
int n,e;
cin>>n>>e;
vector<pair<int,int>>edges;
vector<int>parent(n,-1);
for(int i=0;i<e;i++)
{
    int src,dest;
    cin>>src>>dest;
 edges.push_back({src,dest});
}

if(iscycle(edges,parent))
{
    cout<<"cycle";
}
else
{
    cout<<"no cycle";
}

return 0;
}