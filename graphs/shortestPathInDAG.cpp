class Solution
{
private:
    void topoSortDfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSortDfs(v, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Topological Sort
        int vis[N] = {0};
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSortDfs(i, vis, adj, st);
            }
        }

        // Initialize distance array
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        // Process nodes in topological order
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            // Update the distances of the adjacent nodes only if the current node has been reached
            if (dist[node] != INT_MAX)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable distances with -1
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};