#include <iostream>
using namespace std;

string getSum(string num1, string num2, int num1_size, int num2_size)
{
    /*
        this can be solve via javascript very easily  =>
    */
    if (num1_size == 0 && num2_size == 0)
        return 0;

    getSum(num1, num2, num1_size - 1, num2_size - 1);
}

int main()
{
    string num1 = "124";
    string num2 = "124";
    int num1_size = num1.size() - 1;
    int num2_size = num1.size() - 1;
    getSum(num1, num2, num1_size, num2_size);
    return 0;
}
