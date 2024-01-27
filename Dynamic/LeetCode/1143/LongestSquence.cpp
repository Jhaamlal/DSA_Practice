#include <iostream>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(string text1, string text2, int i, int j)
    {
        if (i >= text1.length())
            return 0;
        if (j >= text2.length())
            return 0;
        int ans = 0;
        if (text1[i] == text2[j])
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        else
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1), solveUsingRecursion(text1, text2, i + 1, j));
        return ans;
    }
    int solveUsingMemo(string text1, string text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= text1.length())
            return 0;
        if (j >= text2.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (text1[i] == text2[j])
            ans = 1 + solveUsingMemo(text1, text2, i + 1, j + 1, dp);
        else
            ans = 0 + max(solveUsingMemo(text1, text2, i, j + 1, dp), solveUsingMemo(text1, text2, i + 1, j, dp));
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveUsingTabulation(string text1, string text2)
    {
        // first analise the base case from there you need to choose the item that need
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = text1.length() - 1; i >= 0; i--)
        {
            // reverse the the recursion relation ,in the for loop
            // because in this you are going from bottom to UP
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                    ans = 1 + dp[i + 1][j + 1];
                else
                    ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = ans;
            }
        }
        // Where in the last value will be created
        return dp[0][0];
    };
    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        int ans = solveUsingMemo(text1, text2, i, j, dp);
        // int ans = solveUsingRecursion(text1, text2, i, j);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
