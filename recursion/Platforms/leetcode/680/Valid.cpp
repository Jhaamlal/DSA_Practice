#include <iostream>

using namespace std;

class Solution
{
public:
    bool solve(string &s, int frontIndex, int lastIndex, int &count)
    {
        // edge case
        if (s.size() == 0)
            return true;
        // base case
        if (frontIndex >= lastIndex)
            return true;

        // once case
        char frontChar = s[frontIndex];
        char backChar = s[lastIndex];
        if (frontChar != backChar)
        {
            // if front character
            if (count == 0)
            {
                count++;
                bool include = solve(s, ++frontIndex, lastIndex, count);
                int front = frontIndex - 1;
                bool exclude = solve(s, front, --lastIndex, count);

                return include || exclude;
            }
            else
                return false;
        }

        return solve(s, ++frontIndex, --lastIndex, count);
    }
    bool validPalindrome(string s)
    {
        int frontIndex = 0;
        int lastIndex = s.size() - 1;
        int count = 0;
        return solve(s, frontIndex, lastIndex, count);
    }
};

int main()
{
    Solution solution;

    // // Test case 1: A palindrome string
    // string test1 = "madam";
    // if (solution.validPalindrome(test1))
    // {
    //     cout << "Test case 1 passed!" << endl;
    // }
    // else
    // {
    //     cout << "Test case 1 failed!" << endl;
    // }

    // // Test case 2: A non-palindrome string
    // string test2 = "hello";
    // if (!solution.validPalindrome(test2))
    // {
    //     cout << "Test case 2 passed!" << endl;
    // }
    // else
    // {
    //     cout << "Test case 2 failed!" << endl;
    // }

    // // Test case 3: A palindrome string with one character removed
    // string test3 = "racecar";
    // if (solution.validPalindrome(test3))
    // {
    //     cout << "Test case 3 passed!" << endl;
    // }
    // else
    // {
    //     cout << "Test case 3 failed!" << endl;
    // }

    // // Test case 4: An empty string
    // string test4 = "";
    // if (solution.validPalindrome(test4))
    // {
    //     cout << "Test case 4 passed!" << endl;
    // }
    // else
    // {
    //     cout << "Test case 4 failed!" << endl;
    // }

    // Test case 5: A string with one character
    string test5 = "abc";
    if (solution.validPalindrome(test5))
    {
        cout << "Test case 5 passed!" << endl;
    }
    else
    {
        cout << "Test case 5 failed!" << endl;
    }

    return 0;
}
