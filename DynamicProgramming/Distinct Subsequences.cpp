/*115. Distinct Subsequences
Solved
Hard
Topics
Companies
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
*/

// Code:-
class Solution {
    public:
        //recurssion
        // int f(int i,int j,string s1, string s2){
        //     //base case
        //     //str2 match found
        //     if(j<0) return 1;
        //     //no atch found for s2 in s1 si ind is -ve
        //     if(i<0)return 0;
            
        //     //matching char found in s1 ,char of s2
        //     if(s1[i]==s2[j]){
        //         return (/*take*/f(i-1,j-1,s1,s2)+/*not take*/f(i-1,j,s1,s2));
        //     }
        //     //no matching char found in s1 ,char of s2
        //     else{
        //         return f(i-1,j,s1,s2);
        //     }
        // }
        // int numDistinct(string s, string t) {
        //     int n=s.size();
        //     int m=t.size();
        //     return f(n-1,m-1,s,t);
        // }
    
        // //memoization
        // int f(int i,int j,string s1, string s2,vector<vector<int>>&dp){
        //     //base case
        //     //str2 match found
        //     if(j<0) return 1;
        //     //no atch found for s2 in s1 si ind is -ve
        //     if(i<0)return 0;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     //matching char found in s1 ,char of s2
        //     if(s1[i]==s2[j]){
        //         return dp[i][j]=(/*take*/f(i-1,j-1,s1,s2,dp)+/*not take*/f(i-1,j,s1,s2,dp));
        //     }
        //     //no matching char found in s1 ,char of s2
        //     else{
        //         return dp[i][j]=f(i-1,j,s1,s2,dp);
        //     }
        // }
        // int numDistinct(string s, string t) {
        //     int n=s.size();
        //     int m=t.size();
        //     vector<vector<int>>dp(n,vector<int>(m,-1));
        //     return f(n-1,m-1,s,t,dp);
        // }
    
    
        //memoization for strs we consider 1based indexing
        // int f(int i,int j,string s1, string s2,vector<vector<int>>&dp){
        //     //base case
        //     //str2 match found
        //     if(j==0) return 1;
        //     //no atch found for s2 in s1 si ind is -ve
        //     if(i==0)return 0;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     //matching char found in s1 ,char of s2
        //     if(s1[i-1]==s2[j-1]){
        //         return dp[i][j]=(/*take*/f(i-1,j-1,s1,s2,dp)+/*not take*/f(i-1,j,s1,s2,dp));
        //     }
        //     //no matching char found in s1 ,char of s2
        //     else{
        //         return dp[i][j]=f(i-1,j,s1,s2,dp);
        //     }
        // }
        // int numDistinct(string s, string t) {
        //     int n=s.size();
        //     int m=t.size();
        //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //     return f(n,m,s,t,dp);
        // }
    
        // //tabulation
        // int numDistinct(string s, string t) {
        //     int n=s.size();
        //     int m=t.size();
        //     vector<vector<double>>dp(n+1,vector<double>(m+1,0));
    
        //     //base case
        //     //if(j==0) return 1;
        //     for(int i=0;i<=n;i++)dp[i][0]=1;
        //     //if(i==0) return 0;
        //     // for(int j=0;j<=m;j++)dp[0][j]=0; cau7se we already filled dp with 0
    
        //     //loops for changing vars
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             if(s[i-1]==t[j-1]){
        //                 dp[i][j]=(/*take*/dp[i-1][j-1]+/*not take*/dp[i-1][j]);
        //             }
        //             //no matching char found in s1 ,char of s2
        //             else{
        //                 dp[i][j]=dp[i-1][j];
        //             }                
        //         }
        //     }
    
        //     return (int)dp[n][m];
        // }
        //space optoimization using 2 1d arrays
        // int numDistinct(string s, string t) {
        //     int n=s.size();
        //     int m=t.size();
        //     vector<double>prev(m+1,0);
        //     vector<double>curr(m+1,0);
    
        //     //base case
        //     //if(j==0) return 1;
        //     prev[0]=curr[0]=1;
        //     //if(i==0) return 0;
        //     // for(int j=0;j<=m;j++)dp[0][j]=0; cau7se we already filled dp with 0
    
        //     //loops for changing vars
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             if(s[i-1]==t[j-1]){
        //                 curr[j]=(/*take*/prev[j-1]+/*not take*/prev[j]);
        //             }
        //             //no matching char found in s1 ,char of s2
        //             else{
        //                 curr[j]=prev[j];
        //             }                
        //         }
        //         prev=curr;
        //     }
    
        //     return (int)prev[m];
        // }
        //space optoimization using 1 1d array
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<double>prev(m+1,0);
            // vector<double>curr(m+1,0);
    
            //base case
            //if(j==0) return 1;
            prev[0]=1;
            //if(i==0) return 0;
            // for(int j=0;j<=m;j++)dp[0][j]=0; cau7se we already filled dp with 0
    
            //loops for changing vars
            for(int i=1;i<=n;i++){
                for(int j=m;j>=1;j--){
                    if(s[i-1]==t[j-1]){
                        prev[j]=(/*take*/prev[j-1]+/*not take*/prev[j]);
                    }               
                }
            }
    
            return (int)prev[m];
        }
    };
// prob link:-https://leetcode.com/problems/distinct-subsequences/