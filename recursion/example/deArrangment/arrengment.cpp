#include <iostream>
#include <vector>
using namespace std;

int solver(int nums)
{
    if (nums == 1)
    {
        return 0;
    }
    if (nums == 2)
    {
        return 1;
    }
    int ans = (nums - 1) * (solver(nums - 1) + solver(nums - 2));
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int ans = solver(5);
    cout << "This is the solution " << ans << endl;
    return 0;
}
