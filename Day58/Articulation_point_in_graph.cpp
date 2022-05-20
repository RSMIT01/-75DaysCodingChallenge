#include<bits/stdc++.h>
using namespace std;
void dfstrverse(vector<int> &visited,vector<int>adj[],vector<int> &tim,vector<int> &low,int node,int timer,int parent,vector<int> &articulation)
{
         visited[node]=1;
         int child=0;
         tim[node]=low[node]=timer++;
         for(auto it:adj[node])
         {
             if(it==parent)
             {
                 continue;
             }
             if(!visited[it])
             {
                  dfstrverse(visited,adj,tim,low,it,timer,node,articulation);
                  low[node]=min(low[node],low[it]);
                  if(low[it]>=tim[node] && parent!=-1)
                  {
                     articulation[node]=1;
                  }
                  child++;
             }
             else{
                 low[node]=min(low[node],tim[it]);
             }
         }
         if(parent==-1 && child>1)
         {
             articulation[node]=1;
         }
}
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v+1];
vector<int>visited(v+1,0);
vector<int>tim(v+1,-1);
vector<int>low(v+1,-1);
vector<int>articulation(v+1,-1);
for(int i=0;i<e;i++)
{
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
}
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        dfstrverse(visited,adj,tim,low,i,0,-1,articulation);
    }
}
for(int i=1;i<=v;i++)
{
  if(articulation[i]!=-1)
  {
      cout<<i<<" ";
  }
}
return 0;
}