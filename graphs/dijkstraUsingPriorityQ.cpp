/*
dijkstra algorithm to find shortest path from src node to all nodes,
for this here we'll use priority queue technique:
problem statement in gfg

Dijkstra Algorithm
Difficulty: MediumAccuracy: 50.83%Submissions: 184K+Points: 4
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> distances = dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 0; i < V; i++)
    {
        if (distances[i] == 1e9)
        {
            cout << i << ": INF" << endl;
        }
        else
        {
            cout << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}
