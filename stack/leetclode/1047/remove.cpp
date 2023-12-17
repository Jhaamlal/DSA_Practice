#include <iostream>
#include <stack>
using namespace std;
/*
    1) Create a index with zero;
    2) Iterate till the length
    3) Check if string is present in the stack,
       if not then put it  else remove it and also erase that element in the string also
 s = "abbaca"
*/
class Solution
{
public:
    string removeDuplicates(string s)
    {

        int index = 0;
        stack<int> st;
        while (index != s.size())
        {
            if (st.empty() == false && st.top() == s[index])
            {

                st.pop();
                s.erase(index, 1);
            }
            else
            {
                st.push(s[index]);
                index++;
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
int main()
{
    Solution solution;
    cout << "Test Case 1: " << endl;
    cout << "Input: abbaca" << endl;
    cout << "Expected Output: ca" << endl;
    cout << "Actual Output: " << solution.removeDuplicates("abbaca") << endl
         << endl;

    cout << "Test Case 2: " << endl;
    cout << "Input: aababa" << endl;
    cout << "Expected Output: b" << endl;
    cout << "Actual Output: " << solution.removeDuplicates("aababa") << endl
         << endl;

    cout << "Test Case 3: " << endl;
    cout << "Input: abcde" << endl;
    cout << "Expected Output: abcde" << endl;
    cout << "Actual Output: " << solution.removeDuplicates("abcde") << endl
         << endl;

    cout << "Test Case 4: " << endl;
    cout << "Input: " << endl;
    cout << "Expected Output: " << endl;
    cout << "Actual Output: " << solution.removeDuplicates("") << endl
         << endl;

    return 0;
}
