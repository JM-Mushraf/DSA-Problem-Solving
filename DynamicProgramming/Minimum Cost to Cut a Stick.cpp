/*Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.*/

// code:-
class Solution {
    public:
        //Recurssion
        // int f(int i,int j,vector<int>&cuts){
        //     //base case
        //     if(i>j)return 0;
        //     int mini=1e9;
        //     for(int cut=i;cut<=j;cut++){
        //         int cost=(cuts[j+1]-cuts[i-1])+f(i,cut-1,cuts)+f(cut+1,j,cuts);
        //         mini=min(mini,cost);
        //     }
        //     return mini;
        // }
        // int minCost(int n, vector<int>& cuts) {
        //     int c=cuts.size();
        //     cuts.push_back(n);
        //     cuts.insert(cuts.begin(),0);
        //     sort(cuts.begin(),cuts.end());
        //     return f(1,c,cuts);
        // }
    
        //memoization
        // int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        //     //base case
        //     if(i>j)return 0;
        //     int mini=1e9;
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     for(int cut=i;cut<=j;cut++){
        //         int cost=(cuts[j+1]-cuts[i-1])+f(i,cut-1,cuts,dp)+f(cut+1,j,cuts,dp);
        //         mini=min(mini,cost);
        //     }
        //     return dp[i][j]=mini;
        // }
        // int minCost(int n, vector<int>& cuts) {
        //     int c=cuts.size();
        //     cuts.push_back(n);
        //     cuts.insert(cuts.begin(),0);
        //     sort(cuts.begin(),cuts.end());
    
        //     vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        //     return f(1,c,cuts,dp);
        // }
    
        //tabulation
        int minCost(int n, vector<int>& cuts) {
            int c=cuts.size();
            cuts.push_back(n);
            cuts.insert(cuts.begin(),0);
            sort(cuts.begin(),cuts.end());
    
            vector<vector<int>>dp(c+2,vector<int>(c+2,0));
    
            for(int i=c;i>=1;i--){
                for(int j=1;j<=c;j++){
                    if(i>j)continue;
                    int mini=1e9;
                    for(int cut=i;cut<=j;cut++){
                        int cost=(cuts[j+1]-cuts[i-1])+dp[i][cut-1]+dp[cut+1][j];
                        mini=min(mini,cost);
                    }
                    dp[i][j]=mini;
                }
            }
            return dp[1][c];
        }
    };

    // prob link:https://leetcode.com/problems/minimum-cost-to-cut-a-stick/