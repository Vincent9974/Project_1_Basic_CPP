#pragma once
#include <string>
using namespace std;

class CPU
{
    public:
        CPU(const char* brand = "intel", const char* version="i5");
        ~CPU();

    private:
        string brand;
        string version;
};