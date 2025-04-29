/*132. Palindrome Partitioning II
Solved
Hard
Topics
Companies
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.*/

// code:-
class Solution
{
public:
    // recurssion
    //  bool isPalindrome(int i,int j,string &s){
    //      while(i<j){
    //          if(s[i]!=s[j])return false;
    //          i++;
    //          j--;
    //      }
    //      return true;
    //  }
    //  int f(int i,string &s,int n){
    //      if(i==n)return 0;

    //     int mini=INT_MAX;
    //     for(int j=i;j<n;j++){
    //         if(isPalindrome(i,j,s)){
    //             int cost=1+f(j+1,s,n);
    //             mini=min(mini,cost);
    //         }
    //     }
    //     return mini;
    // }
    // int minCut(string s) {
    //     int n=s.size();
    //     return f(0,s,n)-1;//-1 cause when it reaches n it is counting partition there also so -1
    // }

    // memoization
    //  bool isPalindrome(int i,int j,string &s){
    //      while(i<j){
    //          if(s[i]!=s[j])return false;
    //          i++;
    //          j--;
    //      }
    //      return true;
    //  }
    //  int f(int i,string &s,int n,vector<int>&dp){
    //      if(i==n)return 0;
    //      if(dp[i]!=-1)return dp[i];
    //      int mini=INT_MAX;
    //      for(int j=i;j<n;j++){
    //          if(isPalindrome(i,j,s)){
    //              int cost=1+f(j+1,s,n,dp);
    //              mini=min(mini,cost);
    //          }
    //      }
    //      return dp[i]=mini;
    //  }
    //  int minCut(string s) {
    //      int n=s.size();
    //      vector<int>dp(n,-1);
    //      return f(0,s,n,dp)-1;//-1 cause when it reaches n it is counting partition there also so -1
    //  }

    // Tabulation
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // no need of base case cause entire array initilized with 0
        //  dp[n]=0;
        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1; //-1 cause when it reaches n it is counting partition there also so -1
    }
};

// prob link:-https://leetcode.com/problems/palindrome-partitioning-ii/