#include <iostream>
#include <stack>

using namespace std;
void solve(stack<int> &st)
{
    if (st.empty())
        return;
    int val = st.top();
    st.pop();
    solve(st);
    stack<int> tempSt;
    if (st.empty())
    {
        st.push(val);
    }
    else
    {
        while (!st.empty() && st.top() > val)
        {
            int temp = st.top();
            tempSt.push(temp);
            st.pop();
        }
        st.push(val);
        while (!tempSt.empty())
        {
            int top = tempSt.top();
            st.push(top);
            tempSt.pop();
        }
    }
    return;
}
stack<int> sortStack(stack<int> &s)
{
    solve(s);
    // stack<int> tempSt = s;
    // while (!tempSt.empty())
    // {
    //     int topVal = tempSt.top();
    //     cout << topVal << endl;
    //     tempSt.pop();
    // }

    return s;
}
int main(int argc, char const *argv[])
{
    stack<int> stack;
    stack.push(1);
    stack.push(3);
    stack.push(2);

    sortStack(stack);
    return 0;
}
