/*1463. Cherry Pickup II
Solved
Hard
Topics
Companies
Hint
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.*/

// Code
class Solution {
    public:
        // int f(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid){
        //     if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e9;
        //     if(i==r-1){
        //         if(j1==j2) return grid[i][j1];
        //         else return grid[i][j1]+grid[i][j2];
        //     }
            
        //     // explore all the paths of alice and bob simultaneously
        //     int maxi=-1e9;
        //     for(int dj1=-1;dj1<=1;dj1++){
        //         for(int dj2=-1;dj2<=1;dj2++){
        //             int val=0;
        //             if(j1==j2) val=grid[i][j1];
        //             else val=grid[i][j1]+grid[i][j2];
        //             val+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
        //             maxi=max(maxi,val);
        //         }
        //     }
        //     return maxi;
        // }
        // int cherryPickup(vector<vector<int>>& grid) {
        //     int r=grid.size();
        //     int c=grid[0].size();
        //     return f(0,0,c-1,r,c,grid);
        // }
    
        //Memoization
        // int f(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        //     if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e9;
        //     if(i==r-1){
        //         if(j1==j2) return grid[i][j1];
        //         else return grid[i][j1]+grid[i][j2];
        //     }
        //     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        //     // explore all the paths of alice and bob simultaneously
        //     int maxi=-1e9;
        //     for(int dj1=-1;dj1<=1;dj1++){
        //         for(int dj2=-1;dj2<=1;dj2++){
        //             int val=0;
        //             if(j1==j2) val=grid[i][j1];
        //             else val=grid[i][j1]+grid[i][j2];
        //             val+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
        //             maxi=max(maxi,val);
        //         }
        //     }
        //     return dp[i][j1][j2]=maxi;
        // }
        // int cherryPickup(vector<vector<int>>& grid) {
        //     int r=grid.size();
        //     int c=grid[0].size();
        //     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        //     return f(0,0,c-1,r,c,grid,dp);
        // }
    
        //Tabulation
        // int cherryPickup(vector<vector<int>>& grid) {
        //     int n=grid.size();
        //     int m=grid[0].size();
        //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
            
        //     for(int j1=0;j1<m;j1++){
        //         for(int j2=0;j2<m;j2++){
        //             if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
        //             else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        //         }
        //     }
        //     for(int i=n-2;i>=0;i--){
        //         for(int j1=0;j1<m;j1++){
        //             for(int j2=0;j2<m;j2++){
        //                 int maxi=-1e9;
        //                 for(int dj1=-1;dj1<=1;dj1++){
        //                     for(int dj2=-1;dj2<=1;dj2++){
        //                         int val=0;
        //                         if(j1==j2) val=grid[i][j1];
        //                         else val=grid[i][j1]+grid[i][j2];
        //                         int nj1 = j1 + dj1;
        //                         int nj2 = j2 + dj2;
        //                         if(nj1>=0 && nj1<m && nj2>=0 && nj2<m)
        //                             val+=dp[i+1][nj1][nj2];
        //                         else
        //                             val = -1e9;
        //                         maxi=max(maxi,val);
        //                     }
        //                 }
        //                 dp[i][j1][j2]=maxi;
        //             }
        //         }
        //     }
        //     return dp[0][0][m-1];
        // }
    
        //spaceoptimization
        int cherryPickup(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
            vector<vector<int>>front(m,vector<int>(m,0));
             vector<vector<int>>curr(m,vector<int>(m,0));
            // int front[m][m];
            // int curr[m][m];
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    if(j1==j2) front[j1][j2]=grid[n-1][j1];
                    else front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
            for(int i=n-2;i>=0;i--){
                for(int j1=0;j1<m;j1++){
                    for(int j2=0;j2<m;j2++){
                        int maxi=-1e9;
                        for(int dj1=-1;dj1<=1;dj1++){
                            for(int dj2=-1;dj2<=1;dj2++){
                                int val=0;
                                if(j1==j2) val=grid[i][j1];
                                else val=grid[i][j1]+grid[i][j2];
                                int nj1 = j1 + dj1;
                                int nj2 = j2 + dj2;
                                if(nj1>=0 && nj1<m && nj2>=0 && nj2<m)
                                    val+=front[nj1][nj2];
                                else
                                    val = -1e9;
                                maxi=max(maxi,val);
                            }
                        }
                        curr[j1][j2]=maxi;
                    }
                }
                front=curr;
            }
            return front[0][m-1];
        }
    };