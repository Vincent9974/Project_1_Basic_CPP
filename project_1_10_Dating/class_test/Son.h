#pragma once
#include "Father.h"

class Son : public Father
{
public:
    Son(const char *name, int age, const char *game);
    ~Son();
    string getGame();
    string description();

private:
    string game;
};
