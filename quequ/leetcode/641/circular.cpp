#include <iostream>
using namespace std;

// Circular deque
class MyCircularDeque
{
    int size;
    int front;
    int rear;
    int *arr;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1 && rear == -1)
        {
            // empty case
            rear++;
            front++;
            arr[front] = value;
        }
        else if (front == 0 && rear != size - 1)
        {
            // circular case
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1 && rear == -1)
        {
            // empty case
            rear++;
            front++;
            arr[rear] = value;
        }
        else if (front == 0 && rear != size - 1)
        {
            // circular case
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            arr[++rear] = value;
        }
        return true;
    }

    bool deleteFront()
    {
    }

    bool deleteLast()
    {
    }

    int getFront()
    {
    }

    int getRear()
    {
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }
};
int main()
{

    return 0;
}
