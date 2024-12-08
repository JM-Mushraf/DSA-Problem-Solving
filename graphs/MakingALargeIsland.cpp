/*You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.*/
//Code:-
class DisjointSet
{
public:
  vector<int> rank, parent,size;
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n+1,1);
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
        size[ulp_v] += size[ulp_u];
    } else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

};
class Solution {
private:
  bool isValid(int adjr,int adjc,int n){
    return (adjr>=0 && adjr<n && adjc>=0 && adjc<n);
  }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        //step1
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]==0) continue;

                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};

                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dc[ind];

                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo=row*n+col;
                        int adjNode=newr*n+newc;
                        ds.unionBySize(nodeNo,adjNode);
                    }
                }
            }
        }

        //step2
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;
                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dc[ind];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        components.insert(ds.findUpr(newr*n+newc));
                    }
                }
                int totalSize=0;
                for(auto it :components){
                    totalSize+=ds.size[it];
                }
                mx=max(mx,totalSize+1);
            }
        }

        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx=max(mx,ds.size[ds.findUpr(cellNo)]);
        }
        return mx;
    }
};