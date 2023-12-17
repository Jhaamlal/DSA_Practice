#include <iostream>
#include <stack>
#include <vector>
using namespace std;

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
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            int value = temp->val;
            st.push(value);
            temp = temp->next;
        }
        int maxVal = INT32_MIN;
        vector<int> result;
        while (!st.empty())
        {
            int currentValue = st.top();
            if (currentValue > maxVal)
            {
                result.insert(result.begin(), 0);
                maxVal = currentValue;
            }
            else
                result.insert(result.begin(), maxVal);

            st.pop();
        }

        return result;
    }
};

int main()
{
    // Create nodes for the linked list
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(5);

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;

    // Create a Solution object
    Solution solution;

    // Call the nextLargerNodes function and store the result
    vector<int> result = solution.nextLargerNodes(node1);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
