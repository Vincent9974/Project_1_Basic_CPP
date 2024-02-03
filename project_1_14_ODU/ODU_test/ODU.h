#pragma once
#include <string>

#define ODU_TYPE_331_FLAG	"331"
#define	ODU_TYPE_335_FLAG	"335"


enum class ODU_TYPE
{
    ODU_TYPE_331,
	ODU_TYPE_335,
	ODU_TYPE_UNKNOWN

};

class ODU
{
public:
    ODU();
    virtual int getTxFre(); // 获取发射频率
    virtual bool setTxFre(int);

    virtual int getRxFre(); //获取接收频率
    virtual bool setRxFre(int);

	virtual float getTxPower(); //获取发射功率
	virtual bool setTxPower(float);  //设置发射功率

    virtual float getRxL(); //获取接收电平

    virtual bool heartBeat(); //心跳包
    virtual std::string name(); //获取该设备的名称
    
    ODU_TYPE getODUType();

protected:
    int txFre;
    int rxFre;
    float txPower;
    float rxL;
    
    ODU_TYPE type;
};