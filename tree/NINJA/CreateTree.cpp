#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
Node *solve(vector<int> &arr, int index, int &size)
{
    if (index >= size)
        return NULL;

    Node *node = new Node(arr[index]);

    node->left = solve(arr, 2 * index + 1, size);
    node->right = solve(arr, 2 * index + 2, size);

    return node;
}

Node *createTree(vector<int> &arr)
{
    // Write your code here.
    int size = arr.size();
    return solve(arr, 0, size);
    // return root;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = createTree(arr);

    return 0;
}