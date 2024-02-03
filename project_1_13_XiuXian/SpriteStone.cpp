#include "SpriteStone.h"
#include <sstream>

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
    this->count = count;
    this->level = level;
}

std::string SpriteStone::str() const
{
    std::stringstream ret;
    ret << count << "块";
    switch (level)
    {
    case SpriteStoneLevel::PRIMARY_LEVEL:
        ret << "初阶灵石";
        break;
    case SpriteStoneLevel::MIDDLE_LEVEL:
        ret << "中阶灵石";
        break;
    case SpriteStoneLevel::ADVANCE_LEVEL:
        ret << "高阶灵石";
        break;
    default:
        ret << "未知灵石";
        break;
    }
    return ret.str();
}

SpriteStone SpriteStone::operator+(const SpriteStone &stone)
{
    int sum = 0;
    if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL)
    {
        sum += stone.count;
    }
    else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL)
    {
        sum += stone.count * 10;
    }
    else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL)
    {
        sum += stone.count * 100;
    }

    if (this->level == SpriteStoneLevel::PRIMARY_LEVEL)
    {
        sum += this->count;
    }
    else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL)
    {
        sum += this->count * 10;
    }
    else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL)
    {
        sum += this->count * 100;
    }

    return SpriteStone(sum, SpriteStoneLevel::PRIMARY_LEVEL);
}

SpriteStone SpriteStone::operator-(const SpriteStone& stone)
{
	int sum1 = 0;
	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum1 = this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum1 = this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum1 = count * 100;
	}

	int sum2 = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum2 = stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum2 = stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum2 = stone.count * 100;
	}

	return SpriteStone(sum1 - sum2, SpriteStoneLevel::PRIMARY_LEVEL);
}

std::ostream &operator<<(std::ostream &os, const SpriteStone &stone)
{
    os << stone.str();
    return os;
}

int SpriteStone::getCount()
{
    return count;
}

bool SpriteStone::operator>=(const SpriteStone &stone)
{
    int sum1 = 0;
    if (this->level == SpriteStoneLevel::PRIMARY_LEVEL)
    {
        sum1 = this->count;
    }
    else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL)
    {
        sum1 = this->count * 10;
    }
    else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL)
    {
        sum1 = count * 100;
    }

    int sum2 = 0;
    if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL)
    {
        sum2 = stone.count;
    }
    else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL)
    {
        sum2 = stone.count * 10;
    }
    else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL)
    {
        sum2 = stone.count * 100;
    }

    return sum1 >= sum2;
}
