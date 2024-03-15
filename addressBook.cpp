#include <iostream>
#include <string> // string 头文件
using namespace std;

#define Max 1000 // 最大人数
// 菜单界面
void showMenu()
{
    cout << "********************" << endl;
    cout << "*** 1、添加联系人 ***" << endl;
    cout << "*** 2、显示联系人 ***" << endl;
    cout << "*** 3、删除联系人 ***" << endl;
    cout << "*** 4、查找联系人 ***" << endl;
    cout << "*** 5、修改联系人 ***" << endl;
    cout << "*** 6、清空联系人 ***" << endl;
    cout << "*** 0、退出通讯录 ***" << endl;
    cout << "********************" << endl;
}

struct Person
{
    string m_Name;  // 姓名
    int m_Sex;      // 性别
    int m_Age;      // 年龄
    string m_Phone; // 电话
    string m_Addr;  // 住址
};

struct AddressBooks
{
    struct Person personArray[Max]; // 通讯录中保存的联系人数组
    int m_Size;                     // 通讯录中人员个数
};

void addPerson(AddressBooks *abs)
{
    if (abs->m_Size == Max)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        string name = "";
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout << "请输入性别:" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;

        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }

            cout << "输入有误，请重新输入";
        }

        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        string phone = "";
        cout << "请输入电话号码：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        string address = "";
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++;

        cout << "添加成功！" << endl;
        system("pause");
        system("cls");
    }
}

void showPerson(AddressBooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空";
    }
    else
    {

        cout << " 姓名 "
             << "    "
             << "性别"
             << "    "
             << "年龄"
             << "    "
             << "电话"
             << "    "
             << "住址" << endl;

        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << abs->personArray[i].m_Name << "    " << abs->personArray[i].m_Sex << "    " << abs->personArray[i].m_Age << "    " << abs->personArray[i].m_Phone << "    " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause");
    system("cls");
}

int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
            break;
        }
    }

    return -1;
};

void deletePerson(AddressBooks *abs)
{
    cout << "请输入你要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }

        abs->m_Size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void findPerson(AddressBooks *abs)
{
    cout << "请输入你要查找的人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "性别：" << abs->personArray[ret].m_Sex << "年龄：" << abs->personArray[ret].m_Age << "联系方式” " << abs->personArray[ret].m_Phone << "地址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void modifyPerson(AddressBooks *abs)
{
    cout << "请输入你要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        int sex = 0;
        cout << "请输入性别" << endl;
        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }

            cout << "输入有误，请重新输入" << endl;
        }

        int age = 0;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        string phone = "";
        cout << "请输入联系电话" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        string address = 0;
        cout << "请输入地址" << endl;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功！" << endl;
    }
};

void cleanPerson(AddressBooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
};

int main()
{

    int select = 0;
    // 创建通讯录
    AddressBooks abs;
    abs.m_Size = 0; // 初始化通讯录中人数
    while (true)
    {
        showMenu();
        cout << "请选择:";
        cin >> select;
        switch (select)
        {
        case 1: // 添加联系人
            addPerson(&abs);
            break;
        case 2: // 显示联系人
            showPerson(&abs);
            break;
        case 3: // 删除联系人
            deletePerson(&abs);
            break;
        case 4: // 查找联系人
            findPerson(&abs);
            break;
        case 5: // 修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;

        default:
            break;
        }
    }

    system("pause");
    return 0;
};