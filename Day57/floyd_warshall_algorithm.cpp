#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < e; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }

    // floyd warshall

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if(i==j)
                {
                    graph[i][j]=0;
                }
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX  && graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
           if(graph[i][j]==INT_MAX)
           {
               cout<<"INF"<<" ";
           }
           else
           {
           cout<<graph[i][j]<<" ";
           }
        }
        cout<<endl;
    }

    return 0;
}