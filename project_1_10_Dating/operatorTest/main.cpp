#include <iostream>
#include "boy.h"
#include "Man.h"

// void boyTest()
// {
// 	Boy boy1("vincent", 25, 25000, 10);
// 	Boy boy2, boy3;

// 	std::cout << boy1.description() << std::endl;
// 	std::cout << boy2.description() << std::endl;
// 	std::cout << boy3.description() << std::endl;

// 	boy3 = boy2 = boy1;
// 	std::cout << boy2.description() << std::endl;
// 	std::cout << boy3.description() << std::endl;
// }

void boyCompare()
{
	Boy boy1("Rock", 38, 58000, 5);
	Boy boy2("Jack", 25, 50000, 10);

	if (boy1 > boy2)
	{
		std::cout << "选择boy1" << std::endl;
	}
	else if (boy1 == boy2)
	{
		std::cout << "难以选择" << std::endl;
	}
	else
	{
		std::cout << "选择boy2" << std::endl;
	}
}

// void boyIndex()
// {
// 	Boy boy1("Rock", 38, 58000, 5);
// 	Boy boy2("Jack", 25, 50000, 10);

// 	std::cout << "age:" << boy1["age"] << std::endl;
// 	std::cout << "salary:" << boy1["salary"] << std::endl;
// 	std::cout << "darkHorse:" << boy1["darkHorse"] << std::endl;
// 	std::cout << "power:" << boy1["power"] << std::endl;

// 	std::cout << "[0]:" << boy1[0] << std::endl;
// 	std::cout << "[1]:" << boy1[1] << std::endl;
// 	std::cout << "[2]:" << boy1[2] << std::endl;
// 	std::cout << "[3]:" << boy1[3] << std::endl;
// }

ostream& operator<<(ostream& os, Boy& boy)
{
	os << "ID:" << boy.id << "\t姓名:" << boy.name << "\t年龄:" << boy.age << "\t薪资:"
	<< boy.salary << "\t黑马系数:" << boy.darkHorse;
	return os;
}



void boyOut()
{
	Boy boy1("Rock", 38, 58000, 5);
	Boy boy2("Jack", 25, 50000, 10);
}

void boyInOutFile()
{
	Boy boy1("Rock", 38, 58000, 5);
	Boy boy2("Jack", 25, 50000, 10);

	cout << boy1 << endl;
	cin >> boy1;
	cout << boy1;

}

void boyReInit()
{
	Boy boy1 = 10000;
	Boy boy2 = "aa";

	cout << boy1 << endl;
	cout << boy2 << endl;

	boy1 = 20000; //boy1 = Boy(20000);
	cout << boy1 << endl;

}


void boyTransfer()
{
	Boy boy1("vincent", 25, 15000, 5);
	Boy boy2("vincent");

	int power = boy1;
	char* name = boy2;

	cout << power << endl;
	cout << name << endl;

}

void boy2Man()
{
	Boy boy("Vincnt", 25, 10000, 5);
	Man man = boy;
	

	cout << boy << endl;
	cout << man << endl;

}

int main(void)
{
	// boyTest();
	// boyCompare();
	// boyIndex();
	// boyOut();
	// boyInOutFile();
	//boyReInit();
	// boyTransfer();
	// boy2Man();

	system("pause");
	return 0;
}