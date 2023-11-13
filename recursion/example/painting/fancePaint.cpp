// https : // www.geeksforgeeks.org/painting-fence-algorithm/
#include <iostream>
using namespace std;

// In recursion most important is to find out the way to find the the equation and formula
// there is no other, only you have to see the how can you solve the solution

int getPaintWays(int poles, int color)
{
    if (poles == 0)
        return 0;
    if (poles == 1)
        return 1;
    int answer = (poles - 1) * (getPaintWays(poles - 1, color) + getPaintWays(poles - 2, color));
    return answer;
}

int main()
{
    int poles = 4;
    int color = 3;
    int numberOfWays = getPaintWays(poles, color);
    cout << "Number of ways: " << numberOfWays;
    return 0;
}
