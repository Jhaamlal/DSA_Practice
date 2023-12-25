#include <string>
#include <iostream>
using namespace std;

int operationNeed(string &word1, string &word2, int i, int j)
{
    // base case that is anyone of the string get exhausted
    if (i >= word1.length())
        return word2.length() - j;
    if (j >= word2.length())
        return word1.length() - i;

    int ans = 0;

    if (word1[i] == word2[j])
    {
        ans = 0 + operationNeed(word1, word2, i + 1, j + 1);
    }
    else
    {
        // insertion is
        // insertions
        int option1 = 1 + operationNeed(word1, word2, i, j + 1);
        // delete operation
        int option2 = 1 + operationNeed(word1, word2, i + 1, j);
        // replace operation
        int option3 = 1 + operationNeed(word1, word2, i + 1, j + 1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    int i = 0;
    int j = 0;
    int operation = operationNeed(word1, word2, i, j);
    cout << operation;
    return 0;
}
