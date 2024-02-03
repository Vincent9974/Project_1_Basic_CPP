#include "Boy.h"
#include "Girl.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define SALARY_FACTOR 0.006

Boy::Boy(){};

Boy::Boy(const Boy &other):Single(other.getName(), other.getAge())
{
    salary = other.salary;
    // name = other.name;
    // age = other.age;
}

Boy::Boy(int age, string name, int salary) : Single(name, age)
{
    // this->age = age;
    // this->name = name;
    this->salary = salary;
}

Boy::~Boy()
{
}

// int Boy::getAge() const
// {
//     return age;
// }

// string Boy::getName() const
// {
//     return name;
// }

int Boy::getSalary() const
{
    return salary;
}

bool Boy::satisfied(const Girl &s) const
{
    if (s.getFaceValue() >= salary * SALARY_FACTOR)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Boy::description() const
{
    stringstream ret;
    // 格式
    // 性别:男\t\t\t姓名:vc\t\t\t薪资:35000\t\t\t年龄:25
    ret <<"性别:男\t\t\t姓名:"<< getName() << "\t\t\t薪资:" << getSalary() << "\t\t\t年龄:" << getAge();
    return ret.str();
}

void Boy::inputBoys(vector<Boy> &boys)
{
    int age;
    int salary;
    string name;
    int n =1;
    while(1)
    {
        cout << "请输入第" << n << "位男嘉宾的年龄:";
        cin  >> age;
        if(age == 0)
        {
            break;
        }
        cout << "请输入第" << n << "位男嘉宾的姓名:";
        cin >> name;

        cout << "请输入第" << n << "位男嘉宾的薪资:";
        cin >> salary;

        n++;
        boys.push_back(Boy(age,name,salary));
    }

}

void Boy::inputBoy(Boy &boy)
{
    int age;
    int salary;
    string name;


    cout << "请输入男嘉宾的年龄:";
    cin  >> age;

    cout << "请输入男嘉宾的姓名:";
    cin >> name;

    cout << "请输入男嘉宾的薪资:";
    cin >> salary;

    boy = Boy(age, name ,salary);
    
}

bool Boy::operator>(const Boy &boy)
{
    return salary > boy.salary;
}

// ostream& operator<<(ostream& os, const Boy& boy) {
// 	os << "性别:男"
// 		<< "\t\t\t姓名:" << boy.name
// 		<< "\t\t\t薪资:" << boy.salary
// 		<< "\t\t\t年龄:" << boy.age;
// 	return os;
// }
