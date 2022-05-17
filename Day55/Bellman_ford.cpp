#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u;
    int v;
    int w;
    
};
int main()
{
int n,e;
cin>>n>>e;
vector<edge>graph(e);
for (int i = 0; i < e; i++)
{
    int a,b,c;
    cin>>a>>b>>c;
    graph[i].u=a;
    graph[i].v=b;
    graph[i].w=c;
}
int start;
cin>>start;

int inf = 10000000; 
vector<int>distance(n,inf);
distance[start]=0;
for(int i=1;i<=n-1;i++)
{
    for(auto it:graph)
    {
        if(distance[it.u] + it.w< distance[it.v])
        {
            distance[it.v]=distance[it.u]+it.w;
        }
    }
}
bool negcycle=false;
for(auto it:graph)
{
         if(distance[it.u]+it.w<distance[it.v])
        {
            cout<<"Negative cycle";
            negcycle=true;
            break;
        }
}
if(!negcycle)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
}
return 0;
}