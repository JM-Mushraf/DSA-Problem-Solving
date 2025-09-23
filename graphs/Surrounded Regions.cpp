/*
130. Surrounded Regions
Solved
Medium
Topics
premium lock icon
Companies
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

// code:
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        //for first row and last row
        for(int j=0;j<m;j++){
            //for first Row
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,board,vis,delrow,delcol);
            }
            //for last Row
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,board,vis,delrow,delcol);
            }
        }

        //for first column and last column
        for(int i=0;i<n;i++){
            //for firstColumn
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,delrow,delcol);
            }
            //for last column
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        // return board;
    }
};

// link: https://leetcode.com/problems/surrounded-regions/