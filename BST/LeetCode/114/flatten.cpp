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

/*
    if(root==NULL) return NULL;
    if(root ==NULL){

    }


*/

class Solution
{
public:
    void solve(TreeNode *root)
    {
        if (!root)
            return;
    }
    void flatten(TreeNode *root)
    {
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}

/*
largeNumber/SmallNumber

*/
