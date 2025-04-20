/*Problem statement
You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.



A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.



Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.

Output: 3

Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
wasdijkl
wsdjkl
Sample Output 1:
 3*/

//  code:-
//tabulation
// #include <bits/stdc++.h> 
// using namespace std;
// int lcs(string &s1, string &s2){
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//                 ans=max(ans,dp[i][j]);
//             }
//             else {
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return ans;
// }

//space optimization
#include <bits/stdc++.h> 
using namespace std;
int lcs(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    vector<int>prev(m+1,0),curr(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else {
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return ans;
}

// prob link:-
//tabulation
// #include <bits/stdc++.h> 
// using namespace std;
// int lcs(string &s1, string &s2){
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//                 ans=max(ans,dp[i][j]);
//             }
//             else {
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return ans;
// }

//space optimization
#include <bits/stdc++.h> 
using namespace std;
int lcs(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    vector<int>prev(m+1,0),curr(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else {
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return ans;
}