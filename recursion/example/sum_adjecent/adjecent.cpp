#include <iostream>
#include <vector>
using namespace std;

/*
 Here we are trying to find the the maximum sum of the the adjacent number
 this is what we have to do with values
*/

int adjacentSum(vector<int> arr, int size, int index)
{

    // base case,
    if (index >= arr.size())
        return 0;

    // Now we have find the sum of the array elements,for that we need to
    int answer1 = arr[index] + adjacentSum(arr, size, index + 2);
    int answer2 = 0 + adjacentSum(arr, size, index + 1);
    return max(answer1, answer2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int index = 0;
    int size = arr.size();
    int adjecentItemSum = adjacentSum(arr, size, index);
    cout << "Adjecent Item sum is " << adjecentItemSum;
    return 0;
}
