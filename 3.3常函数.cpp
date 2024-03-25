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

void test01(){
    const Person person;  // 常量对象
    cout << person.p_A <<" , " << person.p_B<< endl;
    // perosn.p_A = 666; //报错， 常对象不能修改成员变量的值，但可以访问
    person.p_B = 777;  // 声明变量时加关键字 mutable 后，变量可以在常函数中修改
     cout << person.p_A <<" , " << person.p_B<< endl;
    // person.MyFunc();     //报错， 常对象只能调用常函数 
    person.showPerson();     
}

int main()
{
    test01();
    return 0;
}