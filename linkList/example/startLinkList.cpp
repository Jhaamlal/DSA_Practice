#include <iostream>
using namespace std;

// Class node creation
class Node
{
public:
    int data;
    Node *next;

    // This is default constructed
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    // Parameter customer
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    // create a temporary node
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Insert node
// One thing to be noted is that pass by value ,will not work
// Pass by reference in head is
// If it is empty link list then head is also empty and tail is also empty

void insertAtHead(Node *&head, Node *&tail, int data)
{
    cout << "Head is out of => " << endl;
    if (head == NULL)
    {
        // If it is empty link list
        Node *newNode = new Node(data);
        // Once we created new list ,use this for
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Create a node
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

int insertAtTail(Node *&head, Node *&tail, int data)
{
    cout << "Tail  is out of => " << endl;
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Step1 : Create a node
        Node *newNode = new Node(data);
        // step2 : Connect with tail node
        tail->next = newNode;
        // update tail node
        tail = newNode;
    }
}

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

int insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    int len = findLength(head);

    // If it is starting postion
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    // If it is last position then ,you can do that
    else if (position > len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    else
    {
        // If you want to position it in between in that case
        // you have to go from ,
        Node *newNode = new Node(data);

        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        // Now we have reached the postion that we want to insert the value
        // newNode next is referring to current;
        newNode->next = curr;

        // pervious of new node is
        prev->next = newNode;
    }
}

int main()
{
    /* code */
    cout << " Jai shree Ram " << endl;

    Node *head = NULL;
    Node *tail = NULL;

    // Created node
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *five = new Node(50);

    // Attaching the previous
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = five;

    // starting point of the data
    // Node *head = first;
    // Node *tail = five;
    // Node *head = NULL;

    insertAtHead(head, tail, 500);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 300);

    print(head);

    return 0;
}
