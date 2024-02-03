#pragma once 
#include <string>
#include <vector>
using namespace std;

typedef enum gender
{
    MAN,
    WOMAN
}gender_t;



class HumanTest
{
public:
    HumanTest();
    ~HumanTest();
    HumanTest(const string &name, gender_t gender, int age);

    string getName() const;
    gender getGender() const;
    int getAge() const;
    HumanTest* getLover() const;
    vector<HumanTest*> getFriends() const;
    string descripction() const;

    void marry(HumanTest& other);
    void divorce();
    void addFriend(HumanTest &other);
    void delFriend(HumanTest &other);

private:
    string name;
    int age ;
    HumanTest* lover;
    vector<HumanTest*> friends;
    gender_t gender;
    
};

