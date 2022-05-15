#include<bits/stdc++.h>
using namespace std;
void dfstrverse(vector<int> &visited,vector<int>adj[],vector<int> &dfs,int node)
{
    
         dfs.push_back(node);
         visited[node]=1;
         for(auto it:adj[node])
         {
             if(!visited[it])
             {
                  dfstrverse(visited,adj,dfs,it);
             }
         }
}
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v+1];

for(int i=0;i<e;i++)
{
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
}

vector<int>visited(v+1,0);
vector<int>dfs;
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        dfstrverse(visited,adj,dfs,i);
    }
}
for(auto i:dfs)
{
    cout<<i<<" ";
}
return 0;
}