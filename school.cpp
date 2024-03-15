#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
    string tName = "教师";
    string sName = "学生";
    string nameSeed = "ABCDE";

    for (int i = 0; i < len; i++)
    {
        tArray[i].name = tName + nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].name = sName + nameSeed[j];
            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
};

void printTeacher(Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << tArray[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << tArray[i].sArray[j].name << ":" << tArray[i].sArray[j].score << endl;
        }
    }
};

struct hero
{
    string name;
    int age;
    string sex;
};

int main()
{
    // srand((time(0))); // 使系统每次随机生成的数字不一样
    srand((unsigned int)time(NULL)); // 随机数种子 头文件 #include <ctime>

    Teacher tArr[3];

    hero heroArr[5] = {
        {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
    };

   
    int len = sizeof(tArr) / sizeof(Teacher);
    int lenh = sizeof(heroArr) / sizeof(hero);


  

    allocateSpace(tArr, len); // 创建数据
    printTeacher(tArr, len);  // 创建数据
};
