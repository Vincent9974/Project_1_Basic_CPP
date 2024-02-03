#include "Pork.h"
#include <sstream>

Pork::Pork(int weight)
{
	this->weight = weight;
}

std::string Pork::description(void)
{
	std::stringstream ret;
	ret << weight << "斤猪肉";
	return ret.str();
}
