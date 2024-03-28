#include <iostream>
#include <string> // string 头文件
using namespace std;

// 通过重载递增运算符，实现自己的整型数据。

class MyInteger
{
    int m_Num;
    // friend ostream &operator<<(ostream out, MyInteger myint);
    friend ostream &operator<<(ostream &out, MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 0;
    };
    // 前置++
    MyInteger &operator++()
    {
        m_Num++;
    };
    // 后置++
    MyInteger operator++(int)
    {
        MyInteger temp = *this; // 记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        m_Num++;
        return temp;
    }
};

ostream &operator<<(ostream &out, MyInteger myint)
{
    out << myint.m_Num;
    return out;
};

int main()
{
    MyInteger myInt;
    cout << ++myInt << endl;

    int a = 5;
    int *p = &a;
    cout << "*p: " << *p << endl;
    cout << "p: " << p << endl;
    cout << "&a " << &a << endl;
    cout << "&p = " << &p << endl;

    int b[] = {1, 2, 3};

    int *q = b;
    cout << "&b " << &b << endl;
    cout << "b " << b << endl;

    cout << "b[1] " << b[0] << endl;
    cout << "q[1] " << q[0] << endl;
    cout << "*q " << *q << endl;
    return 0;

    // delete[] arr;
}