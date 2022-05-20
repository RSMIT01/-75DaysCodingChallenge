#include<bits/stdc++.h>
using namespace std;
void dfstrverse(vector<int> &visited,vector<int>adj[],vector<int> &tim,vector<int> &low,int node,int timer,int parent)
{
         visited[node]=1;
         tim[node]=low[node]=timer++;
         for(auto it:adj[node])
         {
             if(it==parent)
             {
                 continue;
             }
             if(!visited[it])
             {
                  dfstrverse(visited,adj,tim,low,it,timer,node);
                  low[node]=min(low[node],low[it]);
                  if(low[it]>tim[node])
                  {
                      cout<<it<<" "<<node<<endl;
                  }
             }
             else{
                 low[node]=min(low[node],tim[it]);
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
vector<int>tim(v+1,-1);
vector<int>low(v+1,-1);
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        dfstrverse(visited,adj,tim,low,i,0,-1);
    }
}

return 0;
}