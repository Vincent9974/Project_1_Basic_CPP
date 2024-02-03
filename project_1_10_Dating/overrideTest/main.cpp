#include <iostream>
#include "Pork.h"
#include "Cow.h"
#include "Goat.h"


class Complex {
private:
    double real;
    double imaginary;

public:
    // 构造函数
    Complex(double r, double i) : real(r), imaginary(i) {}

    // 运算符重载：加法运算符
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // 打印复数
    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

Pork operator+(const Cow &cow1, const Cow &cow2)
{
	int tmp = (cow1.weight + cow2.weight) * 2;
	return Pork(tmp);
}

Pork operator+(const Cow& cow1, const Goat& goat)
{
	int tmp = cow1.weight * 2 + goat.getWeight() * 3;
	return Pork(tmp);
}


void CowTest()
{


	Cow c1(100);
	Cow c2(200);
	Goat g1(100);

	Pork p = c1 + c2;
	std::cout << p.description() << std::endl;

	p = c1 + g1;  // 思考：如何实现：p = g1 + c1;
	std::cout << p.description() << std::endl;


}

void complexTest()
{
    Complex c1(2.0, 3.0);
    Complex c2(1.5, 2.5);

    // 使用重载的加法运算符
    Complex result = c1 + c2;

    // 显示结果
    result.display();
}


int main() {

    complexTest();
    CowTest();

    return 0;
}
