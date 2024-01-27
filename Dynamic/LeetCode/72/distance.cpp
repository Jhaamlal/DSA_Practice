#include <iostream>
using namespace std;

class Solution
{
public:
    int solveWithRecession(string word1, string word2, int i, int j)
    {
        if (i == word1.length())
            return word2.length() - j;
        if (j == word2.length())
            return word1.length() - i;

        int ans = 0;
        if (word1[i] == word2[j])
        {
            ans = 0 + solveWithRecession(word1, word2, i + 1, j + 1);
        }
        else
        {
            int replace = 1 + solveWithRecession(word1, word2, i + 1, j + 1);
            int insert = 1 + solveWithRecession(word1, word2, i, j + 1);
            int remove = 1 + solveWithRecession(word1, word2, i + 1, j);
            int ans = max(replace, max(insert, remove));
        }
        return ans;
    }
    int minDistance(string word1, string word2)
    {
        int i = word1.length();
        int j = word2.length();
        return solveWithRecession(word1, word2, i, j);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
