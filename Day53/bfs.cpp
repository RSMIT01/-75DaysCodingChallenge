#include<bits/stdc++.h>
using namespace std;
void bfstrverse(vector<int> &visited,vector<int>adj[],vector<int> &bfs,int node)
{
     queue<int>q;
     q.push(node);
     visited[node]=1;
     while(!q.empty())
     {
         int curr=q.front();
         q.pop();
         bfs.push_back(curr);
         for(auto it:adj[curr])
         {
             if(!visited[it])
             {
                 q.push(it);
                 visited[it]=1;
             }
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
vector<int>bfs;
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        bfstrverse(visited,adj,bfs,i);
    }
}
for(auto i:bfs)
{
    cout<<i<<" ";
}
return 0;
}