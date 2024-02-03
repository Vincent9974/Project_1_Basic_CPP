#include "HumanTest.h"
#include <sstream>

HumanTest::HumanTest(){}
HumanTest::~HumanTest(){}
HumanTest::HumanTest(const string &name, gender_t gender, int age)
{
    this->name = name;
    this->gender = gender;
    this->age = age;
}

string HumanTest::getName() const
{
    return name;
}

gender HumanTest::getGender() const
{
    return gender;
}

int HumanTest::getAge() const
{
    return age;
}

HumanTest *HumanTest::getLover() const
{
    return lover;
}

vector<HumanTest *> HumanTest::getFriends() const
{
    return friends;
}

string HumanTest::descripction() const
{
    stringstream des;
    des << name << "-age:" << age << "-" << (gender == MAN ? "男" : "女");
    return des.str();
}

void HumanTest::marry(HumanTest &other)
{
    if(gender == other.gender)
    {
        return;
    }
    this->lover = &other;
    other.lover = this;
}

void HumanTest::divorce()
{
    if(this->lover == NULL)
    {
        return;
    }
    lover->lover = NULL;
    lover = NULL;
}

void HumanTest::addFriend(HumanTest &other)
{
    friends.push_back(&other);
}

void HumanTest::delFriend(HumanTest &other)
{
    for (auto it = friends.begin(); it != friends.end();)
    {
        if(*it == &other)
        {
            it = friends.erase(it);
        }
        else
        {
            it ++;
        }
    }
}
