#include <iostream>
#include <vector>
using namespace std;
#include <climits>

int main()
{
    vector<int> array = {13, 46, 24, 52, 20, 9};
    int arrayLength = array.size();
    int index = 1;
    while (index <= arrayLength)
    {
        if (array[index] < array[index - 1])
        {
            swap(array[index], array[index - 1]);
            index--;
        }
        else
            index++;
    }
    for (int i = 0; i < arrayLength; i++)

        cout << "Jai shree ram => " << array[i] << endl;

    return 0;
}
