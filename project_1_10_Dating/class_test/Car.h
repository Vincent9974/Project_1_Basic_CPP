#pragma once
#include <string>
#include "Engine.h"
#include "Tire.h"

using namespace std;

class Car
{
public:
	Car();
	Car(const string &carBrand, const string &carVer, int carPrice,
		const string &engineBrand, float engineVer,
		const string &tireBrand = "米其林");
	~Car();

	Engine getEngine();
	Tire* getTire(int i);
	string getBrand();
	string getVersion();
	int getPrice();
	int getMiles();
	string description();

private:
	Engine engine;
	Tire  tires[4];
	string brand;  //品牌
	string version; //型号
	int price;
	int miles;
};
