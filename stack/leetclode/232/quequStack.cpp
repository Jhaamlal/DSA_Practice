#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (empty())
            return -1;

        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st2.pop();

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    int peek()
    {
        if (empty())
            return -1;

        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    bool empty()
    {
        return st1.empty();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
