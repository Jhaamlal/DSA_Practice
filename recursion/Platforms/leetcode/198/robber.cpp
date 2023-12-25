#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int robHelper(vector<int> &nums, int i)
    {
        if (i >= nums.size())
            return 0;
        int ans1 = nums[i] + robHelper(nums, i + 2);
        int ans2 = 0 + robHelper(nums, i + 1);
        return max(ans1, ans2);
    }
    int rob(vector<int> &nums)
    {
        return robHelper(nums, 0);
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    int ans = solution.rob(nums);
    cout << "Answer is " << ans;
    return 0;
}
