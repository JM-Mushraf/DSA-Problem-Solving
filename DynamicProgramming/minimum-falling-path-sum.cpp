/*
931. Minimum Falling Path Sum
Solved
Medium
Topics
Companies
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

//Solution
class Solution {
    public:
    //Recurssion
        // int f(int i,int j,vector<vector<int>>& matrix){
        //     if(j<0 || j>=matrix[0].size()) return 1e9;
        //     if(i==0) return matrix[0][j];
        //     int s=matrix[i][j]+f(i-1,j,matrix);
        //     int ld=matrix[i][j]+f(i-1,j-1,matrix);
        //     int rd=matrix[i][j]+f(i-1,j+1,matrix);
        //     return min(s,min(ld,rd));
        // }
        // int minFallingPathSum(vector<vector<int>>& matrix) {
        //     int n=matrix.size();
        //     int m=matrix[0].size();
        //     int ans=1e9;
        //     for(int i=0;i<m;i++){
        //         ans=min(ans,f(n-1,i,matrix));
        //     }
        //     return ans;
        // }
    
        //memoization
        // int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        //     if(j<0 || j>=matrix[0].size()) return 1e9;
        //     if(i==0) return matrix[0][j];
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     int s=matrix[i][j]+f(i-1,j,matrix,dp);
        //     int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
        //     int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
        //     return dp[i][j]=min(s,min(ld,rd));
        // }
        // int minFallingPathSum(vector<vector<int>>& matrix) {
        //     int n=matrix.size();
        //     int m=matrix[0].size();
        //     int ans=1e9;
        //     vector<vector<int>>dp(n,vector<int>(m,-1));
        //     for(int i=0;i<m;i++){
        //         ans=min(ans,f(n-1,i,matrix,dp));
        //     }
        //     return ans;
        // }
    
        //Tabulation
        // int minFallingPathSum(vector<vector<int>>& matrix) {
        //     int n=matrix.size();
        //     int m=matrix[0].size();
        //     int ans=1e9;
        //     vector<vector<int>>dp(n,vector<int>(m,0));
    
        //     for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        //     for(int i=1;i<n;i++){
        //         for(int j=0;j<m;j++){
        //             int u=matrix[i][j]+dp[i-1][j];
        //             int ld=matrix[i][j];
        //             if(j-1>=0) ld+=dp[i-1][j-1];
        //             else ld=1e9;
        //             int rd=matrix[i][j];
        //             if(j+1<m) rd+=dp[i-1][j+1];
        //             else rd=1e9;
        //             dp[i][j]=min(u,min(ld,rd));
        //         }
        //     }
        //     for(int i=0;i<m;i++){
        //         ans=min(ans,dp[n-1][i]);
        //     }
        //     return ans;
        // }
    
        //Space Optimization
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            int ans=1e9;
            vector<int> prev(m, 0);
            vector<int> curr(m, 0);
    
    
            for(int i=0;i<m;i++) prev[i]=matrix[0][i];
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    int u=matrix[i][j]+prev[j];
                    int ld=matrix[i][j];
                    if(j-1>=0) ld+=prev[j-1];
                    else ld=1e9;
                    int rd=matrix[i][j];
                    if(j+1<m) rd+=prev[j+1];
                    else rd=1e9;
                    curr[j]=min(u,min(ld,rd));
                }
                prev=curr;
            }
            for(int i=0;i<m;i++){
                ans=min(ans,prev[i]);
            }
            return ans;
        }
    };