
//Introduction to Dynamic Programming | Memoization | Tabulation | Space Optimization Techniques
#include<iostream>
#include<vector>
using namespace std;
int f(int n,vector<int>&dp){
    if(n<=1)
      return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    // vector<int>dp(n+1,-1);
    // int sol=f(n,dp);
    // cout<<sol<<endl;

    //Tabulation
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<prev;
    return 0;
}