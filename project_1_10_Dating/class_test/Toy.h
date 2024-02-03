#pragma once
#include<string>
using namespace std;


class Toy
{
public:
    Toy();
    ~Toy();
    Toy(string name, float price, string origin);
    string getName() const;
    string getOrign() const;
    float getPrice() const;
    float getDiscount() const;

private:
    string name;
    int price;
    string origin;
    float discount = 0.5;
};