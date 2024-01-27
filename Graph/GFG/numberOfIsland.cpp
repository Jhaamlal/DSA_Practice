#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        // mark it visited
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        // push the node in queue
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        // until the queue becomes empty
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in the neighbours and mark them if its a land
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    // neighbour row and column is valid, and is an unvisited land
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {

        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>> vis(rowSize, vector<int>(colSize, 0));
        int count = 0;
        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
