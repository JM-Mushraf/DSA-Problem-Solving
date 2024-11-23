/*Number of Provinces using DisJointSets
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
*/
// Code:-
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUpr(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUpr(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUpr(u);
        int ulp_v = findUpr(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]++;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        DisjointSet ds(v);
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (ds.parent[i] == i)
                count++;
        }
        return count;
    }
};
