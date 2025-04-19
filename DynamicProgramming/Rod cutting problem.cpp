/*Problem statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24*/

// Code:-

//Recurssion
// int f(int ind,int N,vector<int> &price){
// 	//base case
// 	if(ind==0){
// 		return N*price[0];
// 	}
	
// 	int notTake=0+f(ind-1,N,price);
// 	int take=INT_MIN;
// 	int rodlen=ind+1;
// 	if(rodlen<=N)take=price[ind]+f(ind,N-rodlen,price);

// 	return max(take,notTake);
// }

//Memoization
// int f(int ind,int N,vector<int> &price,vector<vector<int>>&dp){
// 	//base case
// 	if(ind==0){
// 		return N*price[0];
// 	}
// 	if(dp[ind][N]!=-1)return dp[ind][N];
// 	int notTake=0+f(ind-1,N,price,dp);
// 	int take=INT_MIN;
// 	int rodlen=ind+1;
// 	if(rodlen<=N)take=price[ind]+f(ind,N-rodlen,price,dp);

// 	return dp[ind][N]=max(take,notTake);
// }

// int cutRod(vector<int> &price, int n)
// {
// 	int ind=price.size();
// 	vector<vector<int>>dp(ind,vector<int>(n+1,-1));
// 	return f(ind-1,n,price,dp);
// }

//Tabulation
// int cutRod(vector<int> &price, int n)
// {
// 	int index=price.size();
// 	vector<vector<int>>dp(index,vector<int>(n+1,0));

// 	//base case
// 	for(int i=0;i<=n;i++)dp[0][i]=i*price[0];

// 	//loops for changing vars
// 	for(int ind=1;ind<index;ind++){
// 		for(int N=0;N<=n;N++){
// 			int notTake=0+dp[ind-1][N];
// 			int take=INT_MIN;
// 			int rodlen=ind+1;
// 			if(rodlen<=N)take=price[ind]+dp[ind][N-rodlen];

// 			dp[ind][N]=max(take,notTake);	
// 		}
// 	}
// 	return dp[index-1][n];
// }

// //space optimization usig 2 1D arrays
// int cutRod(vector<int> &price, int n)
// {
// 	int index=price.size();
// 	vector<int>prev(n+1,0);
// 	vector<int>curr(n+1,0);

// 	//base case
// 	for(int i=0;i<=n;i++)prev[i]=i*price[0];

// 	//loops for changing vars
// 	for(int ind=1;ind<index;ind++){
// 		for(int N=0;N<=n;N++){
// 			int notTake=0+prev[N];
// 			int take=INT_MIN;
// 			int rodlen=ind+1;
// 			if(rodlen<=N)take=price[ind]+curr[N-rodlen];

// 			curr[N]=max(take,notTake);	
// 		}
// 		prev=curr;
// 	}
// 	return prev[n];
// }

//space optimization usig 1 1D arrays
int cutRod(vector<int> &price, int n)
{
	int index=price.size();
	vector<int>prev(n+1,0);

	//base case
	for(int i=0;i<=n;i++)prev[i]=i*price[0];

	//loops for changing vars
	for(int ind=1;ind<index;ind++){
		for(int N=0;N<=n;N++){
			int notTake=0+prev[N];
			int take=INT_MIN;
			int rodlen=ind+1;
			if(rodlen<=N)take=price[ind]+prev[N-rodlen];

			prev[N]=max(take,notTake);	
		}
	}
	return prev[n];
}

// prob link:-https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM