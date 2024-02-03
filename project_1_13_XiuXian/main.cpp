#include <iostream>
#include <stdlib.h> 
#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"


void testSpriteStone()
{
    SpriteStone stone(100, SpriteStoneLevel::MIDDLE_LEVEL);
    std::cout << stone << std::endl;
}

void testMonster() {
	Monster monster(5, "蛟龙");
	std::cout << monster << std::endl;
}

void testImmortal() {
	Immortal vc("vincent", "CPP", ImmortalLevel::LIAN_QI);
	std::cout << vc << std::endl;

	for (int i = 0; i < 50; i++) {
		vc.mining();
	}
	std::cout << vc << std::endl;

    Monster monster(1, "水箭龟");
	vc.fight(monster);
	std::cout << "捕获" << monster << "之后：" << endl;
	std::cout << vc << endl;

    Monster monster2(1, "喷火龙");
	vc.fight(monster2);
	Monster monster3(1, "妙蛙种子");
	vc.fight(monster3);
	std::cout << "捕获" << monster2 <<"和" << monster3 <<"之后" << endl;
	std::cout << vc << endl;

    vc.trade(monster2);
	std::cout << "售卖" << monster2 << "之后" << endl;
	std::cout << vc << endl;

	vc.trade();
	std::cout << "售卖所有妖兽之后" << endl;
	std::cout << vc << endl;

    Immortal xz("小智", "Java", ImmortalLevel::JIE_DAN);
	std::cout << xz << std::endl;
	Monster monster4(2, "乘龙");
	xz.fight(monster4);
	std::cout << xz << std::endl;

    vc.trade(xz, monster4);
	std::cout << "贸易之后" << std::endl;
	std::cout << vc << std::endl;
	std::cout << xz << std::endl;

    Monster monster5(1, "喵喵");
	xz.fight(monster5);
	cout << "小智" << "捕获" << monster5 << endl;
	cout << xz << endl;

	cout << "vc使用" << monster4 << "和小智交换" << monster5 << endl;
	vc.trade(monster4, xz, monster5);
	cout << vc << endl;
	cout << xz << endl;

	xz.trade(monster4, vc);
	cout << "小智卖" << monster4 << "给vc" << endl;
	cout << vc << endl;
	cout << xz << endl;


}

int main(void)
{
    // testSpriteStone();
    // testMonster();
    testImmortal();
    return 0;
}