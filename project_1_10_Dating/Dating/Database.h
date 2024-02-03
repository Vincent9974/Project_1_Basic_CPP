#pragma once
#include "Boy.h"
#include "Girl.h"
#include <vector>

using namespace std;

// 设计一个新的类来保存用户信息 Database, 

class Database
{
public:
    Database();

    void init();
    void autoPair();
    void print();

    void addOne(Boy& boy);
    void addOne(Girl& girl);
    void autoPairBest();


private:
    vector<Boy> boys;
    vector<Girl> girls;
    void initBoysFromFile();
    void initGirlsFromFile();
    void saveBoys();
    void saveGirls();
};