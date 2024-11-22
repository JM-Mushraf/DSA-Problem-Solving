#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int v, vector<int> adj[])
{
    int vis[v] = {0};
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<int> adj[v];
    cout << "Enter the edges (u -> v format):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    vector<int> result = topoSort(v, adj);

    cout << "Topological Sort: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}