// 第三阶段 C++核心编程
#include <iostream>
#include <string>
using namespace std;

class Phone
{

public:
    string m_phoneName;
    Phone(string name)
    {
        m_phoneName = name;
        cout << "Phone 构造函数" << endl;
    };

    ~Phone()
    {
        cout << "Phone 析构" << endl;
    };
};

class Person
{
public:
    string p_name;
    Phone p_phone;
    Person(string name, string phone) : p_name(name), p_phone(phone)
    {
        cout << "Person 构造函数" << endl;
    };
    void PrintPhone()
    {
        cout << p_name << "使用 Phone: " << p_phone.m_phoneName << endl;
    };
    ~Person()
    {
        cout << "Person 析构" << endl;
    }
};

int main()
{
    Person p("lvbu", "xiaomi");
    p.PrintPhone();
    // Phone 构造函数
    // Person 构造函数
    // lvbu使用 Phone: xiaomi
    // Person 析构
    // Phone 析构

    return 0;
}