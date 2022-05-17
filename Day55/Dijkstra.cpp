#include <bits/stdc++.h>
using namespace std;
int minvalue(int distance[],bool visited[],int n)
{
 int mini=-1;
   for (int i = 0; i < n; i++)
   {
       if(!visited[i] && (mini==-1 || distance[i]<distance[mini]))
       {
           mini=i;
       }
    
   }
   return mini;
   
}
void dijkstra(vector<vector<int>>graph, int n)
{
    bool visted[n];
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        visted[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minval=minvalue(distance,visted,n);
        visted[minval]=true;
        for (int j = 0; j < n; j++)
        {
           if(graph[minval][j]!=0 && !visted[j])
           {
               int dist=distance[minval]+graph[minval][j];
               if(dist<distance[j])
               {
                   distance[j]=dist;
               }
           }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" "<<distance[i]<<endl;;
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
    dijkstra(graph, v);

    return 0;
}