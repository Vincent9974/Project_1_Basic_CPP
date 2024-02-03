#include "Cow.h"
#include "Pork.h"
#include "Goat.h"

Cow::Cow(int weight)
{
	this->weight = weight;
}


// 规则：
// 一斤牛肉：2斤猪肉
// 一斤羊肉：3斤猪肉
// Pork Cow::operator+(const Cow &cow)
// {
// 	int tmp = (this->weight + cow.weight) * 2;
// 	return Pork(tmp);
// }

// Pork Cow::operator+(const Goat& goat)
// {
// 	// 不能直接访问goat.weight
// 	//int tmp = this->weight * 2 + goat.weight * 3;
// 	int tmp = this->weight * 2 + goat.getWeight() * 3;
// 	return Pork(tmp);
// }
