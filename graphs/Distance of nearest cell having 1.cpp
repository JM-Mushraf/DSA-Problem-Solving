/*
istance of nearest cell having 1
Difficulty: MediumAccuracy: 47.7%Submissions: 105K+Points: 4Average Time: 20m
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

Examples

Input: 
grid = [[0,1,1,0], [1,1,0,0], [0,0,1,1]]
Output: 
[[1,0,0,1], [0,0,1,1], [1,1,0,0]]
Explanation: 
The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
- 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.
*/

// code:
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            
            int step=q.front().second;
            q.pop();
            dis[r][c]=step;
            
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
        return dis;
    }
};

// link:https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1