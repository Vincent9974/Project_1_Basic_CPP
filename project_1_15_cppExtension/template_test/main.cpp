#include <vector>
#include <iostream>

using namespace std;

class demo
{
public:
    demo(int _k = 0) { k = _k; }
    ~demo() {}
    bool operator>(demo &dest) const
    {
        if (this->k > dest.k)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    int value() { return k; }

private:
    int k;
};

void demoTest()
{
    vector<int> v1;
    int i1 = 1;
    int i2 = 2;

    v1.push_back(i1);
    v1.push_back(i2);

    for (unsigned int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }

    demo d1(10);
    demo d2(100);
    vector<demo> v2;
    v2.push_back(d1);
    v2.push_back(d2);

    for (unsigned int i = 0; i < v2.size(); i++)
    {
        cout << v2[i].value() << endl;
    }
}

// 函数模板
template <typename T, typename T2>
T Max(T a, T2 b)
{
    return a > b ? a : b;
}

void compareTest()
{
    int a = 0;
    int b = 1;
    char x = 'x';
    char y = 'y';
    cout << Max(a, b) << endl;
    cout << Max(x, y) << endl;
}

demo Max(demo a, demo b)
{
    return a > b ? a : b;
}

void templateClassTest()
{
    demo d1 = demo(10);
    demo d2 = demo(20);
    cout << "demoClassTest:" << Max(d1, d2).value() << endl;
}

template <typename T>
void Swap(T &a, T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
    cout << "Swap 模板函数被调用了" << endl;
}

void Swap(char &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
    cout << "Swap 普通函数被调用了" << endl;
}

void swapTest()
{
    char cNum = 'c';
    int iNum = 65;
    Swap(cNum, iNum);
}

int Max(int a, int b)
{
    cout << "调用 int Max(int a, int b)" << endl;
    return a > b ? a : b;
}

template <typename T>
T Max(T a, T b)
{
    cout << "调用 T Max(T a, T b)" << endl;
    return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c)
{
    cout << "调用 T Max(T a, T b, T c)" << endl;
    return Max(Max(a, b), c);
}

void maxTest()
{
    int a = 1;
    int b = 2;
    char c = 'a';

    // 当函数模板和普通函数都符合调用时,优先选择普通函数
    // cout<<"Max(a, b)"<<Max(a, b)<<endl;

    // 如果显式的使用函数模板,则使用<> 类型列表
    // Max<>(a, b);

    // 如果函数模板会产生更好的匹配，使用函数模板
    // Max1(c, a);
    // Max(1.0, 2.0);

    // cout<<"Max(a, b)"<<Max(1.0, 2.0, 3.0)<<endl;
    cout << "Max(a, b)" << Max<>(a, c) << endl;
}

// 继承中父子类和模板类的结合情况

// class B
// {
// public:
// 	B(int b)
// 	{
// 		this->b = b;
// 	}

// private:
// 	int b;

// };

// template <typename T>
// class A : public B
// {
// public:
//     A(T t):B(0)
//     {this->t = t;}
//     T &getT(){return t;}
// private:
//     T t;
// };

// template <typename T>
// class A
// {
// public:
//     // 函数的参数列表使用虚拟类型
//     A(T t)
//     {
//         this->t = t;
//     }
//     // 成员函数返回值使用虚拟类型
//     T &getT()
//     {
//         return t;
//     }
//     A operator+(const A &other);
//     void print();

// private:
//     // 成员变量使用虚拟类型
//     T t;
// };

// class B : public A<int>
// {
// public:
//     B(int b) : A<int>(b)
//     {
//         this->b = b;
//     }

// private:
//     int b;
// };

// void print(A<int> &a)
// {
//     cout << a.getT() << endl;
// }

// void printB(B &b)
// {
//     cout << "b(888): " << b.getT() << endl;
// }

// template <typename T>
// A<T> A<T>::operator+(const A &other)
// {
//     A<T> temp;
//     temp.t = this->t + other.t;
//     return temp;
// }

// template <typename T>
// void A<T>::print()
// {
//     cout << this->t << endl;
// }

// template <typename T>
// class F
// {
// public:
//     F(T t = 0);

//     T &getT();

//     F operator+(const F &other);

//     void print();

// private:
//     T t;
// };

// template <typename T>
// F<T>::F(T t)
// {
//     this->t = t;
// }

// template <typename T>
// T &F<T>::getT()
// {
//     return t;
// }

// template <typename T>
// F<T> F<T>::operator+(const F<T> &other)
// {
//     F tmp; // 类的内部类型可以显示声明也可以不显示
//     tmp.t = this->t + other.t;
//     return tmp;
// }

// template <typename T>
// void F<T>::print()
// {
//     cout << this->t << endl;
// }

// void testF()
// {
//     F<int> a(666), b(888);
//     // cout<<a.getT()<<endl;

//     F<int> tmp = a + b;
//     // F<int> tmp1 = addF<int>(a, b);

//     tmp.print();
//     // tmp1.print();
// }


template <typename T>
class A
{
public:
	A(T t=0);

	T &getT();

	A operator +(const A &other);

	void print();

public:
	static int count;
private:
	T t;
};

template <typename T> int A<T>::count = 555;

template <typename T>
A<T>::A(T t)
{
	this->t = t;
}

template <typename T>
T &A<T>::getT()
{
	return t;
}

template <typename T>
A<T> A<T>::operator+(const A<T> &other){
	A tmp; //类的内部类型可以显示声明也可以不显示
	tmp.t =this->t + other.t;
	return tmp;
}

template <typename T>
void A<T>::print(){
	cout<<this->t<<endl;
}

void staticTest()
{
    A<int>  a(666), b(888);
	A<int> tmp = a + b;

    A<float> c(777), d(999);

	a.count = 888;

	cout<<"b.count:"<<b.count<<endl;

	cout<<"c.count:"<<c.count<<endl;
	cout<<"d.count:"<<d.count<<endl;
	c.count = 1000;
	cout<<"修改后, d.count:"<<d.count<<endl;


}




int main(void)
{

    // demoTest();
    // compareTest();
    // templateClassTest();

    // swapTest();
    //  maxTest();

    // A<int> a(66);
    // B b(888);

    // print(a);
    // printB(b);

    //testF();

    //staticTest();

    return 0;
}
