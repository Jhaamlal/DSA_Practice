#include <iostream>
using namespace std;
#include <vector>
/*
Making stack with data structure.
Properties of stack,
remove from the top
add to the top
initialise the array
push method ()
pop method


How to initialise the stack
vector<int> arr={};

pointer because of dynamic array

*/
class Stack
{
private:
    /* data */
public:
    int *arr;
    int size;
    int top;
    Stack(int size)
    {
        // array create a dynamic array in heap
        arr = new int[size];
        this->size = size;
        this->top = -1;
    };
    void push(int data)
    {
        int si = size - 1;
        if (top == si)
        {
            cout << "Stack is already filled " << endl;
        }
        else
        {

            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is khaali" << endl;
        }
        else
        {

            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    int getSize()
    {
        return top + 1;
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is khaali" << endl;
            return -1;
        }
        else
        {

            return arr[top];
        }
    }
    void print()
    {
        cout << "Printing the array " << endl;
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // ~Stack();
};

int main(int argc, char const *argv[])
{
    Stack st(8);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(6);
    st.print();

    return 0;
}
