#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        while (k < nums.size())
        {
            int top = pq.top();
            int firstEl = nums[k];
            if (firstEl < top)
            {
                pq.pop();
                pq.push(firstEl);
            }
            k++;
        }
        return pq.top();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
