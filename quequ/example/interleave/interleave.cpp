#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleave(queue<int> &qu, queue<int> &ans)
{
    int queLen = qu.size();
    int index = 0;
    queue<int> tempQue;
    while (index >= queLen / 2)
    {
        int currentNum = qu.front();
        qu.pop();
        tempQue.push(currentNum);
        index++;
    }
    while (!qu.empty())
    {
        int currentNum1 = qu.front();
        int currentNum2 = tempQue.front();
        ans.push(currentNum1);
        ans.push(currentNum2);
        qu.pop();
        tempQue.pop();
    }
}

int main()
{

    return 0;
}
