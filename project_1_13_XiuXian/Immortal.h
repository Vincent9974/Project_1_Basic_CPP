#pragma once
#include <string>
#include <vector>


using namespace std;


class SpriteStone;
class Monster;

// 级别
enum class ImmortalLevel
{
    LIAN_QI,
    ZHU_JI,
    JIE_DAN,
    YUAN_YING,
    HUA_SHENG,
    LIAN_XU,
    HE_TI,
    DA_CHENG,
    DU_JIE
};


//修仙者
class Immortal
{
private:
    string name;
    string menpai;
    ImmortalLevel level;
    vector<SpriteStone> stones; //拥有灵石
    vector<Monster> monsters;
    bool alive;

    bool hadMonster(const Monster& monster);
    bool removeMonster(const Monster& monster);


public:
    Immortal(const char* name, const char* menpai, ImmortalLevel level);
    ~Immortal();

    void mining();
    bool trade(); 
    bool trade(const Monster& monster); 
    bool trade(Immortal &other, const Monster& monster); 
    bool trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest); 
    bool trade(const Monster& monster, Immortal& other);

    int getPower() const;
    void fight(const Monster& monster);
    friend std::ostream& operator<<(std::ostream& os, const Immortal& immortal);
    void dead();
};

std::ostream& operator<<(std::ostream& os, const Immortal& immortal);
std::ostream& operator<<(std::ostream& os, const ImmortalLevel level);
