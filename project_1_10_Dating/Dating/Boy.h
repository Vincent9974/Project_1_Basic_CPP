#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Single.h"

using namespace std;

class Girl;

class Boy : public Single
{
public:
    Boy();
    Boy(int age, string name, int salary);
    ~Boy();

    Boy(const Boy& other);
    int getSalary() const;
    // string getName() const;
    // int getAge() const;

    bool satisfied(const Girl& s) const;
    string description() const;

    // 输入多个男孩信息
    static void inputBoys(vector<Boy> &boys);
    static void inputBoy(Boy& boy);
    bool operator>(const Boy& boy);
    friend ostream& operator<<(ostream& os, const Boy& boy);

private:
    // int age;
    // string name;
    int salary;

};

ostream& operator<<(ostream& os, const Boy& boy);