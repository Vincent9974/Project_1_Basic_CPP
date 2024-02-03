#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU(const char* brand, const char* version)
{
    this->brand = brand;
    this->version = version;
    std::cout << __FUNCTION__ << std::endl;
}

CPU::~CPU()
{
    cout << __FUNCTION__ << endl;
}
