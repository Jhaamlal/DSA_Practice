#include <iostream>
#include <vector>
using namespace std;
#include <climits>

int main()
{
    vector<int> array = {13, 46, 24, 52, 20, 9};
    int arrayLength = array.size();
    vector<int> vect(arrayLength);

    for (int i = 0; i < arrayLength; i++)
    {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = i; j < arrayLength; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
        }
        // swap(array[i], array[minIndex]);
        vect[i] = array[i];
    }

    for (int i = 0; i < vect.size(); i++)
    {
        cout << "This sorted array " << vect[i] << endl;
    }

    return 0;
}
