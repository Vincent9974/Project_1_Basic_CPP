#include "Tire.h"
#include <sstream>



Tire::Tire(const string &brand)
{
	this->brand = brand;
	this->pressure = 2.5; 
}


Tire::~Tire()
{
}

string Tire::descripton() const
{
	stringstream ret;
	ret << "品牌:" << brand  << "-胎压:" << pressure;
	return ret.str();
}

string Tire::getBrand() const
{
	return brand;
}

float Tire::getPressure() const
{
	return pressure;
}
