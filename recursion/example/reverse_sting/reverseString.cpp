#include <iostream>;
using namespace std;

void reverseStr(string str, int index, string &answerString, int size)
{
    if (index == size)
        return;

    char ch = str.at(index);
    reverseStr(str, index + 1, answerString, size);
    answerString += ch;
}

int main()
{
    string str = "Hello";
    int size = str.length();
    int index = 0;
    string answerString = " ";
    reverseStr(str, index, answerString, size);

    cout << "Anser string is +==  >" << answerString << endl;
    return 0;
}
