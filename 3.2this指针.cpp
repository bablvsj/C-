#include <iostream>
#include <string> // string 头文件
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name; // 当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    };
    Person &PersonAddPerson(Person p)
    {
        this->age += p.age;
        return *this; // 返回对象本身
    }
};

class Student
{
public:
    int s_age;
    void showCalssName()
    {
        cout << "我是student类" << endl;
    }
    void showPerson()
    {
        // if (this == NULL)
        // {
        //     return;
        // }
        cout << "Null" << endl;
        cout << s_age << endl;
        cout << "Null" << endl;
    }
};

int main()
{

    Person p1("吕小布", 19);
    cout << "p1.age = " << p1.age << endl; // 19
    Person p2("lin nini", 20);
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl; // 77 = 20 + 19 + 19 +19

    // 空指针也可以调用成员函数
    // Student *s1 = NULL;
    Student *s1;
    s1->showCalssName();
    s1->showPerson();

    return 0;
}