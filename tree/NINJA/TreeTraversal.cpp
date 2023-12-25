// https://www.codingninjas.com/studio/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
/*
=> Used extra memory ,due to some checking of concept
*/
vector<int> preOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);
    vector<int> leftPart = preOrderTraversal(root->left);
    vector<int> rightPart = preOrderTraversal(root->right);
    // Once you have putted the value ,you have the item
    // Item is received
    ans.insert(ans.end(), leftPart.begin(), leftPart.end());
    ans.insert(ans.end(), rightPart.begin(), rightPart.end());
    return ans;
}
vector<int> postOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    vector<int> leftPart = postOrderTraversal(root->left);
    vector<int> rightPart = postOrderTraversal(root->right);

    ans.insert(ans.end(), leftPart.begin(), leftPart.end());
    ans.insert(ans.end(), rightPart.begin(), rightPart.end());
    ans.push_back(root->data);
    return ans;
}

vector<int> inOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    vector<int> leftPart = inOrderTraversal(root->left);
    vector<int> rightPart = inOrderTraversal(root->right);

    // Add of the Item
    ans.insert(ans.end(), leftPart.begin(), leftPart.end());
    ans.push_back(root->data);
    ans.insert(ans.end(), rightPart.begin(), rightPart.end());
    return ans;
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> preOrder = preOrderTraversal(root);
    vector<int> postOrder = postOrderTraversal(root);
    vector<int> inOrder = inOrderTraversal(root);
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);
    return ans;
}