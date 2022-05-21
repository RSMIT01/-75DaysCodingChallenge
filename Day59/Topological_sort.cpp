#include<bits/stdc++.h>
using namespace std;
void toposort(vector<int> &visited,vector<int>adj[],stack<int> &st,int node)
{
    
     
         visited[node]=1;
         for(auto it:adj[node])
         {
             if(!visited[it])
             {
                  toposort(visited,adj,st,it);
             }
         }
        
          st.push(node);
        
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
}

vector<int>visited(v+1,0);
stack<int>st;
for(int i=0;i<v;i++)
{
    if(!visited[i])
    {
        toposort(visited,adj,st,i);
    }
}
while(!st.empty())
{
    cout<<st.top()<<" ";
    st.pop();
}
return 0;
}