#include <iostream>
#include <vector>
using namespace std;

/*
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
possible solution
1) using stack
2) Using recursion
3) Loop with for or while

*/
class Solution
{
public:
    vector<char> solve(vector<char> &s, int index, int arraySize)
    {
        vector<char> ans;
        if (arraySize == -1)
            return ans;

        // base case
        if (index == arraySize)
        {
            ans.push_back(s[index]);
            return ans;
        }

        // index
        char currentChar = s[index];

        vector<char> ans2 = solve(s, ++index, arraySize);
        ans2.push_back(currentChar);
        return ans2;
    }
    void reverseString(vector<char> &s)
    {
        // int index = 0;
        // int arraySize = s.size() - 1;
        // s = solve(s, index, arraySize);
        s = solve(s, 0, s.size() - 1);
    }
};

int main()
{
    Solution solution;

    // Test case 1: Empty vector
    vector<char> test1 = {};
    solution.reverseString(test1);
    // Expected output: {}

    // Test case 2: Single element vector
    vector<char> test2 = {'a'};
    solution.reverseString(test2);
    // Expected output: {'a'}

    // Test case 3: Multiple elements vector
    vector<char> test3 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(test3);
    // Expected output: {'o', 'l', 'l', 'e', 'h'}

    return 0;
}
