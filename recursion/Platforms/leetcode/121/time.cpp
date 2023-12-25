#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &prices, int &arrLength, int index, int &max)
    {
        if (arrLength == 0)
            return;

        // base case
        if (index > arrLength)
            return;

        // studies
        if (prices[0] > prices[index])
        {
            prices.erase(prices.begin());
            arrLength--;
        }
        else
        {
            int tempMax = prices[index] - prices[0];
            if (tempMax > max)
                max = tempMax;
            index++;
        }

        // recursion
        solve(prices, arrLength, index, max);
    }

    // Solution by Lakshay chaudhary
    void maxProfitFinder(vector<int> &prices, int i, int &minPrice, int &maxPrice)
    {
        if (i == prices.size())
            return;

        if (prices[i] < minPrice)
            minPrice = prices[i];

        int todaysProfit = prices[i] - minPrice;
        if (todaysProfit > maxPrice)
            maxPrice = todaysProfit;

        maxProfitFinder(prices, i + 1, minPrice, maxPrice);
    }

    int maxProfit(vector<int> &prices)
    {
        int arrLength = prices.size();
        int index = 0;
        int max = 0;
        solve(prices, arrLength, index, max);
        // --------------------- Second method ---------------------------//
        int minPrice = INT_MAX;
        int maxPrice = INT_MIN;
        maxProfitFinder(prices, 0, minPrice, maxPrice);
        return max;
    }
};

int main()
{
    Solution solution;

    // Test case 1:
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Test case 1 result: " << solution.maxProfit(prices1) << std::endl; // Expected output: 5

    // Test case 2:
    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout << "Test case 2 result: " << solution.maxProfit(prices2) << std::endl; // Expected output: 0

    // Test case 3:
    std::vector<int> prices3 = {2, 4, 1};
    std::cout << "Test case 3 result: " << solution.maxProfit(prices3) << std::endl; // Expected output: 2

    // Test case 4:
    std::vector<int> prices4 = {3, 2, 6, 5, 0, 3};
    std::cout << "Test case 4 result: " << solution.maxProfit(prices4) << std::endl; // Expected output: 4

    return 0;
}
