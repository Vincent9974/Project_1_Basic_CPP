#pragma once
#include <string>
#include <iostream>

using namespace std;

#define AGE_KEY			"age"
#define SALARY_KEY		"salary"
#define DARK_HORSE_KEY  "darkHorse"
#define POWER_KEY		"power"

typedef enum {
	AGE,
	SALARY,
	DARK_HORSE,
	POWER
}BOY_KEY_TYPE;


class Boy
{
public:
    //Boy(const char* name=NULL, int age=0, int salary=0, int darkHorse=0);
	Boy(const char* name, int age, int salary, int darkHorse);
    ~Boy();

    Boy(int salary);
    Boy(const char*name);

    // 重载赋值运算符
    Boy& operator=(const Boy& boy);
    bool operator>(const Boy&boy);
    bool operator<(const Boy&boy);
    bool operator==(const Boy&boy);

    int operator[](std::string index);
    int operator[](int index);

    // ostream& operator<<(ostream& os) const;

    friend ostream& operator<<(ostream& os, Boy& boy);
    friend istream& operator>>(istream& is, Boy& boy);

    operator int() const;
    operator char*() const;

    std::string description(void);



private:
    char *name;
    int age;
    int salary;
    int darkHorse;
    unsigned int id;
    static int LAST_ID;
    int power() const;
};