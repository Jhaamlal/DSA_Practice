#include <iostream>;
#include <vector>;
using namespace std;

int solve(vector<int> &coins, int amount)
{

    // base case: coins
    if (coins.size() == 0 || amount == 0)
        return 0;
    if (amount < 0)
        return INT16_MAX; // out of range

    // for coin change notifications
    int mini = INT16_MAX;
    /*
    iterator over all the coins in the array, and check if put the recursion
    */
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (coin <= amount)
        {
            // This will stop the recursion to go in the negative direction
            // This is how it will stop calculating the useless probability
            int recursionAns = 1 + solve(coins, amount - coin);
            if (recursionAns != INT16_MAX)
            {
                int ans = 1 + recursionAns;
                mini = min(mini, ans);
            }
        }

        /* code */
    }
    return mini;
}

int main()
{
    vector<int> coins;
    int amount;

    return 0;
}
