#include <iostream>
using namespace std;

// explain of backtracking here why it is necessary
/*
    1) simply speaking  backtracking is nothing but when you return back from the,
    2) get back to the original array  and thats what you want
*/

void permutation(string &str, int index)
{
    // Base case: permutation
    if (index >= str.length())
    {
        cout << str << endl;
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        // Here you are going to all the i for each index in the string
        // this is very crucial for each index
        swap(str[index], str[i]);

        permutation(str, index + 1);
        // this is here backtracking starting
        swap(str[index], str[i]);
    }
}

int main()
{
    string str = "abc";
    int index = 0;
    permutation(str, index);
    return 0;
}
