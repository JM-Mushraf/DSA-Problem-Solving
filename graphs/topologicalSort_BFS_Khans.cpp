#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int v, vector<int> adj[])
{
    int indegree[v]={0};

    for(int i=0;i<v;i++)
    {
        for(int it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
               q.push(it);
        }
    }
    return topo;
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