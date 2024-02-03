#pragma once
#include <string>
#include <vector>
#include "Single.h"

using namespace std;
class Boy;

class Girl : public Single
{
public:
    Girl();
    Girl(int age, string name, int FaceValue);
    ~Girl();
    // int getAge() const;
    // string getName() const;
    int getFaceValue() const;
    bool satisfied(const Boy& boy) const;
    string description() const;
    static void inputGirls(vector<Girl> &girls);
    static void inputGirl(Girl& girl);


private:
    // int age;
    // string name;
    int FaceValue;

};