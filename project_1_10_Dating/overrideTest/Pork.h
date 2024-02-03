#pragma once
#include <iostream>

class Pork
{
public:
	Pork(int weight);
	std::string  description(void);

private:
	int weight = 0;
};
