/*Number Of Islands
Difficulty: MediumAccuracy: 60.65%Submissions: 45K+Points: 4
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.*/

// Code:-

class DisjointSet
{
  vector<int> rank, parent,size;

public:
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
   void unionBySize(int u, int v)
  {
    int ulp_u = findUpr(u);
    int ulp_v = findUpr(v);
    if (ulp_u == ulp_v)
      return;
    if(size[ulp_u]<size[ulp_v]){
      parent[ulp_u]=ulp_v;
      size[ulp_v]++;
    }
    else{
      parent[ulp_v]=ulp_u;
      size[ulp_u]++;
    }
  }
};
class Solution {
    bool isValid(int adjr,int adjc,int n,int m){
        return (adjr>=0 && adjr<n && adjc>=0 && adjc<m);
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       DisjointSet ds(n*m);
       int vis[n][m];
       memset(vis,0,sizeof vis);
       int cnt=0;
       vector<int>ans;
       for(auto it :operators){
           int row=it[0];
           int col=it[1];
           if(vis[row][col]==1){
               ans.push_back(cnt);
               continue;
           }
           vis[row][col]=1;
           cnt++;
           
           int dr[]={-1,0,1,0};
           int dc[]={0,1,0,-1};
           
           for(int ind=0;ind<4;ind++){
               int adjr=row+dr[ind];
               int adjc=col+dc[ind];
               if(isValid(adjr,adjc,n,m)){
                   if(vis[adjr][adjc]==1){
                   int nodeNo=row*m+col;
                   int adjNode=adjr*m+adjc;
                   if(ds.findUpr(nodeNo) != ds.findUpr(adjNode)){
                       cnt--;
                       ds.unionBySize(nodeNo,adjNode);
                   }
                  }
               }
           }
           ans.push_back(cnt);
       }
       return ans;
    }
};