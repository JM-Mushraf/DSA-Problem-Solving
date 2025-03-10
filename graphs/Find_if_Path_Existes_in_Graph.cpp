
/*
1971. Find if Path Exists in Graph
Easy
Topics
Companies
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.*/

// code:->
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       unordered_map<int,vector<int>> map;
        for(auto x:edges)
        {
            vector<int> temp=x;
            int u=temp[0];
            int v=temp[1];

            map[u].push_back(v);
            map[v].push_back(u);
        }

        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();

            vector<int> temp=map[v];
            for(int i=0;i<temp.size();i++)
            {
                int vertex=temp[i];
                if(visited[vertex]==false)
                {
                    q.push(vertex);
                    visited[vertex]=true;
                }
            }
            if(visited[destination])
               return visited[destination];
        }
        return visited[destination];
    }
};