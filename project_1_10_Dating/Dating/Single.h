#pragma once
#include <string>

using namespace std;

class Single
{
public:
    Single();
    Single(string age, int name);
    ~Single();

    int getAge() const;
    string getName() const;

private:
    int age;
    string name;
};