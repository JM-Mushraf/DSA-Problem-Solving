/*
120. Triangle
Solved
Medium
Topics
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).*/

// Code:-
class Solution
{
public:
    // recurssion
    //  int f(int i,int j,vector<vector<int>>& triangle,int n){
    //      if(i==n-1)return triangle[n-1][j];
    //      int d=triangle[i][j]+f(i+1,j,triangle,n);
    //      int dg=triangle[i][j]+f(i+1,j+1,triangle,n);
    //      return min(d,dg);
    //  }
    //  int minimumTotal(vector<vector<int>>& triangle) {
    //      int n=triangle.size();
    //      return f(0,0,triangle,n);
    //  }

    // Memoization
    //  int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    //      if(i==n-1)return triangle[n-1][j];
    //      if(dp[i][j]!=-1) return dp[i][j];
    //      int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
    //      int dg=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    //      return dp[i][j]=min(d,dg);
    //  }
    //  int minimumTotal(vector<vector<int>>& triangle) {
    //      int n=triangle.size();
    //      vector<vector<int>>dp(n,vector<int>(n,-1));
    //      return f(0,0,triangle,n,dp);
    //  }

    // //Tabulation
    //  int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=triangle[n-1][j];}
    //         for(int i=n-2;i>=0;i--){
    //             for(int j=i;j>=0;j--){
    //                 int d=triangle[i][j]+dp[i+1][j];
    //                 int dg=triangle[i][j]+dp[i+1][j+1];
    //                 dp[i][j]=min(d,dg);
    //             }
    //         }

    //     return dp[0][0];
    // }

    // Tabulation
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n, 0), curr(n, 0);
        ;
        for (int j = 0; j < n; j++)
        {
            front[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j + 1];
                curr[j] = min(d, dg);
            }
            front = curr;
        }

        return front[0];
    }
};