// https : // practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> hdToNode;
        vector<int> ans;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;
            if (hdToNode.find(hd) == hdToNode.end())
                hdToNode[hd] = frontNode->data;
            if (frontNode->left != NULL)
                q.push(make_pair(frontNode->left, hd - 1));
            if (frontNode->right != NULL)
                q.push(make_pair(frontNode->right, hd + 1));
        }
        for (auto i : hdToNode)
            ans.push_back(i.second);
        return ans;
    }
    vector<int> bottomView(Node *root)
    {
        map<int, int> hdToNode;
        vector<int> ans;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;
            // Only remove this if condition ,
            // This will make whole code work because the now last which will meet will be s
            // if (hdToNode.find(hd) == hdToNode.end())
            hdToNode[hd] = frontNode->data;
            if (frontNode->left != NULL)
                q.push(make_pair(frontNode->left, hd - 1));
            if (frontNode->right != NULL)
                q.push(make_pair(frontNode->right, hd + 1));
        }
        for (auto i : hdToNode)
            ans.push_back(i.second);
        return ans;
    }
};

int main()
{
    /* code */
    return 0;
}
