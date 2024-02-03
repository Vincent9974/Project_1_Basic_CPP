#pragma once
#include "CPU.h"
#include "VoiceBox.h"

class Computer
{
    public:
        Computer(const char* cpuBrand, 
        const char* cpuVersion,int hardDisk, int memory);
        ~Computer();
        void addVoiceBox(VoiceBox* vb);
    private:
        CPU cpu;
        VoiceBox* vb;
        int hardDisk;
        int memory;
};