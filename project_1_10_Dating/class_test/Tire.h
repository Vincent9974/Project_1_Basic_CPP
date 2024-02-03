#pragma once
#include <string>

using namespace std;

class Tire
{
public:
	Tire(const string &brand="米其林");
	~Tire();
	string descripton() const;
	string getBrand() const;
	float getPressure() const;

private:
	string brand;		//品牌
	float pressure;   //胎压
};
