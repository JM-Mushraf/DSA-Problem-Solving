/*Minimum Spanning Tree
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
*/
// Code:-
class disjointSet
{
    vector<int> rank, parent;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findulp(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findulp(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        disjointSet ds(V);
        int mstwt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            if (ds.findulp(node) != ds.findulp(adjNode))
            {
                ds.unionByRank(node, adjNode);
                mstwt += wt;
            }
        }
        return mstwt;
    }
};