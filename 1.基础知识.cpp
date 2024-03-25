#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 值传递
void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递 （通过指针）
void swapPoint(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(int arr[], int len) // int *arr 可以写成  int arr[]

{

    cout << arr << endl; // 0x61fed8 , 数组名传入到函数作为参数时，被退化为指向首元素的指针
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 结构体
struct student
{
    string name;
    int age;
    int score;
} stu3; // 结构体变量创建方式3

struct teacher
{
    int id;             // 职工编号
    string name;        // 职工姓名
    int age;            // 教师姓名
    struct student stu; // 子结构体 学生
};

// 值传递
void printStudent(student stu)
{
    stu.age = 22;
    cout << "子函数中 姓名:" << stu.name << " age:" << stu.age << " score:" << stu.score << endl;
};

// 地址传递
void printStudent2(const student *stu) // const使用场景：加const防止函数体中的误操作
{
    // stu->age = 66; // 加了const 不可修改
    // stu->score = 700;
    cout << "子函数中 姓名:" << stu->name << " age:" << stu->age << " score:" << stu->score << endl;
};

int main()
{
    // 整型
    // cout << "short 类型所占内存空间：" << sizeof(short) << endl;
    // cout << "int   类型所占内存空间：" << sizeof(int) << endl;
    // cout << "long  类型所占内存空间：" << sizeof(long) << endl;
    // cout << "long long 类型所占内存空间：" << sizeof(long long) << endl;

    // 浮点型
    // cout << "float 类型所占内存空间：" << sizeof(float) << endl;
    // cout << "double类型所占内存空间：" << sizeof(double) << endl;
    // float f1 = 3.14f;
    // double d1 = 3.14;
    // cout << f1 << endl;
    // cout << d1<< endl;
    // float f2 = 3e2; // 3 * 10 ^ 2
    // cout << "f2 = " << f2 << endl;
    // float f3 = 3e-2;  // 3 * 0.1 ^ 2
    // cout << "f3 = " << f3 << endl;

    // 字符型
    // char ch = 'a';
    // char ch1 = 'A';
    // cout << ch << endl;
    // cout << sizeof(char) << endl;
    // //ch = "abcde"; //错误，不可以用双引号
    // //ch = 'abcde'; //错误，单引号内只能引用一个字符
    // cout<<"小写a：" << (int)ch << endl;  //查看字符a对应的ASCII码 97
    // cout<<"大写A：" << (int)ch1 << endl;  //查看字符a对应的ASCII码 65
    // ch = 100; //可以直接用ASCII给字符型变量赋值
    // cout << ch << endl;  // d

    // 转义字符
    // cout << "\\" << endl;
    // cout << "\tHello" << endl;
    // cout << "\n" << endl;

    // 字符串型
    // char str1[] = "hello world";
    // cout << str1 << endl;
    // string str2 = "hello str2";
    // cout << str2 << endl;

    // bool 类型
    // bool flag = true;
    // cout << flag << endl;  // 1
    // flag = false;
    // cout << flag << endl; // 0
    // cout << sizeof(bool) << endl;   // 1

    // 数值的输入 cin
    // 作用：用于从键盘获取数据
    // int a = 0;
    // cout << "请输入整型变量：" << endl;
    // cin >> a;
    // cout << a << endl;
    // double d = 0;
    // cout << "请输入浮点型变量:" << endl;
    // cin >> d ;
    // cout << d << endl;

    // // 算术运算符
    // int a1 = 10;
    // int b1 = 20;
    // cout << a1 + b1 << endl;
    // cout << a1 - b1 << endl;
    // cout << a1 * b1 << endl;
    // cout << a1 / b1 << endl;  //两个整数相除结果依然是整数
    // //两个小数可以相除
    // double d1 = 0.5;
    // double d2 = 0.25;
    // cout << d1 / d2 << endl;
    // cout << 10 % 3 << endl;

    // //区别
    // //前置递增先对变量进行++，再计算表达式
    // int a2 = 10;
    // int b2 = ++a2 * 10;
    // cout << b2 << endl;
    // //后置递增先计算表达式，后对变量进行++
    // int a3 = 10;
    // int b3 = a3++ * 10;
    // cout << b3 << endl;

    // 选择结构
    // if 语句
    // int pigA = 0;
    // int pigB = 0;
    // int pigC = 0;
    // cout << "请分别输入三只猪的体重：" << endl;
    // cin >> pigA >> pigB >> pigC;
    // cout << "你输入的分数为：A:" << pigA << " B:" << pigB << " C:" << pigC << endl;
    // string text = pigA > pigB ? (pigA > pigC ? "pigA重" : "pigC重") : (pigB > pigC ? "pigB重" : "pigC重");
    // cout << text << endl;

    // switch case语句
    // int score = 0;
    // cout << "请给电影打分" << endl;
    // cin >> score;
    // switch (score)
    // {
    // case 10:
    // case 9:
    //     cout << "经典好片" << endl;
    //     break;
    // case 8:
    // case 7:
    //     cout << "还不错" << endl;
    //      break;
    // case 6:
    //     cout << "一般" << endl;
    //      break;
    // default:
    //     cout << "烂片" << endl;
    //     break;
    // }

    // 系统随机生成一个0~100的数，猜大小
    // srand((time(0)));  // 使系统每次随机生成的数字不一样
    // int num = 0;
    // int inum = 0;
    // cout << "系统已随机生成一个数，现在输入数字开始猜大小" << endl;
    // num = rand() % 100 + 1;
    // cout << num << endl;
    // cin >> inum;
    // cout << "终于答对了！" << endl;
    // if (inum > num)
    // {
    //     cout << "大了" << endl;
    // }
    // else if (inum < num)
    // {
    //     cout << "小了" << endl;
    // }
    // else
    // {
    //     cout << "bingo" << endl;
    // }

    // 乘法口诀表
    // for (int i = 1; i < 10; i++)
    // {
    //     for (int j = 1; j < 10; j++)
    //     {
    //         cout << i << "*" << j << "=" << i * j << " ";
    //     }
    //     cout << endl;
    // }

    // system("pause");
    // break 用于跳出循环
    // 出现在switch条件语句中，作用是终止case并跳出switch
    // 出现在循环语句中，作用是跳出当前的循环语句
    // 出现在嵌套循环中，作用是跳出最近的内层循环语句

    // 在嵌套循环语句中使用break，退出内层循环
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         if (j == 1)
    //         {
    //             break;
    //         }
    //         cout << "*"
    //              << " ";
    //     }
    //     cout << endl;
    // }

    // continue语句
    //  作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环。
    // for (int i = 0; i < 20; i++)
    // {
    //     if (i % 2 == 0 || i % 3 == 0)
    //     {
    //         continue;
    //     }
    //     cout << i << endl;
    // }

    // goto语句
    // 作用：可以无条件跳转语句
    // cout << "1" << endl;
    // goto FLAG;
    // cout << "2" << endl;
    // cout << "3" << endl;
    // cout << "4" << endl;
    // FLAG:
    // cout << "5" << endl;

    // 数组
    // int score[10] = {1, 2, 3, 4, 5, 6, 7};
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << score[i] << " ";
    // }
    // cout << endl;
    // cout << "整个数组所占内存空间为:" << sizeof(score) << endl;
    // cout << "每个元素所占内存空间为:" << sizeof(score[0]) << endl;
    // cout << "元素个数为:" << sizeof(score) / sizeof(score[0]) << endl;
    // cout << "元素的首地址为：" << score << endl;
    // cout << "元素的首地址为：" << (int)score << endl;
    // cout << "数组中的第一个元素为：" << (int)&score[0] << endl;
    // cout << "数组中第二个元素为:" << (int)&score[1] << endl;

    // 数组
    // int arr[5] = {300, 350, 200, 400, 250};
    // int alength = sizeof(arr) / sizeof(arr[0]);
    // int max = 0;
    // for (int i = 0; i < alength; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    // cout << "最重的小猪的体重为： " << max << endl;

    // 将数组逆序
    // int arr[5] = {1, 8, 3, 2, 5};
    // int alength = sizeof(arr) / sizeof(arr[0]);
    // int temp[alength] = {};
    // for (int i = 0; i < alength; i++)
    // {
    //     temp[alength - 1 - i] = arr[i];
    //     cout << arr[i] << " ";
    // }
    // for (int i = 0; i < alength; i++)
    // {
    //     cout << temp[i] << " ";
    // }

    // 二维数组
    // int arr[2][3] = {{1, 2, 3},
    //                  {4, 5, 6}};
    // cout << "二维数组大小：" << sizeof(arr) << endl;
    // cout << "二维数组一行大小：" << sizeof(arr[0]) << endl;
    // cout << "二维数组元素大小：" << sizeof(arr[0][0]) << endl;
    // cout << "二维数组行数：" << sizeof(arr) / sizeof(arr[0]) << endl;
    // cout << "二维数组列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
    // cout << "二维数组首地址：" << arr << endl;
    // cout << "二维数组第一行地址：" << arr[0] << endl;
    // cout << "二维数组第二行地址：" << arr[1] << endl;
    // cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
    // cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

    // int scores[3][3] =
    //     {
    //         {100, 100, 100},
    //         {90, 50, 100},
    //         {60, 70, 80},
    //     };
    // string names[3] = {"张三", "李四", "王五"};
    // for (int i = 0; i < 3; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < 3; j++)
    //     {
    //         sum += scores[i][j];
    //     }
    //     cout << names[i] << "同学总成绩为： " << sum << endl;
    // }

    // 值传递：
    // 所谓值传递，就是函数调用时实参将数值传入给形参
    // 值传递时，如果形参发生改变，并不会影响实参。

    // 指针变量
    // 数据类型 * 变量名
    // int a = 10;
    // int *p = &a;

    // 指针变量赋值
    // p = &a;
    // cout << "a的地址" << &a << endl;
    // cout << p << endl;

    // 指针的使用
    // 通过*操作指针变量指向的内存
    // cout << "*p = " << *p << endl;
    // 区别：
    // 普通变量存放的是数据，指针变量存放的是地址
    // 指针变量可以通过 * 操作符，操作指针变量指向的内存空间，这个过程成为解引用。

    // cout << sizeof(p) << endl;        // 4
    // cout << sizeof(char *) << endl;   // 4
    // cout << sizeof(float *) << endl;  // 4
    // cout << sizeof(double *) << endl; // 4
    // 所有指针类型在32位操作系统下是4个字节

    // int *q = NULL;
    // cout << *q << endl; // 访问空值指针报错

    // int * p1 = (int *)0x1100;
    // 访问野指针报错
    // cout << *p1 << endl;

    // const 修饰指针
    // const修饰指针有三种情况
    // int a = 10;
    // int b = 20;

    // const修饰的是指针（常量指针），指针指向可以改，指针指向的值不可以更改
    // const int *p1 = &a;
    // p1 = &b; // 正确
    // //*p1 = 100;  报错

    // const修饰的是常量（指针常量），指针指向不可以改，指针指向的值可以更改
    // int *const p2 = &a;
    // // p2 = &b; //错误
    // *p2 = 100; // 正确

    // const既修饰指针又修饰常量
    // const int *const p3 = &a;
    // p3 = &b; //错误
    //*p3 = 100; //错误

    // int *p1 = &a;       // 指针
    // const int *p2 = &b; // 常量指针
    // int *const p3 = &b; // 指针常量

    // 技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量

    // 指针和数组
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int *p = arr; // 指向数组的指针
    // for (int i = 0; i < 10; i++)
    // { // 利用指针遍历数组
    //     cout << *p << " ";
    //     p++;
    // }

    // 指针和函数
    // 利用指针作函数参数，可以修改实参的值
    // int aaa = 10;
    // int bbb = 20;
    // swapValue(aaa, bbb);
    // cout << aaa << " , " << bbb << endl; // 10 , 20
    // swapPoint(&aaa, &bbb);
    // cout << aaa << " , " << bbb << endl; // 20 , 10

    // 指针、数组、函数
    // 实现冒泡排序
    // int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(arr, len);
    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // 结构体
    // struct student std1;
    // std1.name = "lvxiaobu";
    // std1.age = 20;
    // std1.score = 660;
    // cout << std1.name << " " << std1.age << " " << std1.score << endl;

    // 结构体数组
    // struct student stuArr[] = {
    //     {"刘备", 25, 200},
    //     {"关羽", 18, 200},
    //     {"张飞", 17, 200},
    // };

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << stuArr[i].name << " " << stuArr[i].age << " " << stuArr[i].score << endl;
    // }

    // 结构化指针
    // 通过指针访问结构体中的成员

    struct student stu =
        {
            "吕布",
            20,
            250};

    // struct student *p = &stu;

    // p->score = 100;
    // p->age = 40;
    // p->name = "吕小布";
    // p.age = 100;
    // p->age
    // cout << stu.name << " " << stu.age << " " << stu.score << endl;

    // 结构体嵌套结构体
    // struct teacher t1;
    // t1.id = 10000;
    // t1.name = "老李";
    // t1.age = 50;
    // t1.stu.name = "小红";
    // t1.stu.age = 20;
    // t1.stu.score = 299;
    // cout << "教职工编号：" << t1.id << " 教职工姓名：" << t1.name << " 年龄：" << t1.age << endl;
    // cout << "学生姓名：" << t1.stu.name << " 学生年龄：" << t1.stu.age << " 学生成绩：" << t1.stu.score << endl;

    // 结构体做函数参数
    // 将结构体作为参数向函数中传递
    // 传递方式有两种：1.值传递 2.地址传递
    // 值传递
    printStudent(stu);
    printStudent2(&stu);

    // return EXIT_SUCCESS;
}
