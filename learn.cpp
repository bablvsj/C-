#include <iostream>
using namespace std;

int g_a = 10; // 全局变量
int g_b = 10;
const int c_g_a = 10; // 全局常量
const int c_g_b = 10;

int *func()
{                         // 堆区数据利用new关键字进行开辟内存
    int *a = new int(10); // 利用new创建的数据，会返回该数据对应的类型的指针
    return a;
}

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

    int *p = func();
    cout << *p << endl;
    cout << *p << endl;

    delete p;
    cout << *p << endl; // 报错，释放的空间不可访问

    // 开辟空间
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
        cout << arr[i] << endl;
    }

    // for (int i = 0; i < 10; i++)
	// {
	// 	cout << arr[i] << endl;
	// }
}
