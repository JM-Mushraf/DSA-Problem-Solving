/*
 Array partition with minimum difference
Hard
120/120
Average time to solve is 10m
397 upvotes
Asked in companies
Problem statement
You are given an array 'arr' containing 'n' non-negative integers.



Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.



You just need to find the minimum absolute difference considering any valid division of the array elements.



Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Example:
Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
1 2 3 4
Sample Output 1:
0
Explanation for sample input 1:
We can partition the given array into {2,3} and {1,4}.
This will give us the minimum possible absolute difference i.e. (5 - 5 = 0) in this case.
Sample Input 2:
3
8 6 5
Sample Output 2:
3
Explanation for sample input 2:
We can partition the given array into {8} and {6,5}. 
This will give us the minimum possible absolute difference i.e. (11 - 8 = 3).
Expected time complexity:
The expected time complexity is O(n * 𝚺 'arr'[i]), where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.
Constraints:
1 <= 'n' <= 10^3
0 <= 'arr'[i] <= 10^3
0 <= 𝚺 'arr'[i] <= 10^4, 

where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.

Time Limit: 1sec
*/


// code:
 bool subsetSumToK(int n, int k, vector<int> &arr,vector<vector<bool>> &dp) {
        // vector<vector<bool>>dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++)  dp[i][0]=true;
        if(arr[0]<=k) dp[0][arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notTake=dp[ind-1][target];
                bool take=false;
                if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
                dp[ind][target]=take | notTake;
            }
        }
        return dp[n-1][k];
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	    // int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++) totalsum+=arr[i];
        vector<vector<bool>>dp(n,vector<bool>(totalsum+1,false));
        int mini=1e9;
        subsetSumToK(n,totalsum,arr,dp);
        for(int i=0;i<=(totalsum/2);i++){
            if(dp[n-1][i]){
                int s1=i;
                int s2=totalsum-i;
                mini=min(mini,abs(s2-s1));
            }
        }
        return mini;
}

