// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
=> Sorted array  you need to make the min-heap of all ke element .
=>
*/
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int val, int row, int col)
    {
        this->data = val;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        //  Putting the first row in the in min heap
        for (int row = 0; row < k; row++)
        {
            int element = arr[row][0];
            Info *temp = new Info(element, row, 0);
            pq.push(temp);
        }
        vector<int> ans;

        while (!pq.empty())
        {
            Info *temp = pq.top();
            pq.pop();
            int topData = temp->data;
            int topRow = temp->rowIndex;
            int topCol = temp->colIndex;

            // store in ans vector
            ans.push_back(topData);

            // next element for the same row, jisme se pop kia h just abhi
            // use insert bhi toh karna hai
            if (topCol + 1 < n)
            {
                // iska matlab row me or element abhi present hai
                Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
                pq.push(newInfo);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
