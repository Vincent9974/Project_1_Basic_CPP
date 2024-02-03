#include "Girl.h"
#include "Boy.h"
#include <sstream>
#include <iostream>
#include "Single.h"
#include <iomanip>

#define FACE_VALUE_FACTOR 100 //颜值系数

Girl::Girl()
{
    // age = 0;
    // name = "";
    FaceValue = 0;
};

Girl::Girl(int age, string name, int FaceValue):Single(name,age)
{
    // this->age = age;
    // this->name = name;
    this->FaceValue = FaceValue;
    cout << "GirlInit" << endl;
}

Girl::~Girl()
{
}

// int Girl::getAge() const
// {
//     return age;
// }

// string Girl::getName() const
// {
//     return name;
// }

int Girl::getFaceValue() const
{
    return FaceValue;
}

string Girl::description() const
{
    stringstream ss;
    ss <<"性别:女\t\t\t姓名:"<< getName()  << "\t\t\t颜值:" << setw(3) << setiosflags(ios::left) << getFaceValue() << "\t\t\t年龄:" << getAge();
    return ss.str();
}

void Girl::inputGirls(vector<Girl>& girls)
{
    int age;
    int FaceValue;
    string name;

    int n = 1;
    while(1)
    {
        cout << "请输入第" << n << "位女嘉宾的年龄:";
        cin  >> age;
        if(age == 0)
        {
            break;
        }
        cout << "请输入第" << n << "位女嘉宾的姓名:";
        cin >> name;

        cout << "请输入第" << n << "位女嘉宾的颜值打分:";
        cin >> FaceValue;

        n++;
        girls.push_back(Girl(age,name,FaceValue));
    }
}

void Girl::inputGirl(Girl &girl)
{
    int age;
    int FaceValue;
    string name;


    cout << "请输入女嘉宾的年龄:";
    cin  >> age;

    cout << "请输入女嘉宾的姓名:";
    cin >> name;

    cout << "请输入女嘉宾的颜值:";
    cin >> FaceValue;

    girl = Girl(age, name ,FaceValue);
}


bool Girl::satisfied(const Boy& s) const
{
    if(s.getSalary() >= FaceValue * FACE_VALUE_FACTOR)
    {
        return true;
    }
    else
    {
        return false;
    }
}