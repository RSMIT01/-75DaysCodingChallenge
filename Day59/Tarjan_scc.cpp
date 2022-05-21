#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int time, vector<int> adj[], vector<bool> &ispresent, stack<int> &st, vector<int> &low, vector<int> &disc)
{
    low[node] = disc[node] = time;
    time++;
    st.push(node);
    ispresent[node] = true;
    for (int v : adj[node])
    {
        if (disc[v] == -1)
        {
            dfs(v, time, adj, ispresent, st, low, disc);
            low[node] = min(low[v], low[node]);
        }
        else if (ispresent[v])
        {
            low[node] = min(low[node], disc[v]);
        }
    }
    if (low[node] == disc[node])
    {
        cout << "SCC : ";
        while (st.top() != node)
        {
            cout << st.top() << " ";
            ispresent[st.top()] = false;
            st.pop();
        }
        cout << st.top() << "\n";
        ispresent[st.top()] = false;
        st.pop();
    }
}
int main()
{
    int n, e;
    cin>>n>>e;
    vector<int> adj[n];

    for (int i = 0; i < e; i++)
    {
        int src, dest;
         cin>>src>>dest;
       adj[src].push_back(dest);
    }

    stack<int> st;
    vector<bool> ispresent(n, false);
    vector<int> low(n, -1), disc(n, -1);

    dfs(0, 0, adj, ispresent, st, low, disc);
    return 0;
}