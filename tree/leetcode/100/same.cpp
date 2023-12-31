#include <iostream>
#include <vector>
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
    vector<int> inOrderSolve(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        vector<int> ans1 = inOrderSolve(root->left);
        ans.insert(ans.end(), ans1.begin(), ans1.end());

        ans.push_back(root->val);
        vector<int> ans2 = inOrderSolve(root->right);
        ans.insert(ans.end(), ans2.begin(), ans2.end());
        return ans;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
