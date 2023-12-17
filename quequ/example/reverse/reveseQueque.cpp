#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*
1) Create a stack
1) Iterate over the stack and put it
1) put back into que again
*/
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> st;
        queue<int> qu;
        while (!q.empty())
        {
            int currentNum = q.front();
            st.push(currentNum);
            q.pop();
        }

        while (!st.empty())
        {
            int currentVal = st.top();
            qu.push(currentVal);
            st.pop();
        }
        return qu;
    }
};
int main()
{
    // Create a Solution object
    Solution solution;

    // Create a queue and add some items
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Call the rev function and store the result
    std::queue<int> result = solution.rev(q);

    // Print the result
    while (!result.empty())
    {
        std::cout << ' ' << result.front();
        result.pop();
    }

    return 0;
}
