#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (empty())
            return -1;

        int ans = q1.back();
        // length
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }

    int top()
    {
        if (empty())
            return -1;

        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
