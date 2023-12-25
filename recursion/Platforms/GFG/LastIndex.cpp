// https://practice.geeksforgeeks.org/problems/last-index-of-a-character-in-the-string4516/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include <iostream>
using namespace std;
/*
=> create other function , to keep track of the index
=>
*/
class Solution
{
public:
    /*Mistake I made in this small */

    int solve(string s, char p, int index)
    {
        // base case
        if (s.size() == 0)
            return -1;

        // Recursive case: solve the problem for the rest of the string
        int lastIndexInRest = solve(s.substr(1), p, index + 1);

        // If the character was found in the rest of the string, return that index
        if (lastIndexInRest != -1)
            return lastIndexInRest;

        // Otherwise, check the current character
        if (s.at(0) == p)
            return index;

        // If the current character isn't a match either, return -1
        return -1;
    }

    int LastIndex(string s, char p)
    {
        int index = 0;
        int ans = solve(s, p, index);
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case 1: Normal case
    string s1 = "hello";
    char p1 = 'l';
    int result1 = solution.LastIndex(s1, p1);
    std::cout << "Test case 1 result: " << result1 << std::endl; // Expected output: 3

    // Test case 2: Character not in string
    string s2 = "world";
    char p2 = 'a';
    int result2 = solution.LastIndex(s2, p2);
    std::cout << "Test case 2 result: " << result2 << std::endl; // Expected output: -1

    // Test case 3: Empty string
    string s3 = "";
    char p3 = 'b';
    int result3 = solution.LastIndex(s3, p3);
    std::cout << "Test case 3 result: " << result3 << std::endl; // Expected output: -1

    // Test case 4: Character at the end of the string
    string s4 = "apple";
    char p4 = 'e';
    int result4 = solution.LastIndex(s4, p4);
    std::cout << "Test case 4 result: " << result4 << std::endl; // Expected output: 4

    return 0;
}
