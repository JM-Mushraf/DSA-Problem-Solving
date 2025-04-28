/*Problem statement
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
70
8000
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.

If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.

Thus a minimum number of multiplications required is 8000.*/

// code:-
#include <bits/stdc++.h> 

//recurssion
// int f(int i,int j,vector<int>&arr){
//     if(i==j)return 0;
//     int mini=1e9;
//     for(int k=i;k<j;k++){
//         int steps=(arr[i-1]*arr[k]*arr[j])+f(i,k,arr)+f(k+1,j,arr);
//         if(mini>steps)mini=steps;
//     }
//     return mini;
// }
// int matrixMultiplication(vector<int> &arr, int N)
// {
//     return f(1,N-1,arr);
// }

//memoization
// int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
//     if(i==j)return 0;
//     int mini=1e9;
//     if(dp[i][j]!=-1)return dp[i][j];
//     for(int k=i;k<j;k++){
//         int steps=(arr[i-1]*arr[k]*arr[j])+f(i,k,arr,dp)+f(k+1,j,arr,dp);
//         if(mini>steps)mini=steps;
//     }
//     return dp[i][j]=mini;
// }
// int matrixMultiplication(vector<int> &arr, int N)
// {
//     vector<vector<int>>dp(N,vector<int>(N,-1));
//     return f(1,N-1,arr,dp);
// }


//tabulation
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N));

    //base case
    for(int i=0;i<N;i++){
        dp[i][i]=0;
    }
    //loops for changing variables
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                if(mini>steps)mini=steps;
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}
// prob link:-https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344