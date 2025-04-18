/*
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3
*/

// code:-
#include <bits/stdc++.h> 
//Recurssion
// int f(int ind,int maxWeight,vector<int> wt,vector<int> val){
// 	if(ind==0){
// 		if(wt[0]<=maxWeight)return val[0];
// 		return 0;
// 	}
// 	int notTake=0+f(ind-1,maxWeight,wt,val);
// 	int take=INT_MIN;
// 	if(wt[ind]<=maxWeight){
// 		take=val[ind]+f(ind-1,maxWeight-wt[ind],wt,val);
// 	}
// 	return max(take,notTake);
// }

//Memoization
// int f(int ind,int maxWeight,vector<int> wt,vector<int> val,vector<vector<int>>&dp){
// 	if(ind==0){
// 		if(wt[0]<=maxWeight)return val[0];
// 		return 0;
// 	}
// 	if(dp[ind][maxWeight]!=-1)return dp[ind][maxWeight];
// 	int notTake=0+f(ind-1,maxWeight,wt,val,dp);
// 	int take=INT_MIN;
// 	if(wt[ind]<=maxWeight){
// 		take=val[ind]+f(ind-1,maxWeight-wt[ind],wt,val,dp);
// 	}
// 	return dp[ind][maxWeight]=max(take,notTake);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// int n=weight.size();
// 	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
// 	return f(n-1,maxWeight,weight,value,dp);
// }

//Tabulation

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

// 	//baseCase
// 	for(int i=0;i<=maxWeight;i++){
//         if(weight[0]<=i){
//             dp[0][i]=value[0];
//         }
//     }

// 	//nested loops for changing vars
// 	for(int ind=1;ind<n;ind++){
// 		for(int wt=0;wt<=maxWeight;wt++){
// 			int notTake=0+dp[ind-1][wt];
// 			int take=INT_MIN;
// 			if(weight[ind]<=wt){
// 				take=value[ind]+dp[ind-1][wt-weight[ind]];
// 			}
// 			dp[ind][wt]=max(take,notTake);
// 		}
// 	}
// 	return dp[n-1][maxWeight];
// }

//space optimization using two 1D arrays
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<int>prev(maxWeight+1,0);
// 	vector<int>curr(maxWeight+1,0);

// 	//baseCase
// 	for(int i=0;i<=maxWeight;i++){
//         if(weight[0]<=i){
//             prev[i]=value[0];
//         }
//     }

// 	//nested loops for changing vars
// 	for(int ind=1;ind<n;ind++){
// 		for(int wt=0;wt<=maxWeight;wt++){
// 			int notTake=0+prev[wt];
// 			int take=INT_MIN;
// 			if(weight[ind]<=wt){
// 				take=value[ind]+prev[wt-weight[ind]];
// 			}
// 			curr[wt]=max(take,notTake);
// 		}
// 		prev=curr;
// 	}
// 	return prev[maxWeight];
// }

//space optimization using one 1D arrays
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0);

	//baseCase
	for(int i=0;i<=maxWeight;i++){
        if(weight[0]<=i){
            prev[i]=value[0];
        }
    }

	//nested loops for changing vars
	for(int ind=1;ind<n;ind++){
		for(int wt=maxWeight;wt>=0;wt--){
			int notTake=0+prev[wt];
			int take=INT_MIN;
			if(weight[ind]<=wt){
				take=value[ind]+prev[wt-weight[ind]];
			}
			prev[wt]=max(take,notTake);
		}
	}
	return prev[maxWeight];
}