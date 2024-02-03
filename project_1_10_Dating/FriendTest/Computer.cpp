#include "Computer.h"
#include <sstream>


Computer::Computer()
{
    cpu = "i5";
}

string Computer::description()
{
    std::stringstream ret;
    ret << "CPU" << cpu;
    return ret.str();
}
