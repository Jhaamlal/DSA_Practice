#include <iostream>
using namespace std;
/*
Make BST from In order array , as we know that ,from array we are need
As we know that , array in BST
*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *bstFromInOrder(vector<int> inOrder, int start, int end)
{
    if (inOrder.size() == 0)
        return NULL;

    // base case
    if (end > start)
        return NULL;

    int mid = start + (end - start) / 2;
    int el = inOrder[mid];
    Node *root = new Node(el);

    root->left = bstFromInOrder(inOrder, start, mid - 1);
    root->right = bstFromInOrder(inOrder, mid, end);

    return root;
}

main(int argc, char const *argv[])
{

    return 0;
}
