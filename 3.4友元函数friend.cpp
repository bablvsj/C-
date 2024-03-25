#include <iostream>
#include <string> // string 头文件
using namespace std;

class Building;

class goodGay2
{
private:
    Building *building;

public:
    goodGay2();
    void visit();
};

class goodGay3
{
    Building *building3;

public:
    goodGay3();
    void visit1();
    void visit4();
};

class Building
{
    friend void goodGay(Building *building); // 全局函数做友元
    friend class goodGay2;                   // 类做友元
    friend void goodGay3::visit1();          // 成员函数做友元
private:
    string m_BedRoom;

public:
    string m_SittingRoom; // 客厅
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
};

void goodGay(Building *building) // 全局函数做友元
{
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

goodGay2::goodGay2()
{
    building = new Building;
}

void goodGay2::visit()
{
    cout << "好基友2正在访问" << building->m_SittingRoom << endl;
    cout << "好基友2正在访问" << building->m_BedRoom << endl;
};

goodGay3::goodGay3()
{
    building3 = new Building;
}

void goodGay3::visit1()
{
    cout << "好基友3正在访问：" << building3->m_SittingRoom << endl;
    cout << "好基友3正在访问：" << building3->m_BedRoom << endl;
};

void goodGay3::visit4(){
    // cout << "好基友3正在访问：" << building3->m_SittingRoom << endl;
    // cout << "好基友3正在访问：" << building3->m_BedRoom << endl;
};

int main()
{
    // 友元函数的目的：让一个函数或者类能访问另一个类中的私有成员。

    // 友元的三种实现
    Building b;
    goodGay(&b);

    // 类做友元
    goodGay2 g2;
    g2.visit();

    // 成员函数做友元
    goodGay3 g3;
    g3.visit1();
    return 0;
}