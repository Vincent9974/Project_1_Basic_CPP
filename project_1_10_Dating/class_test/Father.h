#pragma once
#include <string>

using namespace std;

class Father
{
public:
    Father(const char* name, int age);
    ~Father();
    int getAge();
    string getName();
    string description();

protected:
    int age;
    string name;
};