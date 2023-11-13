#include <istream>
#include <vector>
using namespace std;
int solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return 0;

    // when you include the first element
    int ans1 = nums[start] + solve(nums, start + 2, end);
    // when you not include the first element
    int ans2 = nums[start] + solve(nums, start, end);
    // answer the value
    return max(ans1, ans2);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = nums.size();
    if (size == 1)
        return nums[0];
    // Now as we know that , as homes are in circle ,if person robe the first house it can't robe the last house
    // to reuse the logic, why because the logic is remain the same that data remains
    // first case when first house is robbed ,then last house can't be robbed
    int ans1 = solve(nums, 0, size - 2);
    // When first house is not robbed
    int ans1 = solve(nums, 1, size - 1);
    return 0;
}
