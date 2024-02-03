#include "Computer.h"
#include <iostream>
using namespace std;

Computer::Computer(const char *cpuBrand, const char* cpuVersion, int hardDisk, int memory):cpu(cpuBrand,cpuVersion)
{

    this->hardDisk = hardDisk;
    this->memory = memory;
    cout << __FUNCTION__ << endl;
}


Computer::~Computer()
{
	std::cout << __FUNCTION__ << std::endl;
}

void Computer::addVoiceBox(VoiceBox* vb)
{
    this->vb = vb;
}