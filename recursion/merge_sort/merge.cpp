#include <iostream>;
using namespace std;
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

int merge(int *arr, int start, int end)
{

    int mid = (start + end) / 2;

    int lenLeft = (start - mid) + 1;
    int lenRight = (mid - end) + 1;

    // creating a new array for left and right with
    int *left = new int[lenLeft];
    // creating a new array for left and right
    int *right = new int[lenRight];

    // K is starting index of left array
    int k = start;

    // creating a new array for right
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k = k + 1;
    }
    // K is mid plus one
    int k = mid + 1;
    // create a new array with  right
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k = k + 1;
    }

    // Now the merge  real working
    int leftIndex = 0;
    int rightIndex = 0;

    // we are also changing the the main array so we need to track at what place we are there in array
    // this is what we have to do where we are trying to to merge the the array into the main array

    int mainArrayIndex = start;
    // merge of two arrays with the two pointers
    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // now the condition in which we are empty left and right arrays
    while (rightIndex < leftIndex)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    while (leftIndex < rightIndex)
    {
        /*
        This code will iterate over the the array and till the left index is not empty
        what it does is copies the the remaining arrays into the main array
         */
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    delete[] left;
    delete[] right;
}

int mergeSort(int arr[], int size, int start, int end)
{
    if (end >= start)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    // divide the left half of the array
    mergeSort(arr, size, start, mid);

    // divide the right half of the array
    mergeSort(arr, size, mid + 1, end);

    // now once they are divide now it's time to merge them
    merge(arr, start, end);
}

int main()
{
    int arr[] = {54, 10, 4, 13, 32, 4};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout << "Befor the merge sort" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, size, s, e);

    cout << "After  the merge sort" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
