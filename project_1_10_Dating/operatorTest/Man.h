#pragma once
#include "Boy.h"

class Man
{
public:
	Man(const char *name, int age, int salary);
	Man(const Boy& boy);
	~Man();
    friend ostream& operator<<(ostream &os, const Man& man);

private:
	char* name;
	int age;
	int salary;
};

ostream& operator<<(ostream &os, const Man& man);