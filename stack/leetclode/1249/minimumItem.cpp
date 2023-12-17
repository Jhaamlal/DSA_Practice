#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    s.erase(i, 1);
                    i--;
                }
                else if (st.top() == '(')
                {
                    st.pop();
                }
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            cout << "This is dangerous => " << s[i] << endl;
        }
        int stringSize = s.size() - 1;
        for (int i = stringSize; i >= 0; i--)
        {
            if (st.empty() == false)
            {
                if (s[i] == '(')
                {
                    s.erase(i, 1);
                    st.pop();
                    i++;
                }
            }
            else
                break;
        }
        return s;
    }
};

int main()
{

    Solution solution;
    string s = "lee(t(c)o)de)";
    // string s = "(a(b(c)d)";
    // string s = "))((";
    string result = solution.minRemoveToMakeValid(s);
    cout << "The result is: " << result << endl;
    return 0;
}
