#include <sstream>
#include "Engine.h"



Engine::Engine()
{
}

Engine::Engine(const string & brand, float version)
{
	this->brand = brand;
	this->version = version;
}


Engine::~Engine()
{
}

string Engine::description() const
{
	stringstream ret;
	ret << "品牌:" << brand << "-型号:" << version;
	return ret.str();
	return string();
}
