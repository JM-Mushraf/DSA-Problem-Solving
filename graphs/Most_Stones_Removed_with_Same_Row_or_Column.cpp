class DisjointSet
{
public:
  vector<int> rank, parent,size;
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n+1,1);
    for (int i = 0; i <= n; i++)
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
  void unionByRank(int u, int v)
  {
    int ulp_u = findUpr(u);
    int ulp_v = findUpr(v);
    if (ulp_u == ulp_v)
      return;
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
void unionBySize(int u, int v) {
    int ulp_u = findUpr(u);
    int ulp_v = findUpr(v);
    if (ulp_u == ulp_v)
        return;
    if (size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u]; // Update the size of the root
    } else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v]; // Update the size of the root
    }
}

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        int n=stones.size();

        for(auto it :stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it :stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it :stoneNodes){
            if(ds.findUpr(it.first)==it.first) cnt++;
        }
        //n->total number of nodes,cnt->number of unique parents
        return n-cnt;
    }
};