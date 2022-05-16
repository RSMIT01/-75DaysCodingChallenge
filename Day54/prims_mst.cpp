#include<bits/stdc++.h>
using namespace std;
int findmin(int weight[],bool mst[],int n)
{
 int mini=-1;
   for (int i = 0; i < n; i++)
   {
       if(!mst[i] && (mini==-1 || weight[i]<weight[mini]))
       {
           mini=i;
       }
    
   }
   return mini;
   
}
void prims( vector<vector<int>>graph,int n)
{
    int weight[n];
    int parent[n];
    bool mst[n];
    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
        mst[i]=false;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n;i++)
    {
       int minval=findmin(weight,mst,n);
       mst[minval]=true;
       for(int j=0;j<n;j++)
       {
           if(graph[minval][j]!=0 && !mst[j])
           {
               if(graph[minval][j]<weight[j])
               {
                   parent[j]=minval;
                   weight[j]=graph[minval][j];
               }
           }
       }
    }
    for(int i = 1; i < n; i++)
    {           
       cout<<parent[i]<<"--"<<i<<" "<<weight[i]<<endl;
    }
    
}
int main()
{
 int v;
    int e;
    cin>>v>>e;
   vector<vector<int>>graph(v+1,vector<int>(v+1));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i <e; i++)
    {
        int v1, v2, value;
        cin >> v1 >> v2 >> value;
        graph[v1][v2] = value;
        graph[v2][v1] = value;
    }
    prims(graph, v);
return 0;
}
