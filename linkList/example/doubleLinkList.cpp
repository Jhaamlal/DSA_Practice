#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node()
    {
        this->val = 0;
        this->next = NULL;
        this->prev = prev;
    }

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = prev;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *tempNode = new Node(data);
    if (head != NULL)
    {
        tempNode->next = head;
        head->prev = tempNode;
        head = tempNode;
    }
    else
    {
        head = tempNode;
        tail = tempNode;
    }
}
Node *reverseList(Node *&node)
{
    if (node == NULL)
        return NULL;

    Node *temp = node->next;
    node->next = node->prev;
    node->prev = temp;

    if (node->prev == NULL)
        return node;

    return reverseList(node->prev);
}

void print(Node *head)
{
    // create a temporary node
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    print(head);
    head = reverseList(head);
    print(head);

    return 0;
}
