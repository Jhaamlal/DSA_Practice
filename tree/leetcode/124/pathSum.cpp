#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;

        int leftSum = max(0, solve(root->left, ans));
        int rightSum = max(0, solve(root->right, ans));

        int tempMax = max(root->val, max(root->val + leftSum, root->val + rightSum));
        ans = max(ans, root->val + leftSum + rightSum);

        return tempMax;
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
