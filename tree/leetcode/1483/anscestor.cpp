// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
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

class TreeAncestor
{
public:
    TreeAncestor(int n, vector<int> &parent)
    {
    }

    int getKthAncestor(int node, int k)
    {
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
