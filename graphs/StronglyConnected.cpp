/*Given an adjacency matrix, adj of Directed Graph, Find the number of strongly connected components in the graph.*/

// code:-
class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>&adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Perform a DFS and push nodes into the stack in topological order
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Reverse the graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i]=0;
            for (auto it : adj[i]) {
                //i->it
                //it->i
                adjT[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the reversed graph
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }

        return scc;
    }
};