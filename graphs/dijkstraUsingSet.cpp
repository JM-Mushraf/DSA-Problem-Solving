vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int v = adj.size();
    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);  // Initialize distances to infinity
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int edgeWeight = it.first;
        st.erase(it);

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgw = it.second;

            if (edgeWeight + edgw < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = edgeWeight + edgw;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
