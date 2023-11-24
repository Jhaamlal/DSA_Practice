#include <iostream>
using namespace std;

/**
 * Definition for sngly-linked list.
 *
 */

/*This with the Insertion sort type of alogorithm ,need to solve with merge sort*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        ListNode *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    // head = [4, 2, 1, 3] len=4
    // head = [2, 4, 1, 3]
    // head = [2, 1, 4, 3]
    // head = [1, 2, 4, 3]
    ListNode *sortList(ListNode *head)
    {
        int listLength = getLength(head);
        ListNode *prev = NULL;
        ListNode *currentNode = head;
        ListNode *nextNode = head->next;
        int index = 1;
        while (index <= listLength)
        {
            ListNode *temp = head;
            if (nextNode == NULL)
            {
                break;
            }

            if (nextNode != NULL && currentNode->val > nextNode->val)
            {
                int tempData = nextNode->val;
                nextNode->val = currentNode->val;
                currentNode->val = tempData;
                if (index > 1)
                {
                    nextNode = currentNode;
                    currentNode = prev;
                    prev = NULL;
                    index--;
                }
            }
            else
            {
                prev = currentNode;
                currentNode = nextNode;
                nextNode = nextNode->next;
                index++;
            }
        }
        return head;
    }
};
int main()
{
    // Create nodes for the linked list
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(3);

    // Link the nodes together to form the linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create an instance of the Solution class
    Solution solution;

    // Call the sortList function and store the result
    ListNode *sortedList = solution.sortList(node1);

    // Print the sorted linked list
    while (sortedList != nullptr)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    cout << endl;

    return 0;
}
