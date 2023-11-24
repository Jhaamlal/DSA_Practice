#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(s[i]);
            }
            else
            {
                char topItem = st.top();
                if (ch == ')' && topItem == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && topItem == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && topItem == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            /* code */
            return true;
        }
    }
};

int main()
{
    /* code */
    return 0;
}
