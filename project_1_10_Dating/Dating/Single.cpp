#include "Single.h"

Single::Single()
{
	this->name = "张三";
	this->age = 0;
}

Single::Single(string name, int age)
{
	this->name = name;
	this->age = age;
}


Single::~Single()
{
}

int Single::getAge() const {
	return age;
}

string Single::getName() const {
	return name;
}
