// https://leetcode.com/problems/add-strings/submissions/1097049223
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int solve(string num, int index, int &n)
    {
        // edge conditions
        if (num.size() == 0)
            return -1;
        // base condition
        // Base condition should be always at the top
        if (num.size() == index + 1)
        {
            char ch = num[index];
            int num1 = ch - '0';
            return num1;
        }
        char currentChar = num[index];
        int currentNum = currentChar - '0';
        // recursive call
        int ans = solve(num, ++index, n);
        n = n * 10;
        int newAns = ans + currentNum * n;
        return newAns;

        // return call
    }
    string addStrings(string num1, string num2)
    {
        int index = 0;
        int n1 = 1;
        int n2 = 1;
        int ans1 = solve(num1, index, n1);
        int ans2 = solve(num2, index, n2);
        cout << ans1 << " " << ans2 << endl;
        int summedAnswer = ans1 + ans2;
        return to_string(summedAnswer);
    }
};

int main()
{
    Solution solution;

    // Test case 1:
    string num1 = "123";
    string num2 = "456";
    string result = solution.addStrings(num1, num2);
    cout << "Test case 1 result: " << result << endl; // Expected output: "579"

    // Test case 2:
    num1 = "999";
    num2 = "1";
    result = solution.addStrings(num1, num2);
    cout << "Test case 2 result: " << result << endl; // Expected output: "1000"

    // Test case 3:
    num1 = "0";
    num2 = "0";
    result = solution.addStrings(num1, num2);
    cout << "Test case 3 result: " << result << endl; // Expected output: "0"

    return 0;
}
