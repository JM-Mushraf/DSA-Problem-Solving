/*Problem statement
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.



You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.



Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 15
7 2 4
5 10 20


Expected Answer:
21


Output on console:
21*/

// code:-
#include <bits/stdc++.h> 
//Recurssion
// int f(int ind,int bagwt,vector<int> &profit, vector<int> &weight){
//     if(ind==0){
//         return (bagwt/weight[0])*profit[0];
//     }

//     int notTake=0+f(ind-1,bagwt,profit,weight);
//     int take=INT_MIN;
//     if(weight[ind]<=bagwt){
//         take=profit[ind]+f(ind,bagwt-weight[ind],profit,weight);
//     }
//     return max(take,notTake);
// }
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     return f(n-1,w,profit,weight);
// }

//memoization
// int f(int ind,int bagwt,vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
//     if(ind==0){
//         return (bagwt/weight[0])*profit[0];
//     }
//     if(dp[ind][bagwt]!=-1)return dp[ind][bagwt];
//     int notTake=0+f(ind-1,bagwt,profit,weight,dp);
//     int take=INT_MIN;
//     if(weight[ind]<=bagwt){
//         take=profit[ind]+f(ind,bagwt-weight[ind],profit,weight,dp);
//     }
//     return dp[ind][bagwt]=max(take,notTake);
// }
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     return f(n-1,w,profit,weight,dp);
// }


// Tabulation
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     vector<vector<int>>dp(n,vector<int>(w+1,0));

//     //baseCase
//     for(int i=0;i<=w;i++){
//         dp[0][i]=((i/weight[0])*profit[0]);
//     }

//     //loops for changing vars
//     for(int ind=1;ind<n;ind++){
//         for(int wt=0;wt<=w;wt++){
//             int notTake=0+dp[ind-1][wt];
//             int take=INT_MIN;
//             if(weight[ind]<=wt){
//                 take=profit[ind]+dp[ind][wt-weight[ind]];
//             }
//             dp[ind][wt]=max(take,notTake);        
//         }
//     }
//     return dp[n-1][w];
// }


// 2 array space optimization
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     vector<int>prev(w+1,0);
//     vector<int>curr(w+1,0);

//     //baseCase
//     for(int i=0;i<=w;i++){
//         prev[i]=((i/weight[0])*profit[0]);
//     }

//     //loops for changing vars
//     for(int ind=1;ind<n;ind++){
//         for(int wt=0;wt<=w;wt++){
//             int notTake=0+prev[wt];
//             int take=INT_MIN;
//             if(weight[ind]<=wt){
//                 take=profit[ind]+curr[wt-weight[ind]];
//             }
//             curr[wt]=max(take,notTake);        
//         }
//         prev=curr;
//     }
//     return prev[w];
// }


// 1 array space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1,0);

    //baseCase
    for(int i=0;i<=w;i++){
        prev[i]=((i/weight[0])*profit[0]);
    }

    //loops for changing vars
    for(int ind=1;ind<n;ind++){
        for(int wt=0;wt<=w;wt++){
            int notTake=0+prev[wt];
            int take=INT_MIN;
            if(weight[ind]<=wt){
                take=profit[ind]+prev[wt-weight[ind]];
            }
            prev[wt]=max(take,notTake);        
        }
    }
    return prev[w];
}

// code link:-https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?leftPanelTabValue=PROBLEM