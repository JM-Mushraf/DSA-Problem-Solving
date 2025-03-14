/*
63. Unique Paths II
Solved
Medium
Topics
Companies
Hint
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.*/
// Code:
class Solution {
    public:
    //Recurssion
    // int mod=(int)(1e9+7);
    //     int f(int i,int j,vector<vector<int>>& obstacleGrid){
    //         if(i>=0 && j>=0 && obstacleGrid[i][j]==1)return 0;
    //         if(i==0 && j==0) return 1;
    //         if(i<0 || j<0)return 0;
    
    //         int up=f(i-1,j,obstacleGrid);
    //         int left=f(i,j-1,obstacleGrid);
    //         return up+left;
    //     }
    //     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //         int n=obstacleGrid.size();
    //         int m=obstacleGrid.size();
    //         return f(m-1,n-1,obstacleGrid);
    //     }
    
    //Memoization
        // int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        //     if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return dp[i][j] = 0;
        //     if(i==0 && j==0) return 1;
        //     if(i<0 || j<0)return 0;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     int up=f(i-1,j,obstacleGrid,dp);
        //     int left=f(i,j-1,obstacleGrid,dp);
        //     return dp[i][j] = (up + left);
        // }
        // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //     int n=obstacleGrid.size();
        //     int m = obstacleGrid[0].size();
        //     vector<vector<int>>dp(n,vector<int>(m,-1));
        //     return f(n-1,m-1,obstacleGrid,dp);
        // }
        
        //Tabulation
        // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //     int n=obstacleGrid.size();
        //     int m = obstacleGrid[0].size();
        //     vector<vector<int>>dp(n,vector<int>(m,0));
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<m;j++){
        //             if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
        //             else if(i==0 && j==0)dp[i][j]=1;
        //             else{
        //                 int up=0;
        //                 int left=0;
        //                 if(i>0)up=dp[i-1][j];
        //                 if(j>0)left=dp[i][j-1];
        //                 dp[i][j]=up+left;
        //             }
        //         }
        //     }
        //     return dp[n-1][m-1];
        // }
    
        //space optimization
            int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int n=obstacleGrid.size();
            int m=obstacleGrid[0].size();
            vector<int>prev(m,0);
            for(int i=0;i<n;i++){
                vector<int>curr(m,0);
                for(int j=0;j<m;j++){
                    if (obstacleGrid[i][j] == 1) curr[j] = 0;
                    else if(i==0 && j==0)curr[j]=1;
                    else{
                        int up=0;
                        int left=0;
                        if(i>0)up=prev[j];
                        if(j>0)left=curr[j-1];
                        curr[j]=up+left;
                    }
                }
                prev=curr;
            }
            return prev[m-1];
        }
    };