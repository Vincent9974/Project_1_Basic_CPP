#include <iostream>
#include <string>
#include <array>
#include  <exception>
#include <stdexcept>
#include <memory>
using namespace std;

class student
{
public:
	explicit student(int _age)
	{
		age = _age;
		cout << "age=" << age << endl;
	}

	student(int _age, const string _name)
	{
		age = _age;
		name = _name;
		cout << "age=" << age << "; name=" << name << endl;
	}

	~student()
	{
	}

	int getAge()
	{
		return age;
	}

	string getName()
	{
		return name;
	}

private:
	int age;
	string name;
};

void explicitTest()
{
	student s1(18);		 // 显示构造
	student s2(18, "b"); // 隐式构造
	// student s3 = 18;
	student s4 = {18, "d"};
}

// int& demo()
// {
//     static int i = 0;
// 	cout << "i=" << i << endl;
//     return i;
// }

// void valueTest()
// {
//     demo() = 88;
// 	demo();
//     // int ret = demo();
// 	//int *a = &88;
//     //ret = 99;
// }

int &demo1()
{
	int i = 0;
	// printf("i 的地址: %p, i=%d\n", &i, i);
	i++;
	return i;
}

int &demo(int **addr)
{
	int i = 666;
	*addr = &i;
	printf("i的地址:%p\n", &i);
	printf("i 的地址: %p, i=%d\n", &i, i);

	return i;
}

void quoteTest()
{
	// int& i1 = demo1();
	int *addr = NULL;
	int &i1 = demo(&addr);
	printf("i的地址:%p\n", addr);
}

void arrayTest()
{
	array<int, 5> a1 = {1, 2, 3, 4, 4};
	array<int, 5> a2;

	a1.fill(0);
	a2 = a1;

	for (array<int, 5>::iterator it = a1.begin(); it != a1.end(); ++it)
	{
		int elem = *it;
		cout << elem << endl;
	}

	cout << a1.at(4) << endl;
}

class Animal
{
public:
	virtual void cry() = 0;
};

class Cat : public Animal
{
public:
	void cry()
	{
		cout << "喵喵瞄" << endl;
	}

	void play()
	{
		cout << "爬爬树" << endl;
	}
};

class Dog : public Animal
{
public:
	void cry()
	{
		cout << "汪汪汪" << endl;
	}

	void play()
	{
		cout << "溜达溜达" << endl;
	}
};

void castTest()
{
	double PI = 3.1415927;

	int i1 = PI;
	int i2 = (int)PI;

	cout << i2 << endl;

	int i3 = static_cast<int>(PI);

	cout << i3 << endl;

	Dog *dog1 = new Dog();
	Animal *a1 = static_cast<Animal *>(dog1); // 子类的指针转型到父类指针

	a1->cry();

	Dog *dog1_1 = static_cast<Dog *>(a1); // 父类的指针转型到子类的指针
	Cat *cat1 = static_cast<Cat *>(a1);	  // 父子到子类，有风险

	Dog dog2;
	Animal &a2 = static_cast<Animal &>(dog2);
	Dog &dog2_2 = static_cast<Dog &>(a2);

	// 第二种 基本类型的转换
	int kk = 234;
	char cc = static_cast<char>(kk);

	// 第三种 把空指针转换成目标类型的空指针。
	int *p = static_cast<int *>(NULL);
	Dog *dp = static_cast<Dog *>(NULL);

	// 第四种 把任何类型的表达式转换成void类型
	int *pi = new int[10];
	void *vp = static_cast<void *>(pi);
}

void reintepretTest()
{
	// reinterpreter_cast
	// 用法一   数值与指针之间的转换
	int *p = reinterpret_cast<int *>(0x99999);
	// int val = reinterpret_cast<int>(p);

	// 用法二  不同类型指针和引用之间的转换
	Dog dog1;
	Animal *a1 = &dog1;
	a1->cry();

	Dog *dog1_p = reinterpret_cast<Dog *>(a1);
	Dog *dog2_p = static_cast<Dog *>(a1); // 如果能用static_cast ，static_cast 优先

	dog1_p->cry();
	dog2_p->cry();

	Cat *cat1_p = static_cast<Cat *>(a1);
	// Cat* cat2_p = static_cast<Cat*>(dog1_p);//NO！ 不同类型指针转换不能使用static_cast
	Cat *cat2_p = reinterpret_cast<Cat *>(dog1_p);

	cat1_p->cry();
	cat2_p->cry();
}

