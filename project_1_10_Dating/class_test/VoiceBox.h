#pragma once
#include <iostream>

class VoiceBox
{
    public:
    VoiceBox()
    {
        std::cout << __FUNCTION__ << std::endl;
    };
    ~VoiceBox(){
        std::cout << __FUNCTION__ << std::endl;
    };
};