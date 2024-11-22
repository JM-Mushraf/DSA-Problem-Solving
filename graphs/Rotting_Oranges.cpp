#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Function to check if a cell is valid and contains a fresh orange (1)
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1)
            return true;
        return false;
    }

    // Function to calculate the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;  // Tracks the time (minutes) elapsed
        bool hasFresh = false;  // Tracks if fresh oranges are still present

        // Flood-fill logic similar to the flood fill function
        while (true) {
            bool changed = false;
            vector<pair<int, int>> toRot;  // To store rotten oranges in this iteration

            // Traverse the grid to find rotten oranges and rot adjacent fresh oranges
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        // Check all 4 directions (up, down, left, right)
                        if (isValid(grid, i + 1, j, n, m)) toRot.push_back({i + 1, j});
                        if (isValid(grid, i - 1, j, n, m)) toRot.push_back({i - 1, j});
                        if (isValid(grid, i, j + 1, n, m)) toRot.push_back({i, j + 1});
                        if (isValid(grid, i, j - 1, n, m)) toRot.push_back({i, j - 1});
                    }
                }
            }

            // If no new oranges were rotted this round, we are done
            if (toRot.empty()) break;

            // Mark the fresh oranges as rotten
            for (auto cell : toRot) {
                grid[cell.first][cell.second] = 2;
                changed = true;
            }

            // Increment time if any oranges were rotted in this iteration
            if (changed) time++;
        }

        // After flood-fill-like traversal, check if any fresh oranges are left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // Return -1 if any fresh orange remains
                }
            }
        }

        return time;
    }
};

int main()
{
    return 0;
}