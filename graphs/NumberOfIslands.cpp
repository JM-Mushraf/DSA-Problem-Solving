/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

lass Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
        {
            return true;
        }
        return false;
    }
    void numIslandsRec(int i,int j,int n,int m,vector<vector<char>>& grid){
        grid[i][j]='0';
        if(isValid(i+1,j,n,m,grid))
            numIslandsRec(i+1,j,n,m,grid);
        if(isValid(i-1,j,n,m,grid))
            numIslandsRec(i-1,j,n,m,grid);
        if(isValid(i,j+1,n,m,grid))
            numIslandsRec(i,j+1,n,m,grid);
        if(isValid(i,j-1,n,m,grid))
            numIslandsRec(i,j-1,n,m,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    numIslandsRec(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};