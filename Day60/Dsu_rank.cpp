#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    int parent;
    int rank;
};
int find_parent(int node,vector<vertex> &dsuf)
{
    if(dsuf[node].parent==-1)
    {
        return node;
    }
    return dsuf[node].parent=find_parent( dsuf[node].parent,dsuf);
}

void union_op(int from,int to,vector<vertex>&dsuf)
{
       if(dsuf[from].rank>dsuf[to].rank)
       {
           dsuf[to].parent=from;
       }
      else if(dsuf[from].rank<dsuf[to].rank)
       {
           dsuf[from].parent=to;
       }
       else{
           dsuf[from].parent=to;
            dsuf[to].rank+=1;
       }
        
}

bool iscycle(vector<pair<int,int>>edges,vector<vertex>&dsuf)
{
    for(auto p:edges)
    {
        int fromp=find_parent(p.first,dsuf);
         int top=find_parent(p.second,dsuf);

         if(fromp==top)
         {
             return true;
         }

         union_op(p.first,p.second,dsuf);
    }
    return false;
}

int main()
{
int n,e;
cin>>n>>e;
vector<pair<int,int>>edges;
vector<vertex>dsuf(n);
for(int i=0;i<n;i++)
{
    dsuf[i].rank=0;
    dsuf[i].parent=-1;
}
for(int i=0;i<e;i++)
{
    int src,dest;
    cin>>src>>dest;
 edges.push_back({src,dest});
}

if(iscycle(edges,dsuf))
{
    cout<<"cycle";
}
else
{
    cout<<"no cycle";
}

return 0;
}