#include <iostream>

using namespace std;

template <typename  T>
class Vector
{
	friend ostream &operator<< <T> (ostream &out, const Vector &object);
public:
	Vector(int size = 128); //构造函数
	Vector(const Vector &object); //拷贝构造函数
	//Vector<int> a(10); a
	//operator<<()

	int getLength();//获取内部储存的元素个数

	//Vector<int> a1, a2;  a1[0]
	T& operator[](int index);
	 //a1 = a2 = a3;
	Vector &operator=(const Vector &object);
	~Vector(); //析构函数

private:
	T *m_base;
	int m_len;
};
