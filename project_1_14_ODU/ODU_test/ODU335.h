#pragma once
#include "ODU.h"
#include <iostream>

class ODU335: public ODU
{
public:
    ODU335();
    bool heartBeat();
};