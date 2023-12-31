#include <iostream>
#include <vector>
using namespace std;
/*
aaabbbabbbb
[3,5,10,7,5,3,5,5,4,8,1]
*/

class Solution1
{
public:
    int minCost(string colors, vector<int> &neededTime, int index = 0, char lastColor = '\0')
    {
        if (index == colors.size())
            return 0;
        int ans = 1e9 + 7;
        for (int i = index; i < colors.size() && colors[i] == colors[index]; i++)
        {
            if (colors[i] != lastColor)
            {
                ans = min(ans, neededTime[i] + minCost(colors, neededTime, i + 1, colors[i]));
            }
        }
        return ans;
    }
};

class Solution
{
public:
        void solve(string colors, vector<int> &neededTime, int &index, int &ans)
    {
        if (neededTime.size() == 0)
            return;

        // base case
        if (index > neededTime.size())
            return;

        if ((index + 1) < neededTime.size() && colors[index] == colors[index + 1])
        {
            int ans1 = neededTime[index];
            int ans2 = neededTime[index + 1];
            ans = min(min(ans1, ans2), ans);
        }
        index++;
        solve(colors, neededTime, index, ans);
    }
    int minCost(string colors, vector<int> &neededTime)
    {
        int index = 0;
        int ans = 400000000;
        solve(colors, neededTime, index, ans);
        return ans;
    }
};
int main()
{
    Solution solution;

    /*
        // Test case 1
        string colors1 = "aabaa";
        vector<int> neededTime1 = {1, 2, 3, 4, 1};
        int result1 = solution.minCost(colors1, neededTime1);
        cout << "Test case 1 result: " << result1 << endl; // Expected output: ?

        // Test case 2
        string colors2 = "abc";
        vector<int> neededTime2 = {1, 2, 3};
        int result2 = solution.minCost(colors2, neededTime2);
        cout << "Test case 2 result: " << result2 << endl; // Expected output: ?

        // Test case 3
        string colors3 = "aaa";
        vector<int> neededTime3 = {1, 2, 3};
        int result3 = solution.minCost(colors3, neededTime3);
        cout << "Test case 3 result: " << result3 << endl; // Expected output: ?
    */
    // Test case 4
    string colors3 = "aaabbbabbbb";
    vector<int> neededTime3 = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
    int result3 = solution.minCost(colors3, neededTime3);
    cout << "Test case 3 result: " << result3 << endl; // Expected output: ?

    return 0;
}
