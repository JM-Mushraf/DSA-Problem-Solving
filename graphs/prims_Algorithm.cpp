#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V, 0);

    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (vis[node]) continue;  // IMPORTANT: skip already-in-MST nodes

        vis[node] = 1;
        sum += dist;

        for (auto &[adjNode, wt] : adj[node]) {
            if (!vis[adjNode]) {
                pq.push({wt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << primsMST(V, adj) << endl;

    return 0;
}
