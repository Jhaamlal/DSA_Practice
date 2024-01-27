#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;
    /*
    => This will create the empty heap with ,dynamic memory allocation.
    => Capacity variable that is initiated for the change the capacity.
    */
    Heap(int capacity)
    {
        // create dynamic array .
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int nums)
    {
        // if size is equal to capacity
        if (size == capacity)
            return;
        size++;
        // Attach the element to the last of the Item and then left it .
        int index = size;
        arr[size] = nums;

        /*
        Now you have attache the number to the last , now you should put it the position where it is higher then it's children
        In that case you need to swap it
        */
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
    }
    /*
    What is happening this
    */
    int deleteFromHeap()
    {
        // take the first element of the array
        int answer = arr[1];

        // Replace it with the ,lowest item in the array ,which is at place 1
        arr[1] = arr[size];

        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            int largestKaIndex = index;

            if (largestKaIndex <= size && arr[largestKaIndex] < arr[leftIndex])
                largestKaIndex = leftIndex;
            if (largestKaIndex <= size && arr[largestKaIndex] < arr[rightIndex])
                largestKaIndex = rightIndex;

            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer;
    }

    void heapify(int *arr, int n, int index)
    {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestKaIndex = index;

        /*
        => Which is largest in the all of the Item , for that you need to compare to the all the
        Item in the left and right.
        */
        if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
            largestKaIndex = leftIndex;
        if (rightIndex <= n && arr[leftIndex] > arr[largestKaIndex])
            largestKaIndex = rightIndex;
        while (index != largestKaIndex)
        {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
            heapify(arr, n, index);
        }
    }
    /*
    => Build heap
    */
    void buildHeap(int arr[], int n)
    {
        for (int index = n / 2; index > 0; index--)
            heapify(arr, n, index);
    }

    void heapSort(int arr[], int n)
    {
        while (n != 1)
        {
            swap(arr[1], arr[n]);
            n--;
            heapify(arr, n, 1);
        }
    }
};