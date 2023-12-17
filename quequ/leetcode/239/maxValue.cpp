#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        // Iterate over the each element
        for (int i = 0; i < k; i++)
        {
            int element = nums[i];
            // You check if the current  element is less then
            while (!dq.empty() && element > nums[dq.back()])
                dq.pop_back();
            // If now now element is not bigger then that in that case
            // dq push
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++)
        {
            ans.push_back(nums[dq.front()]);

            // Check out of range element and remove the element
            if (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            // remove the small element
            int element = nums[i];
            // You check if the current  element is less then
            while (!dq.empty() && element > nums[dq.back()])
                dq.pop_back();
            // If now now element is not bigger then that in that case
            // dq push
            dq.push_back(i);
        }
        // last window not stored
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

int main()
{
    /* code */
    return 0;
}
