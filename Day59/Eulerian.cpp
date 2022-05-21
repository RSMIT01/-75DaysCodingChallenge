#include<bits/stdc++.h>
using namespace std;
void dfstraverse(vector<int>adj[],vector<int> &visited,int node)
{
    visited[node]=1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfstraverse(adj,visited,it);
        }
    }
}
void checkeulerian(vector<int>adj[],int v)
{
    vector<int>visited(v,0);
    int start=-1;
    for(int i=0;i<v;i++)
    {
        if(adj[i].size()!=0)
        {
            start=i;
            break;
        }
    }
    if(start==-1)
    {
        cout<<"graph has a Euler cycle\n";
        return;
    }
    dfstraverse(adj,visited,start);

    //check connected
    for(int i=0;i<v;i++)
    {
        if(adj[i].size() && !visited[i])
        {
            cout<<"graph is not Eulerian";
            return;
        }
    }
    int odd=0;
    for(int i=0;i<v;i++)
    {
        if(adj[i].size()&1)
        {
            odd++;
        }
    }
     
    if(odd==0)
    {
        cout<<"graph has a Euler cycle\n";
    }
    else if(odd<=2)
    {
       cout<<"graph has a Euler path\n";
    }
    else{
        cout<<"graph is not Eulerian";
    }

}

int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v];
for(int i=0;i<e;i++)
{
    int src,dest;
    cin>>src>>dest;
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
checkeulerian(adj,v);
return 0;
}