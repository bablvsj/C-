// 第三阶段 C++核心编程
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    int p_c;
    int p_d;
    static int p_a;
    int func3(){
        cout << "public func调用" << endl;
        func();
        func2();
    };
    static void func()
    {
        cout << "func调用" << endl;

        func2();
        p_a = 66;
        // p_c = 44;   静态成员函数不可访问非静态成员变量
    };

private:
    static int p_b;
    static int func2()
    {
        cout << "private func2调用" << endl;
    }
};

int Person::p_a = 10;
int Person::p_b = 20;

int main()
{
    // 静态变量
    Person p1;
    p1.p_a = 100;
    cout << "p1.p_a: " << p1.p_a << endl;
    Person p2;
    p2.p_a = 200;
    cout << "p1.p_a: " << p1.p_a << endl; // 200 // 共享同一份数据
    cout << "p2.p_a: " << p2.p_a << endl; // 200

    // cout << "p_b" << p1.p_b << endl;   //私有权限不可访问
    // 静态成员函数
    p1.func();

    cout << sizeof(Person) << endl;
    // p1.func2();  // 私有权限不可访问
    // p1.func3();
    return 0;
}