void animalPlay(Animal &animal)
{
	animal.cry();

	try
	{
		Dog &pDog = dynamic_cast<Dog &>(animal);
		pDog.play();
	}
	catch (std::bad_cast bc)
	{
		cout << "不是狗，那应该是猫" << endl;
	}

	try
	{
		Cat &pCat = dynamic_cast<Cat &>(animal);
		pCat.play();
	}
	catch (std::bad_cast bc)
	{
		cout << "不是猫，那应该是上面的狗" << endl;
	}
}

void dynamicTest()
{
	Dog *dog1 = new Dog();
	Animal *a1 = dog1;
}


void demo(const char* p)
{
	//对指针去掉cost 重新赋值
	// char* p1 = const_cast<char *>(p);
	// p1[0] = 'A';

	//直接去掉const修改
	//常量字符串不能去掉const 修改
	//警告： 在去掉常量限定符之前，保证指针所指向的内存能够修改，
	//不能修改则会引起异常。

	const_cast<char*>(p)[0] = 'A';

	cout << p << endl;
}


void demo(const int p)
{
	int q = p;
	//const_cast<int>(p) = 888;// NO ! 不能对非指针和引用进行const 转换
	cout << p << endl;
}



void constTest()
{
	//字符串数组
	char p[] = "12345678";
	demo(p);  //合情合理

	const char* cp = "987654321";
	demo(cp);
}

void memory_leak_demo1() {
    //string* str = new string("今天又敲了一天代码，太累了，回家休息了!!!");
	string str("今天又敲了一天代码，太累了，回家休息了!!!"); //string 对象会执行析构函数
    cout << str << endl;
    return;
}

int memory_leak_demo2() {
    string* str = new string("这个世界到处是坑，所以异常处理要谨记在心!!!");
    /***********************************************
     * 程序执行一段复杂的逻辑，假设尝试从一个必须存在
     * 的文件中读取某些数据，而文件此时不存在
     ************************************************/
    cout << *str << endl;
    delete str;
    return 0;
}

class Test
{
public:
    Test() {
        cout << "Test is construct" << endl;
        debug = 1; 
    }

    ~Test() { cout << "Test is destruct" << endl; }

    int getDebug() {
        return debug;
    }

private:
    int debug;
};

void memory_leak_demo1() {
    auto_ptr< Test> t(new Test());

    //auto_ptr< Test> t1;
    //t1 = t;

    //auto_ptr<Test>* tp = new auto_ptr<Test>(new Test()); 


    //在使用智能指针访问对象时，使用方式和普通指针一样
    cout<< "-> debug: "<<t->getDebug()<< endl;
    cout << "* debug: " << (*t).getDebug() << endl;

    //Test* tmp = t.get();
    //cout << "get debug: " << tmp->getDebug() << endl;

    //release 取消指针指针对动态内存的托管，之前分配的内存必须手动释放
    //Test*  tmp = t.release();  
    //delete tmp; 

    //reset 重置智能指针托管的内存地址，如果地址不一致，原来的会被析构掉
    //t.reset();
    t.reset(new Test());
    
    if(0){
        Test* t1 = new Test();
        t1->getDebug();
    }

    return;

}


int memory_leak_demo2() {
    //Test* t = new Test();
    auto_ptr< Test> t(new Test());

    /***********************************************
     * 程序执行一段复杂的逻辑，假设尝试从一个必须存在
     * 的文件中读取某些数据，而文件此时不存在
     ************************************************/
    {
        //throw exception("文件不存在");
    }
    
    //delete t;
    return 0;
}


void pointerTest()
{
	//如果我们分配的动态内存都交由有生命周期的对象来处理，那么在对象过期时，
	//让它的析构函数删除指向的内存
	//智能指针解决自动释放的问题;

	auto_ptr<Test> t(new Test());
	return;

}

int main(void)
{

	// explicitTest();

	// valueTest();

	// quoteTest();

	// arrayTest();

	// castTest();

	// reintepretTest();

	// dynamicTest();
	
	// constTest();

	pointerTest();

	system("pause");
	return 0;
}
