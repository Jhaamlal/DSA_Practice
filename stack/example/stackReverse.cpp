#include <iostream>
using namespace std;
#include <stack>

int main()
{
    stack<char> st;
    string name = "Ravi shankar";
    string reverseName = "";
    for (int i = 0; i < name.size(); i++)
    {
        st.push(name[i]);
    }

    while (!st.empty())
    {
        reverseName += st.top();
        st.pop();
    }
    cout << "answer is  => " << reverseName << endl;

    return 0;
}
