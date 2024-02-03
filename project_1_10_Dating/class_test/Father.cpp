#include "Father.h"
#include <iostream>
#include <sstream>
using namespace std;


Father::Father(const char *name, int age)
{
    cout << __FUNCTION__ << endl;
    this->name = name;
    this->age = age;
}

Father::~Father()
{
}

int Father::getAge()
{
    return age;
}

string Father::getName()
{
    return name;
}

string Father::description()
{
    stringstream ret;
    ret << "name: " << name << "age: " << age;
    return ret.str();
}
