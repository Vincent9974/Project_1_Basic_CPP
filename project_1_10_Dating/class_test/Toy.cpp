#include "Toy.h"
#include <iostream>
using namespace std;

Toy::Toy(){}

Toy::~Toy(){}

Toy::Toy(string name, float price, string origin)
{
    this->name = name;
    this->price = price;
    this->origin = origin;
}


string Toy::getName() const
{
    return name;
}

string Toy::getOrign() const
{
    return origin;
}



float Toy::getPrice() const
{
    return price;
}

float Toy::getDiscount() const
{
    return this->discount;
}

