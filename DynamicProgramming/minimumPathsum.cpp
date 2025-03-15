/*64. Minimum Path Sum
Solved
Medium
Topics
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/
// code:-
class Solution
{
public:
    // Recurssion
    //  int f(int i,int j,vector<vector<int>>& grid){
    //      if(i==0 && j==0) return grid[0][0];
    //      if(i<0 || j<0)return 1e9;
    //      int up=grid[i][j]+f(i-1,j,grid);
    //      int left=grid[i][j]+f(i,j-1,grid);
    //      return min(up,left);
    //  }
    //  int minPathSum(vector<vector<int>>& grid) {
    //      int n=grid.size();
    //      int m=grid[0].size();

    //     return f(n-1,m-1,grid);
    // }

    // Memoization
    //  int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //      if(i==0 && j==0) return dp[i][j]=grid[0][0];
    //      if(i<0 || j<0)return 1e9;
    //      if(dp[i][j]!=-1)return dp[i][j];
    //      int up=grid[i][j]+f(i-1,j,grid,dp);
    //      int left=grid[i][j]+f(i,j-1,grid,dp);
    //      return dp[i][j]=min(up,left);
    //  }
    //  int minPathSum(vector<vector<int>>& grid) {
    //      int n=grid.size();
    //      int m=grid[0].size();
    //      vector<vector<int>>dp(n,vector<int>(m,-1));
    //      return f(n-1,m-1,grid,dp);
    //  }

    // Tabulation
    //  int minPathSum(vector<vector<int>>& grid) {
    //      int n=grid.size();
    //      int m=grid[0].size();
    //      vector<vector<int>>dp(n,vector<int>(m,-1));
    //      for(int i=0;i<n;i++){
    //          for(int j=0;j<m;j++){
    //              if(i==0 && j==0){
    //              dp[i][j]=grid[i][j];
    //              }
    //              else{
    //                 int up = INT_MAX, left = INT_MAX;
    //                 if(i>0) up=grid[i][j]+dp[i-1][j];
    //                  if(j>0) left=grid[i][j]+dp[i][j-1];
    //                  dp[i][j]=min(up,left);
    //              }
    //          }
    //      }
    //      return dp[n-1][m-1];
    //  }

    // Space Optimization
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = grid[i][j];
                }
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + prev[j];
                    if (j > 0)
                        left = grid[i][j] + curr[j - 1];
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};