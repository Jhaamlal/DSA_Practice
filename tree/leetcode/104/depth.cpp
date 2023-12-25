#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // pass the different parameter in the data
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth1(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;

        // item there
        q.push(root);
        q.push(NULL);
        int count = 1;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (!q.empty())
                {
                    count++;
                    q.push(NULL);
                }
            }
            else
            {

                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
            }
        }
        return count;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        // Left side
        int left = height(root->left);

        // Right side of the element
        int right = height(root->right);

        int height = max(right, left) + 1;

        return height;
    }
};

int main()
{
    /* code */
    return 0;
}
