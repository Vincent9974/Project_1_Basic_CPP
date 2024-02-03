#include <iostream>
#include <cstring>
using namespace std;

#include "Vector.cpp"

class Student{
	friend ostream &operator<<(ostream &out, const Student &object);
public:
	Student(){
		age = 0;
		name[0] = '\0';
	}

	Student(int _age, char *_name){
		age = _age;
		strcpy_s(name, 64, _name);
	}

	void print(){
		cout<<name<<", "<<age<<endl;
	}

	~Student(){

	}

private:
	int age;
	char name[64];
};

ostream &operator<<(ostream &out, const Student &object){
	out<<"("<<object.name<<" , "<<object.age<<")";
	return out;
}

int main(){
	Student s1(18, "李小花");
	Student s2(19, "王大炮");

	Vector<Student *> studentVector(2);

	studentVector[0] = &s1;
	studentVector[1] = &s2;

	/*for(int i=0; i<studentVector.getLength(); i++){
		studentVector[i].print();
	}*/

	cout<<studentVector<<endl;
	system("pause");

	//ostream cout;
	Vector<int> myVector(10);
	//int a[10]; len: sizeof(a)/sizeof(a[0])
	for(int i=0; i<myVector.getLength(); i++){
		myVector[i] = i;
	}

	cout<<myVector<<endl;
	system("pause");

	for(int i=0; i<myVector.getLength(); i++){
		cout<<myVector[i]<<endl;
	}

	//测试拷贝构造函数
	Vector<int> myIntVector1(myVector);
	cout<<"myIntVector1 中的元素如下："<<endl;
	for(int i=0; i<myIntVector1.getLength(); i++){
		cout<<myIntVector1[i]<<endl;
	}
	cout<<"---end---"<<endl;

	//测试赋值运算符重载
	Vector<int> myIntVector2(1);
	myIntVector2 = myIntVector1;

	cout<<"myIntVector2 中的元素如下："<<endl;
	for(int i=0; i<myIntVector1.getLength(); i++){
		cout<<myIntVector1[i]<<endl;
	}
	cout<<"---end---"<<endl;


	Vector<float> myVector1(10);
	//int a[10]; len: sizeof(a)/sizeof(a[0])
	for(int i=0; i<myVector1.getLength(); i++){
		myVector1[i] = i*0.1f;
	}

	for(int i=0; i<myVector1.getLength(); i++){
		cout<<myVector1[i]<<endl;
	}

	system("pause");
	return 0;
}