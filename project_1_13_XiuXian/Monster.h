#pragma once
#include <string>
#include <sstream>


class SpriteStone;

class Monster
{
private:
    std::string catagory;
    int level;

public:
    Monster(int level, const std::string &category);
    SpriteStone getValue() const;
    friend std::ostream& operator<<(std::ostream& os, const Monster& monster);
    ~Monster();
    friend bool operator==(const Monster& one, const Monster& other);
    int getPower() const;
};

std::ostream& operator<<(std::ostream& os, const Monster& monster);
bool operator==(const Monster& one, const Monster& other);
