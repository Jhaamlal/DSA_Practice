// https: // leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {2, 2};
    int target = 2;
    int start = 0;
    int end = nums.size();
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (target == nums[mid])
        {
            int indexLeft = mid;
            int indexRight = mid;
            while (indexLeft - 1 >= 0 && nums[indexLeft - 1] == target && indexLeft > start)
                indexLeft--;
            while (indexRight + 1 <= end && nums[indexRight + 1] == target && indexRight < end)
                indexLeft++;
            cout << "Starting => " << indexRight << "ending is  => " << indexLeft << endl;
            return indexLeft;
        }
        if (target >= nums[mid])
            start = mid + 1;
        if (nums[mid] >= target)
            end = mid - 1;
    }
    return 0;
}
