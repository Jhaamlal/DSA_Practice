#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q, queue<int> &result)
{
    /*
    1) Get the first element of the item.
    2) Remove that element.
    3) pass the item again to the qu.
    */
    if (q.size() == 0)
        return;

    int currentNum = q.front();
    q.pop();
    reverseQueue(q, result);
    result.push(currentNum);
}

int main()
{
    // Create a queue and add some items
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    // Create an empty queue for the result
    std::queue<int> result;

    // Call the reverseQueue function
    reverseQueue(q, result);

    // Print the result
    while (!result.empty())
    {
        std::cout << ' ' << result.front();
        result.pop();
    }

    return 0;
    return 0;
}
