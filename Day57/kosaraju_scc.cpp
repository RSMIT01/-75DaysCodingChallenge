#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &visited)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
    }
    vector<int> visited(n + 1, 0);

    dfs(1, adj, visited);

    bool isscc = true;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "Not Strongly connected\n";
            isscc = false;
            break;
        }
        visited[i]=0;
    }

    if (isscc)
    {
        vector<int> trandpose[n + 1];
        for (int i = 1; i <= n; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                trandpose[it].push_back(i);
            }
        }

        dfs(1, trandpose, visited);

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cout << "Not Strongly connected\n";
                 isscc = false;
                 break;
            }
        }
    }
    if(isscc)
    {
        cout<<"Strongly connected\n";
    }
    return 0;
}