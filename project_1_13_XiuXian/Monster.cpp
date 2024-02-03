#include "Monster.h"
#include "SpriteStone.h"

#define MONSTER_LEVEL_FACTOR 1000

Monster::Monster(int level, const std::string &category)
{
    this->level = level;
    this->catagory = category;
}

SpriteStone Monster::getValue() const
{
    int stoneCount[] = {100, 200, 500, 1000,2000,5000,10000,20000,100000};
    int count = stoneCount[level - 1];
    return SpriteStone(count, SpriteStoneLevel::PRIMARY_LEVEL);
}

Monster::~Monster()
{
}

int Monster::getPower() const
{
    int ret = level * MONSTER_LEVEL_FACTOR;
	return ret;
}

std::ostream &operator<<(std::ostream &os, const Monster &monster)
{
    os << monster.level << "级" << monster.catagory << "妖兽";
    return os;
}

bool operator==(const Monster &one, const Monster &other)
{
    if(one.catagory == other.catagory && other.level == one.level)
    {
        return true;
    }
    else
    {
        return false;
    }
}
