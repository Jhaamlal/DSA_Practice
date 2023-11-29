#include <iostream>
using namespace std;

/*
=> Iterate over the item, if it's equal to previous re just move the item ,
=> if it's different then previous move the head
1->1->2->3->3
*/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->val != temp->val)
            {
                ListNode *duplicate = temp;
                temp->next = temp->next->next;
                delete duplicate;
            }
            else

                temp = temp->next;
        }
        return head;
    }
};
int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Create a Solution object
    Solution sol;

    // Delete duplicates
    ListNode *result = sol.deleteDuplicates(head);

    // Print the linked list
    ListNode *temp = result;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
