#include <sstream>
#include "Car.h"


Car::Car()
{
}

Car::Car(const string & carBrand, const string & carVer, int carPrice, 
	const string & engineBrand, float engineVer, 
	const string & tireBrand):
	engine(engineBrand, engineVer), tires{ tireBrand, tireBrand, tireBrand, tireBrand }
{
	this->brand = carBrand;
	this->price = carPrice;
	this->version = carVer;
	this->miles = 0;
}


Car::~Car()
{
}

Engine Car::getEngine()
{
	return engine;
}

Tire* Car::getTire(int i)
{
	if (i>=1 && i<=4) {
		return &tires[i];
	}

	return NULL;
}

string Car::getBrand()
{

	return brand;
}

string Car::getVersion()
{
	return version;
}

int Car::getPrice()
{
	return price;
}

int Car::getMiles()
{
	return miles;
}

string Car::description()
{
	stringstream ret;
	ret << "汽车品牌:" << brand << "-" << version << "-$" << price
		<< "\t\t引擎:" << engine.description()
		<< "\t\t轮胎:" << tires[0].descripton();

	return ret.str();
}
