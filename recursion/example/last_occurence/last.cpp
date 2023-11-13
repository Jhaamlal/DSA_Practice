#include <iostream>
using namespace std;
#include <string>

//

int getLastIndex(string str, int index, char target, int &answer)
{
    int size = str.length() - 1;
    char currentChar = str[index];
    if (currentChar == target)
    {
        answer = index;
    }

    if (index >= size)
        return answer;

    return getLastIndex(str, index + 1, target, answer);
}

int main()
{
    int index = 0;
    string str = "rmm";
    char target = 'm';
    int answer = -1;
    int ans = getLastIndex(str, index, target, answer);
    cout << ans << endl;
    return 0;
}
