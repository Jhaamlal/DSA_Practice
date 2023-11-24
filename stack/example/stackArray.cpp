#include <iostream>
using namespace std;

//
/*
    pass the two stack to function

    first => approach is to do with while loop and putting the element;
    second => approach is to do with recursion
        step

*/
// void getStackArray(stack<int> &st, stack<int> &st2)
// {
//     // base case when empty
//     // edge case overflow
//     // edge case underflow
//     //
// }

class Stack
{
public:
    int *arr;
    int size;
    int top;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
        top2 = size;
    }
    void push1(int data)
    {
        if (top - top2 == 1)
        {
            cout << "Top to reach " << endl;
        }
        else
        {

            top++;
            arr[top] = data;
        }
    }
    void push2(int data)
    {
        if (top2 - top == 1)
        {
            cout << "Top to reach " << endl;
        }
        else
        {

            top2--;
            arr[top2] = data;
        }
    }
    void pop1()
    {
        if (top == -1)
        {
            cout << "Not possible " << endl;
        }
        else
        {

            arr[top] = 0;
            top--;
        }
    }
    int pop2()
    {
        if (top2 == size)
        {
            cout << "Dimag kharab hai kya,khali hai sab " << endl;
        }
        else
        {

            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout << "printing the data ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

main()
{
    Stack st(5);
    st.push1(3);
    st.push2(9);
    st.print();

    return 0;
}
