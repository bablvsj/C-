#include <iostream>
using namespace std;

void swap(int a, int b);

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}
