// https://leetcode.com/contest/weekly-contest-373/problems/count-beautiful-substrings-i/
#include <iostream>
using namespace std;

class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int resemble = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string tempString = s.substr(i, k);
            int vowelCount = 0;
            int consonantCount = 0;
            for (char c : tempString)
            {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    vowelCount++;
                else
                    consonantCount++;
            }
            if (vowelCount == consonantCount)
                resemble++;
        }

        return resemble;
    }
};
// Each time it should be grow by that number ,i that case it will increase by lap and bounce

int main(int argc, char const *argv[])
{

    Solution solution;

    std::string test1 = "baeyh";
    int result1 = solution.beautifulSubstrings(test1, 2);
    std::cout << "Test 1 result: " << result1 << std::endl; // Expected output: 2

    std::string test2 = "abba";
    int result2 = solution.beautifulSubstrings(test2, 1);
    std::cout << "Test 2 result: " << result2 << std::endl; // Expected output: 1

    // std::string test3 = "bcdf";
    // int result3 = solution.beautifulSubstrings(test3, 1);
    // std::cout << "Test 3 result: " << result3 << std::endl;
}
