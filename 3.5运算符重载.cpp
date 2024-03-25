#include <iostream>
#include <string> // string 头文件
using namespace std;

class Person
{
public:
    int p_A;
    int mA;
    mutable int p_B; // 可修改的
    Person()
    {
        this->p_A = 10; // 当形参和成员变量同名时，可用this指针来区分
        this->p_B = 20;
    };
    void showPerson() const
    {
        // this = NULL; // 不能修改指正的指向 Person * const this
        // this->mA = 100;
        this->p_B = 100;
        cout << "常函数 showPerson" << endl;
    };
    void MyFunc()
    {
        // mA = 1000;
        cout << "常函数 MyFunc" << endl;
    }
};

int main()
{
    // 加号运算符重载
    //  作用：实现两个自定义数据类型相加的运算
    return 0;
}