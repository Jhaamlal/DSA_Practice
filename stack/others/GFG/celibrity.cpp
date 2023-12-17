// https : // practice.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        // Push all the Item in 1 to 2 into the
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() != 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            // If a knows b
            if (M[a][b])
                st.push(b);
            else
                st.push(a);
        }

        // check single element

        int mightBeCelebrity = st.top();
        st.pop();

        // celebrity doesn't know anyone
        for (int i = 0; i < n; i++)
            if (M[mightBeCelebrity][i] != 0)
                return -1;

        // Everyone should know the celebrity
        for (int i = 0; i < n; i++)
            if (M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity)
                return -1;

        return mightBeCelebrity;
    }
};

int main()
{
    /* code */
    return 0;
}
