#include "Immortal.h"
#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"
#include <ostream>

#define IMMORTAL_LEVEL_FACTOR 1000
#define SPRITE_FACTOR 0.1
#define MONSTER_FACTOR 0.1

bool Immortal::hadMonster(const Monster &monster)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monster == monsters[i])
        {
            return true;
        }
    }

    return false;
}

bool Immortal::removeMonster(const Monster &monster)
{
    vector<Monster>::iterator it = monsters.begin();
    while (it != monsters.end())
    {
        if (*it == monster)
        {
            it = monsters.erase(it);
            return true;
        }
        else
        {
            it++;
        }
    }
    return false;
}

Immortal::Immortal(const char *name, const char *menpai, ImmortalLevel level)
{
    this->name = name;
    this->menpai = menpai;
    this->level = level;
    this->alive = true;
}

Immortal::~Immortal()
{
}

void Immortal::mining()
{
    stones.push_back(SpriteStone(100, SpriteStoneLevel::PRIMARY_LEVEL));
}

bool Immortal::trade()
{
    if (!alive)
    {
        return false;
    }

    SpriteStone stone;
    for (int i = 0; i < monsters.size(); i++)
    {
        stone = stone + monsters[i].getValue();
    }

    stones.push_back(stone);
    monsters.erase(monsters.begin(), monsters.end());

    return false;
}

bool Immortal::trade(const Monster &monster)
{
    if (!alive)
    {
        return false;
    }

    if (!hadMonster(monster))
    {
        cout << name << "没有" << monster << endl;
        return false;
    }

    SpriteStone stone = monster.getValue();
    stones.push_back(stone);
    removeMonster(monster);
    return false;
}

bool Immortal::trade(Immortal &other, const Monster &monster)
{
    if (alive == false || other.alive == false)
    {
        return false;
    }

    if (!other.hadMonster(monster))
    {
        cout << other.name << "没有" << monster << endl;
        return false;
    }

    return false;
}

bool Immortal::trade(const Monster &monsterSource, Immortal &other, const Monster &monsterDest)
{
	if (alive == false || other.alive == false) {
		return false;
	}

	if (monsterSource == monsterDest ||
		!hadMonster(monsterSource) ||
		!other.hadMonster(monsterDest) ||
		!(monsterSource.getValue() >= monsterDest.getValue())) {
		return false;
	}

	removeMonster(monsterSource);
	other.removeMonster(monsterDest);
	monsters.push_back(monsterDest);
	other.monsters.push_back(monsterSource);

	return false;
}

bool Immortal::trade(const Monster &monster, Immortal &other)
{
    if (alive == false || other.alive == false)
    {
        return false;
    }

    if (!hadMonster(monster))
    {
        std::cout << name << "没有" << monster << std::endl;
    }

    SpriteStone otherStone;
    for (int i = 0; i < other.stones.size(); i++)
    {
        otherStone = otherStone + other.stones[i];
    }

    if (!(otherStone >= monster.getValue()))
    {
        return false;
    }

    	// 对方修仙者付钱
    otherStone = otherStone-monster.getValue();
	other.stones.clear();
	other.stones.push_back(otherStone);
	// 对方修仙者收妖兽
	other.monsters.push_back(monster);

	// 己方移除妖兽
	this->removeMonster(monster);
	// 己方收取灵石
	this->stones.push_back(monster.getValue());

	return false;

}

int Immortal::getPower() const
{
    int ret = ((int)level + 1) * IMMORTAL_LEVEL_FACTOR;

    SpriteStone stone;
    for (int i = 0; i < stones.size(); i++)
    {
        stone = stone + stones[i];
    }
    ret += stone.getCount() * SPRITE_FACTOR;

    for (int i = 0; i < monsters.size(); i++)
    {
        ret += monsters[i].getPower() * MONSTER_FACTOR;
    }

    return ret;
}

void Immortal::fight(const Monster &monster)
{
    int selfPower = getPower();
    int monsterPower = monster.getPower();

    if (selfPower > monsterPower)
    {
        monsters.push_back(monster);
    }
    else if (selfPower < monsterPower)
    {
        dead();
    }
}

void Immortal::dead()
{
    alive = false;
    stones.erase(stones.begin(), stones.end());
    monsters.erase(monsters.begin(), monsters.end());
}

std::ostream &operator<<(std::ostream &os, const Immortal &immortal)
{
    // TODO: 在此处插入 return 语句
    os << "[修仙者]" << immortal.name
       << (immortal.alive ? "[在修]" : "[以亡]")
       << "\t门派:" << immortal.menpai
       << "\t级别:" << immortal.level;

    SpriteStone stone;
    for (int i = 0; i < immortal.stones.size(); i++)
    {
        stone = stone + immortal.stones[i];
    }
    os << "\t灵石:折合" << stone;

    os << "\t妖兽:";
    if (immortal.monsters.size() == 0)
    {
        os << "无";
    }
    else
    {
        for (int i = 0; i < immortal.monsters.size(); i++)
        {
            os << immortal.monsters[i] << " ";
        }
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const ImmortalLevel level)
{
    switch (level)
    {
    case ImmortalLevel::LIAN_QI:
        os << "练气期";
        break;
    case ImmortalLevel::ZHU_JI:
        os << "筑基期";
        break;
    case ImmortalLevel::JIE_DAN:
        os << "结丹期";
        break;
    case ImmortalLevel::YUAN_YING:
        os << "元婴期";
        break;
    case ImmortalLevel::HUA_SHENG:
        os << "化神期";
        break;
    case ImmortalLevel::LIAN_XU:
        os << "炼虚期";
        break;
    case ImmortalLevel::HE_TI:
        os << "合体期";
        break;
    case ImmortalLevel::DA_CHENG:
        os << "大成期";
        break;
    case ImmortalLevel::DU_JIE:
        os << "渡劫期";
        break;
    }

    return os;
}
