// https : // leetcode.com/problems/maximal-square/
#include <iostream>
using namespace std;
#include <vector>
// find the maximum square size for square for the given item
int solve(vector<vector<char>> matrix, int i, int j, int row, int column, int &mini)
{
    // Base case if reached to the end of the matrix
    if (i >= row || j >= column)
        return 0;

    int right = solve(matrix, i, j + 1, row, column, mini);
    int column = solve(matrix, i + 1, j + 1, row, column, mini);
    //
    int down = solve(matrix, i + 1, j, row, column, mini);
    if (matrix[i][j] == "1")
    {
        int ans = 1 + min(right, column, down);
        mini = max(mini, ans);
        return ans;
    }
}

int main()
{
    vector<vector<char>> matrix = {};
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int column = matrix[0].size();
    int mini = 0;
    int answer = solve(matrix, i, j, row, column, mini);

    return 0;
}
