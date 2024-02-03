#include "ODU.h"
#include <sstream>

using namespace std;

ODU::ODU()
{
}


ODU::~ODU()
{
}

float ODU::getTxPower() {
	return txPower;
}

bool ODU::setTxPower(float power) {
	// 实际产品项目中, 是通过串口发送控制包实现的.
	txPower = power;
	return true;
}

int ODU::getTxFreq() {
	return txFreq;
}

bool ODU::setTxFreq(int frequency) {
	txFreq = frequency;
	return true;
}

float ODU::getBandWidth() {
	return bandWidth;
}

bool ODU::setBandWidth(float bandWidth) {
	this->bandWidth = bandWidth;
	return true;
}

string ODU::description() {
	stringstream ret;
	ret << "发射功率: " << txPower << "\t发射频率: " << txFreq
		<< "\t带宽: " << bandWidth;
	return ret.str();
}
