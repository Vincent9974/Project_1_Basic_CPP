#pragma once
#include <string>
#include <iostream>

enum class SpriteStoneLevel
{
    PRIMARY_LEVEL,
    MIDDLE_LEVEL,
    ADVANCE_LEVEL,
    SPRITE_STONE_LEVEL_COUNT
};

class SpriteStone
{
public:
    SpriteStone(int count = 0,
                SpriteStoneLevel level = SpriteStoneLevel::PRIMARY_LEVEL);
    std::string str() const;
    friend std::ostream &operator<<(std::ostream &os, const SpriteStone &stone);
    SpriteStone operator+(const SpriteStone& stone);
    SpriteStone operator-(const SpriteStone& stone);
    int getCount();
    bool operator>=(const SpriteStone& stone);

private:
    int count;
    SpriteStoneLevel level;
};

std::ostream &operator<<(std::ostream &os, const SpriteStone &stone);