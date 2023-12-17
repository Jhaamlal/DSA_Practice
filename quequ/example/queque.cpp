#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << "length is => : " << q.size() << endl;
    cout << "Front element is => : " << q.front() << endl;
    cout << "Back element is => : " << q.back() << endl;
    return 0;
}
