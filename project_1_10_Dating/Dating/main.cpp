#include "Girl.h"
#include "Boy.h"
#include "Single.h"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cstring>
#include <cstdio>
#include "Database.h"

using namespace std;



class Bitmap
{
private:
    std::vector<uint32_t> bitmap;

public:
    Bitmap(uint32_t size)
    {
        // 初始化位图，将所有位设置为0
        bitmap.resize((size + 31) / 32, 0);
    }

    void setBit(uint32_t index)
    {
        // 设置与指定元素相关联的位
        bitmap[index / 32] |= (1u << (index % 32));
    }

    bool testBit(uint32_t index)
    {
        // 测试与指定元素相关联的位的值
        return (bitmap[index / 32] & (1u << (index % 32))) != 0;
    }
};

void bitMap_test()
{
    // 要处理的数字集合
    std::vector<uint32_t> numbers = {1, 5, 10, 15, 20, 5, 30, 10};

    // 最大的数字，用于确定位图的大小
    uint32_t maxNumber = 30;

    // 初始化位图
    Bitmap bitmap(maxNumber + 1);

    // 检查重复元素
    for (uint32_t num : numbers)
    {
        if (bitmap.testBit(num))
        {
            // 数字重复
            std::cout << "Duplicate element: " << num << std::endl;
        }
        else
        {
            // 第一次出现，将位图对应位置设为1
            bitmap.setBit(num);
        }
    }
}

void hashMapTest()
{
    std::unordered_set<int> integerSet;

    // 添加一些不重复的整数到哈希表中
    integerSet.insert(123);
    integerSet.insert(456);
    integerSet.insert(789);
    // 添加更多整数...

    // 要判断的整数
    int targetNumber = 456;

    // 在哈希表中查找整数
    if (integerSet.find(targetNumber) != integerSet.end())
    {
        std::cout << targetNumber << " 在集合中。" << std::endl;
    }
    else
    {
        std::cout << targetNumber << " 不在集合中。" << std::endl;
    }
};

void init(char *data, int len)
{
    unsigned int n = len * 8;
    for (unsigned int i = 0; i < n; i++)
    {
        // 假设: 能够被3整数的数, 都在这个集合中.[假设的需求]
        if (i % 3 == 0)
        {
            // 计算这个位对应哪个字节
            char *p = data + i / 8;
            *p = *p | (1 << (i % 8));
        }
    }
}

// 位图算法
bool check(char *data, int len, int value)
{
    // 定位到指定的字节
    char *p = data + value / 8;

    // 判断这个字节中指定的位是否为1
    bool ret = *p & (1 << (value % 8));

    return ret;
}

void initBitMap()
{
    unsigned int n = 4000000000;
    int len = n / 8 + 1;
    char *data = (char *)malloc(len);
    memset(data, 0, len); // 清零

    init(data, len);
    while (1) {
		printf("请输入要检测的数: [输入-1退出] ");
		int value;
		scanf("%d", &value);
		if (value == -1) {
			break;
		}

		if (check(data, len, value)) {
			printf("%d在数据集合中\n", value);
		}
		else {
			printf("%d不在数据集合中\n", value);
		}
	}

}





int main(void)
{

    Database data;

    data.init();

    // Boy boy;
    // Boy::inputBoy(boy);
    // data.addOne(boy);

    // bitMap_test();
    // hashMapTest();



    system("pause");
    return 0;
}