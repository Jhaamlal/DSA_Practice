#include <iostream>
#include <vector>
using namespace std;
/*
    Merge sort algorithm , where you first divide the array int multiple single part and retrive back
*/
// write to  merge sort algorithm

//===============================================================
/*
1) Merge sort algorithm is a divide and concur algorithm
2) In this you divide the elements into the two part ,left and right
3) You divide the element into the two part ,right and left till  it not become one element
4) Then you start combining the two part ,left and right parts into one ,in back direction
5) Now you merge the element in that way, so that the are sorted in way you want, may be increasing or decreasing order
6) How will we merge the two part ,left and right,
    a) You will take the left and right element and use two pointer approach to each element
    b) You will change the same array that  you are using


*/
//================================================================

int merge(vector<int> &arr, int start, int end, int mid)
{
    int lenLeft = (mid - 1) + 1;
    int lenRight = (end - mid) + 1;
    vector<int> left(arr.begin(), arr.begin() + lenLeft);
    vector<int> right(arr.begin() + (lenLeft + 1), arr.begin() + lenRight);

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[lenLeft] < right[rightIndex])
        {
            arr[mainIndex] = left[lenLeft];
            mainIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainIndex] = right[lenRight];
            mainIndex++;
            rightIndex++;
        }
    }
    // After the one may be small or large
    while (rightIndex < leftIndex)
    {
        arr[mainIndex] = right[lenRight];
        mainIndex++;
        rightIndex++;
    }
    while (rightIndex > leftIndex)
    {
        arr[mainIndex] = left[lenLeft];
        mainIndex++;
        leftIndex++;
    }
}

int mergeSort(vector<int> arr, int size, int start, int end)
{
    int mid = start + (start - end) / 2;
    if (start <= end)
    {
        return;
    }
    // left part
    mergeSort(arr, size, start, mid);
    // Right part
    mergeSort(arr, size, mid + 1, end);

    merge(arr, start, end, mid);
}

int main()
{

    vector<int> arr = {4, 2, 5, 7, 1, 9, 0};
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    mergeSort(arr, size, start, end);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
