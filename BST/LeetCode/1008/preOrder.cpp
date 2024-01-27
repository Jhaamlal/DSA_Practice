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

// preorder = [8,5,1,7,10,12]
// preorder = [8,5,10,1,7,null,12]
class Solution
{
public:
    TreeNode *solve(TreeNode *root, vector<int> &preorder, int upper_bound, int &n)
    {
        if (n >= preorder.size() || preorder[n] > upper_bound)
            return NULL;
        // single case
        TreeNode *newNode = new TreeNode(preorder[n]);

        if (root->val > preorder[n] && preorder[n] < upper_bound)
            root->left = solve(newNode, preorder, preorder[n], ++n);
        if (root->val < preorder[n] && preorder[n] > upper_bound)
        {
            root->right = solve(newNode, preorder, preorder[n], ++n);
        }
        // TreeNode *newNode = new TreeNode(preorder[n]);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        // if preOrder size is zero
        int arraySize = preorder.size();
        if (arraySize == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        int upper_bound = INT_MAX;
        int n = 1;
        return solve(root, preorder, upper_bound, n);
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
