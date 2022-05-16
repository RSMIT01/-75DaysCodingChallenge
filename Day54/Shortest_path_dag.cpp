#include<bits/stdc++.h>
using namespace std;
void dac(vector<pair<int,int>>adj[],vector<int> &distance,int start,stack<int> &st)
{
    distance[start]=0;
    while(!st.empty())
    {
        int node=st.top();
         st.pop();
         if(distance[node]!=INT_MAX)
         {
             for(auto it:adj[node])
             {
                 if(distance[node]+it.second<distance[it.first])
                 {
                     distance[it.first]=distance[node]+it.second;
                 }
             }
         }
    }
}
void toposort(vector<int> &visited,vector<pair<int,int>>adj[],stack<int> &st,int node)
{
    
     
         visited[node]=1;
         for(auto it:adj[node])
         {
             if(!visited[it.first])
             {
                  toposort(visited,adj,st,it.first);
             }
         }
          st.push(node);
        
}
int main()
{
int v,e;
cin>>v>>e;
vector<pair<int,int>>adj[v+1];

for(int i=0;i<e;i++)
{
      int x,y,w;
      cin>>x>>y>>w;
      adj[x].push_back({y,w});
}
int start;
cin>>start;
vector<int>visited(v+1,0);
vector<int>distance(v+1,INT_MAX);
stack<int>st;
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        toposort(visited,adj,st,i);
    }
}
dac(adj,distance,start,st);
for (int i = 1; i <=v; i++)
{
   cout<<i<<" "<<distance[i]<<endl;
}

return 0;
}