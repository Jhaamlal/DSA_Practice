#include <iostream>
// inclusion and exclusion class why ?
/*
The thing is for loop
*/
using namespace std;
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        int i = 1;
        int ans = INT_MAX;

        while (i <= sqrt(n))
        {
            int perfectSqr = i * i;
            int numbSqr = 1 + solve(n - perfectSqr, dp);
            if (numbSqr < ans)
                ans = numbSqr;
            i++;
        }
        dp[i] = ans;
        return ans;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp) - 1;
    }
};

int main()
{
    Solution solution;

    // Test case 1:
    int n1 = 12;
    int result1 = solution.numSquares(n1);
    cout << "Test case 1: " << (result1 == 3 ? "Passed" : "Failed") << endl;

    // // Test case 2:
    // int n2 = 13;
    // int result2 = solution.numSquares(n2);
    // cout << "Test case 2: " << (result2 == 2 ? "Passed" : "Failed") << endl;

    // // Test case 3:
    // int n3 = 0;
    // int result3 = solution.numSquares(n3);
    // cout << "Test case 3: " << (result3 == 0 ? "Passed" : "Failed") << endl;

    return 0;
}
