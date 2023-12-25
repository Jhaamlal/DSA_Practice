#include <iostream>
#include <cctype>
#include <string>
using namespace std;

//  s = "A man, a plan, a canal: Panama"
class Solution
{
public:
    void solve(string s, bool &ans, int &frontIndex, int &lastIndex)
    {
        // edge case
        cout << s << endl;
        cout << s.size() << endl;
        if (s.size() == 0)
            return;
        // base case
        if (frontIndex >= lastIndex)
            return;

        // once case
        char frontChar = s[frontIndex];
        char backChar = s[lastIndex];
        if (frontChar != backChar)
        {
            ans = false;
            return;
        }

        solve(s, ans, ++frontIndex, --lastIndex);
    }
    bool isPalindrome(string s)
    {
        string newStr = "";
        bool ans = true;

        for (int i = 0; i < s.size(); i++)
        {
            int ascii_val = int(s.at(i));
            if (65 <= ascii_val && ascii_val <= 90)
                newStr += tolower(s.at(i));
            else if (97 <= ascii_val && ascii_val <= 122)
                newStr += s.at(i);
            else if (48 <= ascii_val && ascii_val <= 57)
                newStr += s.at(i);
        }
        int frontIndex = 0;
        int lastIndex = newStr.size() - 1;
        solve(newStr, ans, frontIndex, lastIndex);
        return ans;
    }
};

int main()
{
    Solution solution;

    // 0P
    solution.isPalindrome("0P");

    /*

    // Test case 1: Palindrome with mixed case
    std::cout << (solution.isPalindrome("AbleWasIEreISawElba") ? "True" : "False") << std::endl; // Expected output: True


    // Test case 2: Non-palindrome
    std::cout << (solution.isPalindrome("HelloWorld") ? "True" : "False") << std::endl; // Expected output: False

    // Test case 3: Palindrome with special characters
    std::cout << (solution.isPalindrome("A man, a plan, a canal: Panama") ? "True" : "False") << std::endl; // Expected output: True

    // Test case 4: Empty string
    std::cout << (solution.isPalindrome("") ? "True" : "False") << std::endl; // Expected output: True

    // Test case 5: Single character
    std::cout << (solution.isPalindrome("A") ? "True" : "False") << std::endl; // Expected output: True
    */

    return 0;
}
