#include <iostream>
#include <stack>
using namespace std;

int insertSorted(stack<int> &st, int element)
{
    // Base case
    if (!st.empty() || element > st.top())
    {
        st.push(element);
        return;
    }
    int tempElement = st.top();
    // When you access top ,mostly you would have to right the pop logic also
    st.pop();
    insertSorted(st, tempElement);
    // Make sure the element has same value
    st.push(tempElement);
}
int sortStack(stack<int> &st)
{
    if (!st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    // WHen item become empty in that case what you do is
    // call the empty stack with element,
    // then once the item is filled with one number ,you put other,which then compare and put in sorted order
    insertSorted(st, temp);
}

int main()
{
    stack<int> st;
    stack<int> ans;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    int stackSize = st.size();

    return 0;
}
