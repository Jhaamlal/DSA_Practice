// https: // www.geeksforgeeks.org/problems/painting-the-fence3727/1
#include <iostream>
using namespace std;

class Solution
{
public:
    long long solveWithRecursion(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * (k - 1) + k;

        int ans = solveWithRecursion(n - 1, k) + solveWithRecursion(n - 2, k) * (k - 1);
        return ans;
    }
    long long solveWithMem(int n, int k, vector<int> &dp)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * (k - 1) + k;

        if (dp[n] != k)
            return dp[n];

        dp[n] = solveWithRecursion(n - 1, k) + solveWithRecursion(n - 2, k) * (k - 1);
        return dp[0];
    }
    long long countWays(int n, int k)
    {

        vector<int> dp(n + 1, -1);
        dp[1] = k;
        dp[2] = k + k * (k + 1);
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
        }
        return dp[n];

        solveWithMem(n, k, dp);
    }
};

int main(int argc, char const *argv[])
{
    //    step of memoization
    // 1) Create dp array
    // 2) Create before the recursion is already present or not
    // 3) Make sure what is needed

    return 0;
}
