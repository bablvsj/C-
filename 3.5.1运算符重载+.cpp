#include <iostream>
#include <string> // string 头文件
using namespace std;

class Person
{
public:
    Person(){};
    Person(int a, int b)
    {
        this->p_A = a;
        this->p_B = b;
    };
    Person operator+(const Person &p)
    {
        Person temp;
        temp.p_A = this->p_A + p.p_A;
        temp.p_B = this->p_B + p.p_B;
        return temp;
    };
    Person operator-(const Person &q)
    {
        Person temp2;
        temp2.p_A = this->p_A - q.p_A;
        temp2.p_B = this->p_B - q.p_B;
        return temp2;
    }
    friend ostream &operator<<(ostream &out, Person &p);  // 左移运算符重载


private:
    int p_A;
    int p_B;
};

//全局函数实现 + 号运算符重载
// Person operator+(const Person &p1, const Person &p2)
// {
//     Person temp(0, 0);
//     temp.p_A = p1.p_A + p2.p_A;
//     temp.p_B = p1.p_B + p2.p_B;
//     return temp;
// }

//全局函数实现左移重载
//ostream对象只能有一个
ostream &operator<<(ostream &out, Person &p)
{
    out << "a: " << p.p_A << " b: " << p.p_B << endl;
};

int main()
{
    // 加号运算符重载
    //  作用：实现两个自定义数据类型相加的运算
    Person p1(10, 20);
    Person p2(30, 50);
    Person p3 = p2 + p1; // 约等于 p2.operator+(p1)

    cout << p3 << " hello world" << endl;
    // cout << "p3 p_A、p_B " << p3.p_A << " 、 " << p3.p_B << endl;
    // Person p4 = p3 - p1; // 约等于 p3.operator-(p1)
    // cout << "p4 p_A、p_B " << p4.p_A << " 、 " << p4.p_B << endl;

    return 0;
}