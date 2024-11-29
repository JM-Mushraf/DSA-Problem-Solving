/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/
// Code:-

class DisjointSets
{
public:
    vector<int> parent, size;
    DisjointSets(int v)
    {
        size.resize(v + 1, 1);
        parent.resize(v + 1);
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
        }
    }
    int findupr(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupr(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int u_ulp = findupr(u);
        int v_ulp = findupr(v);
        if (u_ulp == v_ulp)
        {
            return;
        }
        if (size[u_ulp] < size[v_ulp])
        {
            parent[u_ulp] = v_ulp;
            size[v_ulp]++;
        }
        else
        {
            parent[v_ulp] = u_ulp;
            size[u_ulp]++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSets ds(n);
        int extracnt = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findupr(u) == ds.findupr(v))
            {
                extracnt++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
        }
        int ans = cnt - 1;
        if (extracnt >= ans)
            return ans;
        return -1;
    }
};