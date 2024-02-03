#include "Database.h"
#include <fstream>
#include <iostream>
using namespace std;

#define BOYS_FILE "boys.txt"
#define GIRLS_FILE "girls.txt"

Database::Database()
{
}

void Database::init()
{
    initBoysFromFile();
    initGirlsFromFile();
}

void Database::autoPair()
{
    cout << endl
         << "自动配对结果:" << endl;
    string line(100, '-');
    cout << line << endl;
    for (int i = 0; i < boys.size(); i++)
    {
        for (int j = 0; j < girls.size(); j++)
        {
            if (boys[i].satisfied(girls[j]) &&
                girls[j].satisfied(boys[i]))
            {
                cout << boys[i].description() << endl;
                cout << girls[j].description() << endl;
                cout << line << endl;
            }
        }
    }
}

void Database::print()
{
    cout << "男嘉宾信息:\n";
    for (int i = 0; i < boys.size(); i++)
    {
        cout << boys[i].description() << endl;
    }
    cout << "女嘉宾信息:\n";
    for (int i = 0; i < girls.size(); i++)
    {
        cout << girls[i].description() << endl;
    }
}

void Database::addOne(Boy &boy)
{
    boys.push_back(boy);
    cout << "自动配对结果:" << endl;
    string line(100, '-');
    cout << line << endl;
    

    for (int j = 0; j < girls.size(); j++)
    {
        if (boy.satisfied(girls[j]) &&
            girls[j].satisfied(boy))
        {
            cout << boy.description() << endl;
            cout << girls[j].description() << endl;
            cout << line << endl;
        }
    }
}

void Database::addOne(Girl &girl)
{
    girls.push_back(girl);
    cout << "自动配对结果:" << endl;
    string line(100, '-');
    cout << line << endl;
    

    for (int j = 0; j < boys.size(); j++)
    {
        if (girl.satisfied(boys[j]) &&
            boys[j].satisfied(girl))
        {
            cout << girl.description() << endl;
            cout << boys[j].description() << endl;
            cout << line << endl;
        }
    }
}



void Database::initBoysFromFile()
{
    ifstream stream;
    stream.open(BOYS_FILE);
    if (!stream.is_open())
    {
        cout << "请输入男嘉宾数据:" << endl;
        Boy::inputBoys(this->boys);
        saveBoys();
        stream.close();
        return;
    }

    while (1)
    {
        string line;
        char name[64] = "";
        int salary;
        int age;
        getline(stream, line);

        if (stream.eof())
        {
            break;
        }

        // 解析line
        int ret = sscanf_s(line.c_str(), "性别:男 姓名:%s\t\t\t薪资:%d\t\t\t年龄:%d",
                           name, sizeof(name), &salary, &age);
        if (ret <= 0)
        {
            cout << "男数据格式失败" << endl;
            exit(1);
        }

        boys.push_back(Boy(age, string(name), salary));
    }
}

void Database::initGirlsFromFile()
{
    ifstream stream;
    stream.open(GIRLS_FILE);
    if (!stream.is_open())
    {
        cout << "请输入女嘉宾数据:" << endl;
        Girl::inputGirls(this->girls);
        saveGirls();
        stream.close();
        return;
    }

    while (1)
    {
        string line;
        char name[64] = "";
        int Facevalue;
        int age;
        getline(stream, line);

        if (stream.eof())
        {
            break;
        }

        // 解析line
        int ret = sscanf_s(line.c_str(), "性别:女 姓名:%s\t\t\t颜值:%d\t\t\t年龄:%d",
                           name, sizeof(name), &Facevalue, &age);
        if (ret <= 0)
        {
            cout << "女数据格式失败" << endl;
            exit(1);
        }

        girls.push_back(Girl(age, string(name), Facevalue));
    }
}

void Database::saveBoys()
{
    ofstream stream;
    stream.open(BOYS_FILE);
    if (!stream.is_open())
    {
        cout << BOYS_FILE << "写入失败" << endl;
        exit(1);
    }

    for (int i = 0; i < boys.size(); i++)
    {
        stream << boys[i].description() << endl;
    }
    stream.close();
}

void Database::saveGirls()
{
    ofstream stream;
    stream.open(GIRLS_FILE);
    if (!stream.is_open())
    {
        cout << GIRLS_FILE << "写入失败" << endl;
        exit(1);
    }

    for (int i = 0; i < girls.size(); i++)
    {
        stream << girls[i].description() << endl;
    }
    stream.close();
}
