#pragma once
#include <iostream>
#include <string>
using namespace std;




class Human
{
public:
    // 默认构造函数
    // Human(){
    //     name = "张三";
    //     age = 19;
    //     salary = 15000;
    // }

    // 拷贝构造函数, 创建一个对象, 用于创建一个对象,该对象是对已有对象的拷贝

    // 默认构造函数
    Human();

    Human(const Human &other);

    // Human();
    Human(int age, int salary, string bloodType);
    Human &operator=(const Human &);

    void eat();
    void sleep();
    void play();
    void work();
    string getName();
    int getAge();
    int getSalary();
    const char *getAddr();
    static int getHumanCount();
    void description() const;

private:
    string name;
    int age;
    int salary;
    char *addr;
    static int HumanCount;
    const string bloodType = "A"; //C++ 11,类内初始值
};

class MyResource
{
public:
    MyResource()
    {
        cout << "Resource allocated" << endl;
    }
    ~MyResource()
    {
        cout << "Resource deallocated" << endl;
    }

};


class MyClass
{
public:
    // 默认构造函数
    MyClass()
    {
        std::cout << "Default constructor called" << std::endl;
        // 可以在构造函数中进行初始化操作
        myValue = 0;
    }

    // 带参数的构造函数
    MyClass(int value)
    {
        std::cout << "Parameterized constructor called" << std::endl;
        myValue = value;
    }

    // 成员函数
    void display()
    {
        std::cout << "Value: " << myValue << std::endl;
    }

private:
    int myValue;
    MyResource resource;
};
