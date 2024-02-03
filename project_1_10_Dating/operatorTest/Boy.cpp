#include "Boy.h"
#include <string.h>
#include <sstream>

int Boy::LAST_ID = 0;

Boy::Boy(const char *name, int age, int salary, int darkHorse)
{
    if (!name)
    {
        name = "未命名";
    }
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);

    this->age = age;
    this->salary = salary;
    this->darkHorse = darkHorse;
    this->id = ++LAST_ID;
}

Boy::~Boy()
{
    if (name)
    {
        delete name;
    }
}

Boy::Boy(int salary)
{
    const char* defaultName = "未命名";
    name = new char[strlen(defaultName) + 1];
    strcpy_s(name, strlen(defaultName) + 1, defaultName);

    age = 0;
    this->salary = salary;
    this->id = ++LAST_ID;
}

Boy::Boy(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	age = 0;
	this->salary = 0;
	darkHorse = 0;
	this->id = ++LAST_ID;
}

Boy &Boy::operator=(const Boy &boy)
{
    if (name)
    {
        delete name;
    }
    name = new char[strlen(boy.name) + 1];
    strcpy_s(name, strlen(boy.name) + 1, boy.name);

    this->age = boy.age;
    this->salary = boy.salary;
    this->darkHorse = boy.darkHorse;

    return *this;
}

bool Boy::operator>(const Boy &boy)
{
    // 设置比较规则：
    // 薪资 * 黑马系数 + (100-年龄）*100
    if (power() > boy.power())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Boy::operator<(const Boy &boy)
{
    if (power() < boy.power())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Boy::operator==(const Boy &boy)
{
    if (power() == boy.power())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// int Boy::operator[](std::string index)
// {
//     if (index == "age")
//     {
//         return age;
//     }
//     else if (index == "salary")
//     {
//         return salary;
//     }
//     else if (index == "darkHorse")
//     {
//         return darkHorse;
//     }
//     else if (index == "power")
//     {
//         return power();
//     }
//     else
//     {
//         return -1;
//     }
// }

// int Boy::operator[](int index)
// {
//     if (index == 0)
//     {
//         return age;
//     }
//     else if (index == 1)
//     {
//         return salary;
//     }
//     else if (index == 2)
//     {
//         return darkHorse;
//     }
//     else if (index == 3)
//     {
//         return power();
//     }
//     else
//     {
//         return -1;
//     }
// }

// ostream &Boy::operator<<(ostream &os) const
// {
//     os << "ID:" << id << "\t姓名:" << name << "\t年龄:"
//     << age << "\t薪资:" << salary << "\t黑马系数:" << darkHorse;
//     return os;
// }

Boy::operator int() const
{
    return power();
}

Boy::operator char *() const
{
    return name;
}

std::string Boy::description(void)
{
    std::stringstream ret;
    ret << "ID:" << id << "\t姓名:" << name << "\t年龄:" << age << "\t薪资:"
        << salary << "\t黑马系数:" << darkHorse;
    return ret.str();
}

istream& operator>>(istream& is, Boy& boy)
{
    string name2;
    is >> name2 >> boy.age >> boy.salary >> boy.darkHorse;
    boy.name = (char*)malloc((name2.length()+1) * sizeof(char));
    strcpy_s(boy.name, name2.length() + 1, name2.c_str());
    return is;
}

int Boy::power() const
{
    return salary * darkHorse + (100 - age) * 1000;
}
