#include <iostream>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        /*
            1) Well the genius thing is here consider all the deficit as one .
            2) The things we do not go round as to check again and again we have aggregate.
            3) This help to iterate the item one by one .
        */

        for (int i = 0; i < gas.size(); i++)
        {
            balance = balance + gas[i] - cost[i];
            if (balance < 0)
            {
                deficit += abs(balance);
                start = i + 1;
                balance = 0;
            }
        }

        if (balance - deficit >= 0)
            return start;
        else
            return -1;
    }
};

int main()
{

    return 0;
}
