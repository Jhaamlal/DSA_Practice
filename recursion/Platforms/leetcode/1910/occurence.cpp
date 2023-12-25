// https: // leetcode.com/problems/remove-all-occurrences-of-a-substring/submissions/1066891754
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/submissions/1124721193
#include <iostream>
using namespace std;
class Solution
{
public:
    void solve(string &s, string &part, int index)
    {

        if (index < 0)
            index = 0;

        // edge case
        if (s.size() == 0)
            return;

        // base case
        if (index > s.size() - 1)
            return;
        // solve for one case

        string subString = s.substr(index, part.size());
        if (subString == part)
        {
            s.erase(index, part.size());
            index = index - part.size();
        }
        else
            index++;

        // recursive call
        solve(s, part, index);
    }
    string removeOccurrences(string s, string part)
    {
        int index = 0;
        solve(s, part, index);
        return s;
    }
};
int main()
{
    Solution solution;
    // ccctltctlltlb

    // Test case 1
    string s1 = "daabcadabc";
    string part1 = "abc";
    cout << "Test case 1: " << solution.removeOccurrences(s1, part1) << endl; // Expected output: "dd"

    /*

    // Test case 2
    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << "Test case 2: " << solution.removeOccurrences(s2, part2) << endl; // Expected output: "ab"

    // Test case 3
    string s3 = "abcabcabc";
    string part3 = "abc";
    cout << "Test case 3: " << solution.removeOccurrences(s3, part3) << endl; // Expected output: ""
    */

    return 0;
}
