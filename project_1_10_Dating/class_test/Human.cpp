#include <iostream>
#include <windows.h>
#include <string>
#include "Human.h"
using namespace std;



void Human::eat()
{
    cout << "eat" << endl;
}

void Human::sleep()
{
    cout << "sleep" << endl;
}

void Human::play()
{
    cout << "play" << endl;
}

void Human::work()
{
    cout << "work" << endl;
}

string Human::getName()
{
    return name;
}

int Human::getAge()
{
    return age;
}

int Human::getSalary()
{
    return salary;
}

// 血型初始化列表
Human::Human(){
    name = "null";
    age = 18;
    salary = 10000;
    HumanCount ++;
}

Human::Human(const Human &other)
{
    cout << "调用拷贝构造函数" << endl;
    name = other.name;
    age = other.age;
    salary = other.salary;
    HumanCount++;
}

const char *Human::getAddr()
{
    return addr;
}

Human &Human::operator=(const Human &man)
{
    cout << "调用" << __FUNCTION__ << endl;
    if (this == &man)
    {
        return *this; // 检测是不是对自己赋值：比如 h1 = h1;
    }

    // 如果有必要，需要先释放自己的资源（动态内存）
    // delete addr;
    // addr = new char[ADDR_LEN];

    // 深拷贝

    // 处理其他数据成员
    name = man.name;
    age = man.age;
    salary = man.salary;

    // 返回该对象本身的引用， 以便做链式连续处理，比如 a = b = c;
    return *this;
}

// 对类的静态数据成员进行初始化
int Human::HumanCount = 0;



Human::Human(int age, int salary, string BT):bloodType(BT)
{
    cout << "自定义构造函数" << endl;
    this->age = age;
    this->salary = salary;
    name = "vincent";
    HumanCount++;
}

int Human::getHumanCount(){
    return HumanCount ;
}

void Human::description() const {
	cout << "age:" << age
		<< " name:" << name
		<< " salary:" << salary
		<< " addr:" << addr 
		<< " bloodType:" << bloodType << endl; //其他成员函数可以“读”const变量
}


class Person {
public:
    // 构造函数
    Person(const std::string& name, int age) {
        // 使用 this 指针在构造函数中初始化成员变量
        this->name = name;
        this->age = age;
        std::cout << "Person object created for: " << this->name << std::endl;
    }

    // 成员函数，显示个人信息
    void displayInfo() {
        // 使用 this 指针访问成员变量
        std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
    }

    // 成员函数，比较两个 Person 对象的年龄
    bool isOlderThan(const Person& other) {
        // 使用 this 指针和参数对象比较年龄
        return this->age > other.age;
    }

private:
    std::string name;
    int age;
};

