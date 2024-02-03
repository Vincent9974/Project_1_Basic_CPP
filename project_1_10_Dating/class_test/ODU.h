#pragma once
#include <string>

class ODU
{
public:
	ODU();
	~ODU();

	float getTxPower();
	int getTxFreq();
	float getBandWidth();


	bool setTxPower(float power);
	bool setTxFreq(int frequency);
	bool setBandWidth(float bandWidth);

	std::string description();

protected:
	float txPower;		//	发射功率
	int txFreq;				//发射频率
	float bandWidth;		//带宽, 单位:M
};