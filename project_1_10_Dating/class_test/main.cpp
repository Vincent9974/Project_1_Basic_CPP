#include <iostream>
#include <windows.h>
#include <string>
#include "Human.h"
#include "CPU.h"
#include "Computer.h"
#include "VoiceBox.h"
#include "Toy.h"
#include "HumanTest.h"
#include "Father.h"
#include "Son.h"
#include "Book.h"
#include "SellBook.h"



using namespace std;

void showHumanCount(){
    cout << Human::getHumanCount() << endl;
}

void myFunction() {
    std::cout << "Current function: " << __FUNCTION__ << std::endl;
}

void Computer_test(VoiceBox* vb){
    Computer desktop("intel","i5-12490F", 8000, 16);
    desktop.addVoiceBox(vb);
}

void printPrice(Toy &toy)
{
    cout << toy.getName() << ": " << toy.getPrice() << " [made in " << toy.getOrign() << "]" << endl;

    cout << "限时打5折" << endl;

    cout << toy.getName() << ": " << toy.getPrice()*toy.getDiscount() << " [made in " << toy.getOrign() << "]" << endl;
}

void showFatherSon()
{
    Father father("A", 60);
	Son son("B", 30, "LOL");


	cout << father.description() << endl;
    cout << son.description() << endl;


}

void Human_test()
{
    HumanTest lhc("令狐冲", MAN, 25);
	HumanTest ryy("任盈盈", WOMAN, 26);
	HumanTest tbg("田伯光", MAN, 30);
	HumanTest yls("岳灵珊", WOMAN, 20);
	HumanTest cx("冲虚道长", MAN, 55);

    lhc.marry(yls);
    HumanTest *who = lhc.getLover();

    cout << lhc.getName() << "的配偶是: " << who->descripction() << endl;
	cout << who->getName() << "的配偶是: " << who->getLover()->descripction() << endl;

	cout << lhc.getName() << "离婚." << endl;
	lhc.divorce();



	if (lhc.getLover() == NULL) {
		cout << lhc.getName() << "单身" << endl;
	}

	lhc.addFriend(cx);
	lhc.addFriend(tbg);
	vector<HumanTest*> friends = lhc.getFriends();
	cout << lhc.getName() << "的朋友:" << endl;
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->descripction() << endl;
	}

	cout << lhc.getName() << "删除好友:" << tbg.getName() << endl;
	lhc.delFriend(tbg);

	friends = lhc.getFriends();
	cout << lhc.getName() << "的朋友:" << endl;
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->descripction() << endl;
	}
}

class A {
public:
	A() {}
	~A() {}
	void kill() { cout << "A kill." << endl; }
};

class B : public A {
public:
	B(){}
	~B(){}
	void kill() { cout << "B kill." << endl; }
};

void test(A a) {
	a.kill();  //调用的是A类对象的kill方法
}


class Tel {
public:
	Tel() {
		this->number = "未知";
	}
protected:
	string number; //电话号码;
};

// 座机类
class FixedLine : virtual public Tel{};

// 手机类
class MobilePhone : virtual public Tel{};

//无线座机

class WirelessTel : public FixedLine, public MobilePhone
{
public:
    void setNumber(const char* number)
    {
        this->number = number;
    }

    string getNumber()
    {
        return MobilePhone::number;
    }

};

void sellBook()
{
    Book book1(98, "3240000-12");
	cout << "Price:" << book1.getPrice() << " ISBN:" << book1.getISBN() << endl;

	SellBook book2(98, "3240000-12");
	cout << "Price:" << book2.getPrice() << " ISBN:" << book2.getISBN() << endl;

	book2.setDiscount(5);
	cout << "Price:" << book2.getPrice() << " ISBN:" << book2.getISBN() << endl;

	cout << "Discount:" << book2.getDiscount() << endl;

}

int main(void)
{
    // Human h1(25, 35000);

    // Human* p;
    // p = &h1;

    // MyClass class1(6);
    // class1.display();

    // h1.eat();
    // p->eat();

    // cout << h1.getAge() << endl;

    // Human h1(25, 35000, "B");
    // Human h2(h1); // 拷贝构造函数
    // const Human h3(h2);

    // cout << h2.getAge() << endl;
    

    // MyClass* mr = new MyClass;
    // delete mr;

    // // cout << h2.getHumanCount() << endl;
    // showHumanCount();

    // h1.description();
    // h3.description();

    // myFunction();
    // VoiceBox vb;
    // Computer_test(&vb);

    // Toy toy("玩具", 1000.0, "china");
    // printPrice(toy);

    // Human_test();

    // showFatherSon();

    // A a;
    // B b;
    // test(a);
    // test(b);

	// WirelessTel phone;
	// phone.setNumber("17321106748");
	// cout << phone.getNumber() << endl;  

    // sellBook();

    

    system("pause");
    return 0;
}