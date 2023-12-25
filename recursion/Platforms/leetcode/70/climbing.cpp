// https://leetcode.com/problems/climbing-stairs/

/*
If you see this question, it is asking the number of ways to reach to the top level,and person can take one step or two steps at a time
this, so if you see :
if n=3
1) 1+1+1
2)2+1
3)1+2

Here we are finding out the number of ways to reach, which we can say it is permutation .
*/

#include <iostream>
using namespace std;
int climbStairs(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    cout << "Running test =>" << endl;
    int totalNumberWays = climbStairs(5);
    cout << "This is the total number of  " << totalNumberWays << endl;
}
