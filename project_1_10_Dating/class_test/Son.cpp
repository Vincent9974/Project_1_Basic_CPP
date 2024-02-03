#include "Son.h"
#include <iostream>
#include <sstream>
using namespace std;

Son::Son(const char *name, int age, const char* game) :  Father(name, age)
{
    cout << __FUNCTION__ << endl;
    this->game = game;
}

Son::~Son(){}

string Son::getGame()
{
    return game;
}

string Son::description()
{
	stringstream ret;
	cout << name << endl;
	// 子类的成员函数中, 不能访问从父类继承的private成员
	ret << "name:" << getName() << " age:" << getAge() << " game:" << game;
	return ret.str();

};
