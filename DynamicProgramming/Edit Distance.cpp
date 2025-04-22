/*
72. Edit Distance
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

// code:-
class Solution {
    public:
        //recurssion
        // int f(int i,int j,string s1, string s2){
        //     //base case
        //     if(i<0)return j+1;
        //     if(j<0)return i+1;
    
        //     //match found
        //     if(s1[i]==s2[j])return 0+f(i-1,j-1,s1,s2);
        //     else{
        //         // return min(1+f(i,j-1,s1,s2)/*insertion*/,
        //         // 1+f(i-1,j,s1,s2)/*deletion*/,
        //         // 1+f(i-1,j-1,s1,s2)/*replace)*/);
    
        //         return min(1+f(i,j-1,s1,s2),min(1+f(i-1,j,s1,s2),1+f(i-1,j-1,s1,s2)));
        //     }
        // }
        // int minDistance(string word1, string word2) {
        //     int n=word1.size();
        //     int m=word2.size();
        //     return f(n-1,m-1,word1, word2);
        // }
    
        //Memoization
        // int f(int i,int j,string s1, string s2,vector<vector<int>>&dp){
        //     //base case
        //     if(i<0)return j+1;
        //     if(j<0)return i+1;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     //match found
        //     if(s1[i]==s2[j])return dp[i][j]=0+f(i-1,j-1,s1,s2,dp);
        //     else{
        //         // return min(1+f(i,j-1,s1,s2)/*insertion*/,
        //         // 1+f(i-1,j,s1,s2)/*deletion*/,
        //         // 1+f(i-1,j-1,s1,s2)/*replace)*/);
    
        //         return dp[i][j]=min(1+f(i,j-1,s1,s2,dp),min(1+f(i-1,j,s1,s2,dp),1+f(i-1,j-1,s1,s2,dp)));
        //     }
        // }
        // int minDistance(string word1, string word2) {
        //     int n=word1.size();
        //     int m=word2.size();
        //     vector<vector<int>>dp(n,vector<int>(m,-1));
        //     return f(n-1,m-1,word1, word2,dp);
        // }
    
        // int f(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){
        //     //base case
        //     if(i==0)return j;
        //     if(j==0)return i;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     //match found
        //     if(s1[i-1]==s2[j-1])return dp[i][j]=0+f(i-1,j-1,s1,s2,dp);
        //     else{
        //         // return min(1+f(i,j-1,s1,s2)/*insertion*/,
        //         // 1+f(i-1,j,s1,s2)/*deletion*/,
        //         // 1+f(i-1,j-1,s1,s2)/*replace)*/);
    
        //         return dp[i][j]=min(1+f(i,j-1,s1,s2,dp),min(1+f(i-1,j,s1,s2,dp),1+f(i-1,j-1,s1,s2,dp)));
        //     }
        // }
        // int minDistance(string word1, string word2) {
        //     int n=word1.size();
        //     int m=word2.size();
        //     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //     return f(n,m,word1, word2,dp);
        // }
    
        // //tabulation
        // int minDistance(string word1, string word2) {
        //     int n=word1.size();
        //     int m=word2.size();
        //     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
        //     for(int j=1;j<=m;j++)dp[0][j]=j;
        //     for(int i=1;i<=n;i++)dp[i][0]=i;
    
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             if(word1[i-1]==word2[j-1])dp[i][j]=0+dp[i-1][j-1];
        //             else{
        //                 // return min(1+f(i,j-1,s1,s2)/*insertion*/,
        //                 // 1+f(i-1,j,s1,s2)/*deletion*/,
        //                 // 1+f(i-1,j-1,s1,s2)/*replace)*/);
    
        //                 dp[i][j]=min(1+dp[i][j-1],min(1+dp[i-1][j],1+dp[i-1][j-1]));
        //             }
        //         }
        //     }
        //     return dp[n][m];
        // }
    
        //space optimization using 2 1d array
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<int>prev(m+1,0);
            vector<int>curr(m+1,0);
    
            for(int j=1;j<=m;j++)prev[j]=j;
            // for(int i=1;i<=n;i++)curr[0]=i;
    
            for(int i=1;i<=n;i++){
                curr[0]=i;
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1])curr[j]=0+prev[j-1];
                    else{
                        // return min(1+f(i,j-1,s1,s2)/*insertion*/,
                        // 1+f(i-1,j,s1,s2)/*deletion*/,
                        // 1+f(i-1,j-1,s1,s2)/*replace)*/);
    
                        curr[j]=min(1+curr[j-1],min(1+prev[j],1+prev[j-1]));
                    }
                }
                prev=curr;
            }
            return prev[m];
        }
    };

// prob link:-https://leetcode.com/problems/edit-distance/