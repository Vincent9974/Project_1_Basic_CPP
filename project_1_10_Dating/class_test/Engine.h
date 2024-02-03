#pragma once
#include <string>

using namespace std;

class Engine
{
public:
	Engine();
	Engine(const string &brand,  float version);
	~Engine();

	string description() const;

private:
	string brand;		//品牌
	float version;		//型号, x.x升
};
