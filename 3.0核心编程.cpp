// 第三阶段 C++核心编程
#include <iostream>
#include <string>
using namespace std;

int g_a = 10; // 全局变量
int g_b = 10;
const int c_g_a = 10; // 全局常量
const int c_g_b = 10;

const double PI = 3.14;

int *func()
{                         // 堆区数据利用new关键字进行开辟内存
    int *a = new int(10); // 利用new创建的数据，会返回该数据对应的类型的指针
    return a;
}

// 地址传递
void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 返回局部变量引用
// int &test01()
// {
//     int a = 10; // 局部变量
//     return a;
// }

// 返回静态变量引用
int &test02()
{
    static int a = 10;
    return a;
}

class Circle
{
public:
    int m_r;
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

class Student
{
public:
    string s_name;
    int s_id;
    void showInfo()
    {
        cout << "学生的姓名为：" << s_name << " 学号为：" << s_id;
    };
    void setName(string name)
    {
        s_name = name;
    };
    void setId(int id)
    {
        s_id = id;
    };
};

class Person
{

public:
    string p_name;
    int p_age;
    string p_lover;
    int *p_height;
    Person()
    {
        cout << "无参数构造函数！" << endl;
    };
    Person(string name, int age, int height)
    {
        cout << "有参构造函数！" << endl;
        p_name = name;
        p_age = age;
        *p_height = height;
    };
    Person(const Person &p)
    {
        p_age = p.p_age;
        p_height = new int(*p.p_height);
        cout << "拷贝构造函数！" << endl;
    };
    ~Person()
    {
        cout << "析构函数!" << endl;
    };
    void setName(string name)
    {
        p_name = name;
    };
    int getAge()
    {
        return p_age;
    };
    void setAge(int age)
    {

        if (age < 0 || age > 150)
        {
            cout << "你个老妖精" << endl;
            return;
        }
        p_age = age;
    };
};

class Teacher{
    private:
        string t_name;
        int t_age;
        int t_phone;
    public:
        Teacher(string name,int age,int phone):t_name(name),t_age(age),t_phone(phone){};
        void printTeacher(){
            cout << "t_name: " << t_name << endl;
            cout << "t_name: " << t_age << endl;
            cout << "t_name: " << t_phone << endl;
        }
};

// void Person::setAge(int age)
// {
//     if (age < 0 || age > 150)
//     {
//         cout << "你个老妖精" << endl;
//         return;
//     }
//     p_age = age;
// }

int main()
{

    // 全局区中存放全局变量、静态变量、常量
    // 常量区中存放 const修饰的全局常量和字符串常量
    // 局部变量、局部常量放栈区
    // int a = 10;
    // int b = 20;
    // cout << "局部变量a地址" << (int)&a << endl; // 6422284
    // cout << "局部变量b地址" << (int)&b << endl;
    // const int c_l_a = 10;
    // const int c_l_b = 10;
    // cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;
    // cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;

    // cout << "全局变量g_a地址" << (int)&g_a << endl;
    // cout << "全局变量g_b地址" << (int)&g_b << endl;

    // static int s_a = 10;
    // static int s_b = 10;
    // cout << "静态变量s_a地址" << (int)&s_a << endl;
    // cout << "静态变量s_b地址" << (int)&s_b << endl;

    // cout << "全局常量cg_a地址" << (int)&c_g_a << endl;
    // cout << "全局常量cg_b地址" << (int)&c_g_b << endl;

    // cout << "字符串常量地址为： " << (int)&"hello world" << endl;
    // cout << "字符串常量地址为： " << (int)&"hello world1" << endl;

    // int *p = func();
    // cout << *p << endl;
    // cout << *p << endl;

    // delete p;
    // cout << *p << endl; // 报错，释放的空间不可访问

    // // 开辟空间
    // int *arr = new int[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = i + 100;
    //     cout << arr[i] << endl;
    // }

    // 引用
    // int a = 10;
    // int &b = a;
    // cout << "a = " << a << endl; // 10
    // cout << "b = " << b << endl; // 10

    // a = 20;
    // cout << "a,b = " << a << "," << b << endl; // a,b = 20,20
    // b = 30;
    // cout << "a,b = " << a << "," << b << endl; // a,b = 30,30

    // int a = 10;
    // int b = 20;

    // // 地址传递
    // swap1(&a, &b);
    // cout << "a,b=" << a << "," << b << endl; // a,b=20,10

    // // 引用传递
    // swap2(a, b);
    // cout << "a,b=" << a << "," << b << endl; // a,b=10,20
    //  通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单

    // 不能返回局部变量引用
    // int &ref = test01();  // 编译会报错
    // cout << "ref=" << ref << endl;
    // cout << "ref = " << ref << endl;

    // 如果函数做左值，那么必须返回引用
    // int &ref2 = test02();
    // cout << "ref2 = " << ref2 << endl; // 10
    // cout << "ref2 = " << ref2 << endl; // 10
    // test02() = 1000;
    // cout << "ref2 = " << ref2 << endl; // 1000
    // cout << "ref2 = " << ref2 << endl; // 1000

    // int a = 10;
    // int &ref = a;       // 等效于 int *const ref = &a;   指针常量： 指向不可改，可以赋值
    // const int &ref = a; // 等效于  const int * const ref = &a ;  常量指针：不可修改值

    //  函数重载 ：函数名可以相同，提高复用性
    //      函数重载满足条件：
    //      同一个作用域下
    //      函数名称相同
    //      函数参数类型不同 或者 个数不同 或者 顺序不同
    //   函数的返回值不可以作为函数重载的条件

    // 类和对象
    // 面向对象三大特性：封装、继承、多态

    // 封装：
    //     封装的意义：
    //      将属性和行为作为一个整体，表现生活中的事物
    //      将属性和行为加以权限控制

    // Circle c1;
    // c1.m_r = 5;
    // cout << "c1的周长为：" << c1.calculateZC() << endl; // 31.4
    // Student stu;
    // stu.setName("lvxiaobu");
    // stu.setId(11);
    // stu.showInfo();

    // 封装意义二： 控制权限

    // 三种权限
    // 公共权限  public     类内可以访问  类外可以访问
    // 保护权限  protected  类内可以访问  类外不可以访问
    // 私有权限  private    类内可以访问  类外不可以访问

    // Person p1; // 调用无参构造函数
    // p1.setAge(160);
    // string s1 = "111111";
    // Person p2(s1, 15, 180); // 括号法，常用
    // cout << "age: " << p2.getAge() << endl;
    // Person p3 = Person(s1, 200, 160); // 显式法

    // Person p5(s1, 100, 160);

    // // 如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    // Person p6(p5);
    // cout << "p6 age:" << p6.getAge() << endl;
    // cout << "p5的年龄： " << p5.p_age << " 身高： " << *p5.p_height << endl; // p5的年龄： 100 身高： 160
    // cout << "p6的年龄： " << p6.p_age << " 身高： " << *p6.p_height << endl; // p6的年龄： 100 身高： 160

    Teacher th("吕小布",15,1889610101);
    th.printTeacher();


}
