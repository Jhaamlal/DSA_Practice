#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // Heap is the way to access the top /bottom element in o(1)
        // Why because of it's property
        priority_queue<int> pq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        while (k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
