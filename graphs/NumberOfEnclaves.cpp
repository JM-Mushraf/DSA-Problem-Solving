/*1020. Number of Enclaves
Solved
Medium
Topics
Companies
Hint
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.*/
// code:


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        // int vis[n][m]={0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //for rows
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                vis[0][j]=1;
            }
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        //for column
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+delRow[i];
                int nc=col+delCol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
                {
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};