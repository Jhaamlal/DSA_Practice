#include <iostream>
#include <stack>
using namespace std;
int getMiddle(stack<int> &st, int value)
{

    if (value == 0)
    {
        return st.top();
    }
    int currentTop = st.top();
    st.pop();
    int newVal = value - 1;
    // Here In recursion I was not saving the value that is getting return from st.top()
    // When you return from recursion you need to save the value in some where
    int result = getMiddle(st, newVal);
    // Back tracking
    st.push(currentTop);
    return result;
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(6);
    int value = st.size() / 2;
    int val = getMiddle(st, value);
    cout << "This is value =>" << val << endl;
    return 0;
}
