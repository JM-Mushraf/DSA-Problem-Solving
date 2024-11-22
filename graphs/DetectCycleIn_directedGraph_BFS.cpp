#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool topoSort(int v, vector<int> adj[])
{
    int indegree[v] = {0};

    for (int i = 0; i < v; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // If count doesn't match the number of vertices, there's a cycle
    if (count == v) return false; // No cycle
    return true; // Cycle detected
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
        adj[u - 1].push_back(v - 1); // Adjusted for 1-based indexing
    }

    bool hasCycle = topoSort(v, adj);

    if (hasCycle)
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle.\n";

    return 0;
}
