#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Shape
{
public:
    virtual void draw() const
    {
        // 虚函数
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        // 重写基类的虚函数
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape
{
public:
    void draw() const override
    {
        // 重写基类的虚函数
        std::cout << "Drawing a square." << std::endl;
    }
};

// 使用多态
void drawShape(const Shape &shape)
{
    shape.draw(); // 在运行时确定调用哪个版本的 draw 函数
}

class Father
{
public:
    virtual void play()
    {
        cout << " 父类" << endl;
    }
};

class Son : public Father
{
public:
    virtual void play()
    {
        cout << "子类" << endl;
    }
};

void party(Father **men, int n)
{
    for (int i = 0; i < n; i++)
    {
        men[i]->play();
    }
}

class Father1
{
public:
    virtual void func1() { cout << "Father::func1" << endl; }
    virtual void func2() { cout << "Father::func2" << endl; }
    virtual void func3() { cout << "Father::func3" << endl; }
    void func4() { cout << "!void // Father::func4" << endl; }

public:
    int x = 100;
    int y = 200;
    static int z;
};

int Father1::z = 0;
typedef void (*func_t)(void);

class Father2
{
public:
    virtual void func1() { cout << "Father::func1" << endl; }
    virtual void func2() { cout << "Father::func2" << endl; }
    virtual void func3() { cout << "Father::func3" << endl; }
    void func4() { cout << "非虚函数：Father::func4" << endl; }

public: // 为了便于测试，特别该用public
    int x = 100;
    int y = 200;
};

class Son2 : public Father2
{
public:
    void func1() { cout << "Son::func1" << endl; }
    virtual void func5() { cout << "Son::func5" << endl; }
};

typedef void (*func_t)(void);

class XiaoMi
{
public:
    XiaoMi() {}
    virtual void func();
};

class XiaoMi2 final : public XiaoMi
{
public:
    XiaoMi2(){};
    // void func() {}; // 错误！不能重写func函数
    void func() override;
};

// class XiaoMi3 : public XiaoMi2 {  //不能把XiaoMi2作为基类

// };

void XiaoMi::func()
{ // 不需要再写final
    cout << "XiaoMi::func" << endl;
}

class Father3
{
public:
    Father3(const char *addr = "中国")
    {
        cout << "执行了Father的构造函数" << endl;
        int len = strlen(addr) + 1;
        this->addr = new char[len];
        strcpy_s(this->addr, len, addr);
    }

    // 把Father类的析构函数定义为virtual函数时，
    // 如果对 Father类的指针使用delete操作时，
    // 就会对该指针使用“动态析构”：
    // 如果这个指针，指向的是子类对象，
    // 那么会先调用该子类的析构函数，再调用自己类的析构函数
    virtual ~Father3()
    {
        cout << "执行了Father的析构函数" << endl;
        if (addr)
        {
            delete addr;
            addr = NULL;
        }
    }

private:
    char *addr;
};

class Son3 : public Father3
{
public:
    Son3(const char *game = "吃鸡", const char *addr = "中国")
        : Father3(addr)
    {
        cout << "执行了Son的构造函数" << endl;
        int len = strlen(game) + 1;
        this->game = new char[len];
        strcpy_s(this->game, len, game);
    }
    ~Son3()
    {
        cout << "执行了Son的析构函数" << endl;
        if (game)
        {
            delete game;
            game = NULL;
        }
    }

private:
    char *game;
};

void test3()
{
    cout << "----- case 1 -----" << endl;
    Father3 *father = new Father3();
    delete father;

    cout << "----- case 2 -----" << endl;
    Son3 *son = new Son3();
    delete son;

    cout << "----- case 3 -----" << endl;
    father = new Son3();
    delete father;
};

class form
{
public:
    form(const string& color = "white")
    {
        this->color = color;
    }
    virtual float area() = 0;
    string getColor() { return color; }

private:
    string color;
};

class circle1: public form
{
public:
    circle1(float radius =0,const string& color="white"):form(color),r(radius){}
    float area();
private:
    float r;
};

float circle1::area()
{
    return 3.14 * r * r;
}

int main(void)
{
    // Shape s;
    // Circle c;
    // Square square;
    // s.draw();
    // c.draw();
    // square.draw();
    // Father father;
    // Son son1, son2;
    // Father *men[] = {&father, &son1, &son2};
    // party(men, sizeof(men) / sizeof(men[0]));

    // void test3();

	circle1 c1(10);
	cout << c1.area() << endl;

	form* p = &c1;
	cout << p->area() << endl;


    system("pause");
    return 0;
}


