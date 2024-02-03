#pragma once
#include <string>
#include "ComputerService.h"
using namespace std;

class Computer
{
public:
    Computer();
    string description();

    //使用全局函数友元函数访问
    friend void upgrade(Computer* computer);

    //使用类的成员函数作为友元函数访问
    // friend void ComputerService::upgrade(Computer* computer);


private:
    string cpu;
    friend class ComputerService;
};