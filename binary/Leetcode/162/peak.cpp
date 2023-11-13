// https://leetcode.com/problems/find-peak-element/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 there are multiple approach to this problem
 1) Linier approach is  used ,check that the element , I , I+1 and I-1 are same
 2) another approach is used is to sort the algorithm and find last elements and return the peak
*/

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 10, 7, 8, 9, 4};
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    int maxNums = sortedNums[nums.size() - 1];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == maxNums)
        {
            cout << "Max index " << i;
            return i;
        }
    }

    return 0;
}
