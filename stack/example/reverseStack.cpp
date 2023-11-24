#include <iostream>
using namespace std;
#include <stack>

/*

*/
void reverseStack(stack<int> &st, stack<int> &ans, int size)
{
    // base case
    if (size == 1)
    {
        int topEl = st.top();
        ans.push(topEl);
        return;
    }
    int currentTop = st.top();
    ans.push(currentTop);
    st.pop();
    reverseStack(st, ans, size - 1);
}
void insertAtBottom(stack<int> &st, int &element)
{
    // base case
    if (st.empty())
    {
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(temp);
}

void reverseStackWithRecursion(stack<int> &st, int size)
{
    // Don't use this use
    // st.empty(),then you don't need to send the size
    if (size == 0)
    {
        return;
    }
    int currentTop = st.top();
    st.pop();
    reverseStackWithRecursion(st, size - 1);
    insertAtBottom(st, currentTop);
    // st.inse(currentTop);
    return;
}

int main(int argc, char const *argv[])
{
    stack<int> st;
    stack<int> ans;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    int stackSize = st.size();
    // reverseStack(st, ans, stackSize);
    reverseStackWithRecursion(st, stackSize);
    // While loop for print of stack
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
