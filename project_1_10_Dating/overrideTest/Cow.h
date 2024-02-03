#pragma once


class Pork;
class Goat;

class Cow
{
public:
	Cow(int weight);

	// 参数此时定义为引用类型，更合适，避免拷贝
	// Pork operator+(const Cow& cow);  //同类型进行运算，很频繁
	// Pork operator+(const Goat& goat); //不同类型进行运算，比较少见

	friend Pork operator+(const Cow& cow1, const Cow& cow2);
	friend Pork operator+(const Cow& cow1, const Goat& goat);


private:
	int weight = 0;
};
