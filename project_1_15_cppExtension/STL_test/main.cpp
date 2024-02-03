#include <iostream>
#include <string.h>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include "SizeFilter.hpp"

using namespace std;

class student
{
public:
    student(int age, const char *name)
    {
        this->age = age;
        strncpy(this->name, name, 64);
    }

    student(const student &s)
    {
        this->age = s.age;
        strncpy(this->name, s.name, 64);
        cout << "拷贝构造函数被调用!" << endl;
    }

public:
    int age;
    char name[64];
};

void demo1()
{
    // 第一部分 容器
    vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(3);

    cout << "v1 的元素个数：" << v1.size() << endl;

    cout << "v1中保存的元素：" << endl;
    // 方式1，下标访问
    // for(unsigned int i=0; i<v1.size(); i++){
    //	cout<<v1[i]<<endl;
    // }

    // 方式2，迭代器访问
    // 第二部分 迭代器
    // 1  2  3  4
    // it
    vector<int>::iterator it = v1.begin();
    for (; it != v1.end(); it++)
    {
        cout << *it << endl;
    }

    // 第三部分  算法
    int ncount = count(v1.begin(), v1.end(), 3);
    cout << "v1 中数值为 3 的元素个数：" << ncount << endl;
}

// 容器中直接存放对象，会发生拷贝构造
void demo2()
{
    vector<student> v1;
    student s1(18, "美羊羊");
    student s2(19, "沸羊羊");

    v1.push_back(s1);
    v1.push_back(s2);

    cout << "v1 的学生的个数：" << v1.size() << endl;

    vector<student>::iterator it = v1.begin();
    for (; it != v1.end(); it++)
    {
        cout << (*it).name << ":" << (*it).age << endl;
    }
}

// 容器中存放指针
void demo3()
{
    vector<student *> v1;

    student s1(18, "李小美");
    student s2(19, "王大帅");

    v1.push_back(&s1);
    v1.push_back(&s2);

    cout << "v1 的学生的个数：" << v1.size() << endl;

    // 方式1，下标访问
    // for(unsigned int i=0; i<v1.size(); i++){
    //	cout<<v1[i].name<<": "<<v1[i].age<<endl;
    // }

    vector<student *>::iterator it = v1.begin();
    for (; it != v1.end(); it++)
    {
        cout << (**it).name << ": " << (**it).age << endl;
    }
}

void vector_demo1()
{

    vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(3);

    cout << "v1 的元素个数：" << v1.size() << endl;
    cout << "v1 的容器的大小：" << v1.capacity() << endl;

    cout << v1[0] << endl;

    // vector<int> v3(10, 100);
    // cout << v3.size() <<endl;
    // cout << v3.capacity() << endl;

    // v3.assign(2,999);
    // for(int i=0;i<v3.size();i++)
    // {
    //     cout << v3[i] << endl;
    // }
    // cout << v3.size() <<endl;
    // cout << v3.capacity() << endl;

    // // int test[]={1, 2, 3, 4, 5};
    // // vector<int> v4(test, test+2);

    // cout <<"=="<< endl;
    // vector<int> v4(v3.begin()+3, v3.end());
    // for(int i=0;i<v4.size();i++)
    // {
    //     cout << v4[i] << endl;
    // }

    vector<int> v2(10, 100);
    int test[] = {1, 2, 3, 4, 5};

    vector<int> v3(test, test + 5);

    cout << "v2 的元素个数：" << v2.size() << endl;
    cout << "v2 容器的大小：" << v2.capacity() << endl;

    cout << "v2调用 assign 后：" << endl;
    cout << "v2 的元素个数：" << v2.size() << endl;
    cout << "v2 中存储的元素是: " << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }

    cout << "v3 中存储的元素是: " << endl;
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << endl;
    }

    cout << "===" << endl;
    vector<int> v5(10, 10);
    vector<int> v6;

    cout << v5.size() << endl;
    cout << v5.empty() << endl;
    cout << v6.empty() << endl;

    v5.resize(11, 101);
    cout << v5.size() << endl;

    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.resize(10);
    cout << v5.front() << endl;
    cout << v5.back() << endl;

    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.insert(v5.begin() + 3, 11);
    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.insert(v5.begin() + 3, 2, 11);
    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.insert(v5.begin(), v5.begin() + 3, v5.begin() + 6);
    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.clear();
    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }

    v5.push_back(66);

    cout << "v5 中存储的元素是: " << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5.at(i) << endl;
    }
}

void dequeTest()
{
    deque<int> deqIntA;
    deque<float> deqFloatA;
    // deqIntA.push_back(1);
    // deqIntA.push_back(2);
    // deqIntA.push_back(3);
    // deqIntA.push_back(4);
    // deqIntA.push_back(5);

    // deque<int> deqIntB(deqIntA.begin(), deqIntA.end());

    deque<student *> deqStuP;

    deqIntA.push_back(1);
    deqIntA.push_back(2);
    deqIntA.push_back(3);
    deqIntA.push_back(4);
    deqIntA.push_back(5);
    // deqIntA.pop_front();
    // deqIntA.pop_front();
    // deqIntA.pop_front();
    // deqIntA.push_front(0);

    deqFloatA.push_back(0.1f);
    deqFloatA.push_back(0.2f);
    deqFloatA.push_back(0.3f);
    deqFloatA.push_back(0.4f);
    deqFloatA.push_back(0.5f);

    deque<int> deqIntB(deqIntA.begin(), deqIntA.end());
    deque<int> deqIntC(8, 666);
    deque<int> deqIntD(deqIntA);

    cout << "deqIntA 中存储的元素是: " << endl;
    for (int i = 0; i < deqIntA.size(); i++)
    {
        cout << deqIntA.at(i) << endl;
    }
    cout << "==" << endl;

    for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << "==" << endl;
    for (deque<int>::reverse_iterator rit = deqIntA.rbegin(); rit != deqIntA.rend(); ++rit)
    {
        cout << *rit << endl;
    }

    cout << "==" << endl;
    for (deque<int>::const_iterator cit = deqIntA.cbegin(); cit != deqIntA.cend(); ++cit)
    {
        cout << *cit << endl;
    }
}

void listTest()
{
    list<int> lstInt1;
    lstInt1.push_back(1);
    lstInt1.push_back(2);
    lstInt1.push_back(3);

    list<int> lstInt2(lstInt1.begin(), lstInt1.end()); // 1 2 3
    list<int> lstInt3(5, 8);                           // 8 8 8 8 8
    list<int> lstInt4(lstInt1);

    list<int> lstInt;
    lstInt.push_back(1);
    lstInt.push_back(2);
    lstInt.push_back(3);
    lstInt.push_back(4);
    lstInt.push_back(5);
    lstInt.pop_back();
    lstInt.push_back(5);
    lstInt.push_front(0);
    lstInt.pop_front();

    for (list<int>::iterator it = lstInt.begin(); it != lstInt.end(); ++it)
    {
        cout << *it << endl;
    }

    for (list<int>::reverse_iterator rit = lstInt.rbegin(); rit != lstInt.rend(); ++rit)
    {
        cout << *rit << endl;
    }

    list<int> listA;
    list<int> listB;

    listA.push_back(1);
    listA.push_back(2);
    listA.push_back(3);
    listA.push_back(4);
    listA.push_back(5);

    listB.push_back(11);
    listB.push_back(12);
    listB.push_back(13);
    listB.push_back(14);

    listA.insert(listA.begin(), -1);
    listA.insert(++listA.begin(), 2, -2);
    listA.insert(listA.begin(), listB.begin(), listB.end());

    cout << "==" << endl;
    for (list<int>::iterator it = listA.begin(); it != listA.end(); ++it)
    {
        cout << *it << endl;
    }

    listA.clear();

    listA.push_back(1);
    listA.push_back(2);
    listA.push_back(3);
    listA.push_back(4);
    listA.push_back(5);

    list<int>::iterator itBegin = listA.begin();
    ++itBegin;
    list<int>::iterator itEnd = listA.begin();
    ++itEnd;
    ++itEnd;
    ++itEnd;

    listA.erase(itBegin, itEnd); // 此时容器lstInt包含按顺序的1, 4, 5三个元素。

    listA.erase(listA.begin());

    listA.push_back(4);
    listA.insert(listA.end(), 5, 4);

    // listA.remove(4);

    for (list<int>::iterator it = listA.begin(); it != listA.end();)
    {
        if (*it == 4)
        {
            it = listA.erase(it);
        }
        else
        {
            it++;
        }
    }

    cout << "==" << endl;
    for (list<int>::iterator it = listA.begin(); it != listA.end(); ++it)
    {
        cout << *it << endl;
    }
}

class Student1
{
public:
    Student1()
    {
        cout << "无参构造函数被调用!" << endl;
    }

    Student1(int age, string name, int test)
    {
        this->age = age;
        // strncpy_s(this->name, name, 64);
        cout << "有参构造函数被调用!" << endl;
        cout << "姓名：" << name.c_str() << " 年龄：" << age << endl;
    }

    Student1(const Student1 &s)
    {
        this->age = s.age;
        // strncpy_s(this->name, s.name, 64);

        cout << "拷贝构造函数被调用!" << endl;
    }

    ~Student1()
    {
        cout << "析构函数被调用" << endl;
    }

public:
    int age;
    string name;
};

void emplaceTest()
{
    vector<Student1> vectStu(10);

    cout << "vectStu size:" << vectStu.size() << endl;
    cout << "vectStu capacity:" << vectStu.capacity() << endl;

    // 方法一  先定义对象，再插入
    //  Student1  xiaoHua(18, "校花", 90);
    //  vectStu.push_back(xiaoHua);

    // vectStu.push_back(Student1(18, "校花", 90));

    // vectStu.emplace_back(18, "校花", 90);
    // cout << "vectStu size (1):" << vectStu.size() << endl;
    // cout << "vectStu capacity(1):" << vectStu.capacity() << endl;

    // vectStu.emplace(vectStu.end(), 18, "lixiaohua", 12);

    vectStu.emplace_back(19, "王大锤", 11); // push_back
    cout << "vectStu size (1):" << vectStu.size() << endl;
    cout << "vectStu capacity(1):" << vectStu.capacity() << endl;

    vectStu.emplace(vectStu.end(), 18, "lixiaohua", 12); // 相当于 insert.
    cout << "vectStu size (2):" << vectStu.size() << endl;
    cout << "vectStu capacity (2):" << vectStu.capacity() << endl;
}

// 递归终止函数
void print()
{
    std::cout << std::endl;
}

// 递归模板函数
template <typename T, typename... Args>
void print(T first, Args... args)
{
    std::cout << first << " ";
    print(args...);
}

void templateTest()
{
    print(1, 2.5, "Hello", 'a');
}

class student2
{
public:
    student2(int age)
    {
        this->age = age;
    }

    bool operator<(const student2 &right) const
    {
        return this->age < right.age;
    }

    bool operator>(const student2 &right) const
    {
        return this->age > right.age;
    }

    int getAge() const { return age; }

private:
    int age;
    string name;
};

class funStudent
{
public:
    bool operator()(const student2 &left, const student2 &right)
    {
        cout << "调用了 FunStudent ." << endl;
        ret = left.getAge() < right.getAge();
        return ret;
    }

public:
    int ret;
};

void setTest()
{
    set<int, greater<int>> setInt;

    multiset<int> msetInt;

    for (int i = 0; i < 10; i++)
    {
        setInt.insert(100 - i);
    }

    setInt.insert(99);

    set<int>::iterator it = setInt.begin();
    for (; it != setInt.end(); it++)
    {
        cout << *it;
        cout << " ";
    }

    set<student2, less<student2>> setStu;
    setStu.insert(student2(18));
    setStu.insert(student2(19));

    for (set<student2>::iterator it = setStu.begin(); it != setStu.end(); it++)
    {
        cout << it->getAge();
        cout << " ";
    }

    cout << "===" << endl;

    student2 lixiaohua(18);
    student2 wangdachui(19);

    funStudent funStu;
    funStu(lixiaohua, wangdachui);
    cout << "比较结果：" << funStu.ret << endl;

    setStu.insert(lixiaohua);
    setStu.insert(wangdachui);

    for (set<student2, funStudent>::iterator it = setStu.begin(); it != setStu.end(); it++)
    {
        cout << it->getAge();
        cout << " ";
    }

    cout << "===" << endl;
    pair<set<int>::iterator, bool> ret = setInt.insert(99);
    cout << *ret.first << endl;
    cout << ret.second << endl;
    if (ret.second)
    {
        cout << "插入 成功！" << endl;
    }
    else
    {
        cout << "插入 失败！" << endl;
    }

    set<int> setIntB;
    setIntB.insert(1);
    setIntB.insert(2);
    setIntB.insert(3);
    setIntB.insert(4);
    setIntB.insert(5);

    set<int>::iterator it1 = setIntB.find(60);
    int elem1 = *it1; // elem1 == 4
    cout << "elem1:" << elem1 << endl;
    int iCount = setInt.count(3); // iCount == 1

    set<int>::iterator it2 = setInt.lower_bound(3);
    set<int>::iterator it3 = setInt.upper_bound(3);
    int elem2 = *it2; // i2 == 3
    int elem3 = *it3; // i3 == 4

    // 包含num的区间,左闭右开,两个迭代器it
    pair<set<int>::iterator, set<int>::iterator> pairIt = setInt.equal_range(5);

    cout << endl;
}

void mapTest()
{
    multimap<int, string> mapStu;
    mapStu.insert(pair<int, string>(1, "张三"));
    mapStu.insert(make_pair(2, "李四"));
    mapStu.insert(map<int, string>::value_type(3, "王五"));
    mapStu.insert(map<int, string>::value_type(4, "赵六"));

    for (multimap<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); ++it)
    {
        cout << "key:" << (*it).first << "value:" << (*it).second << endl;
    }

    cout << "===" << endl;

    map<int, string, greater<int>> mapA;
    mapA.insert(pair<int, string>(2, "李四"));
    mapA.insert(pair<int, string>(1, "张三"));
    mapA.insert(pair<int, string>(3, "王五"));
    mapA.insert(pair<int, string>(4, "赵六"));
    for (map<int, string>::iterator it = mapA.begin(); it != mapA.end(); ++it)
    {
        cout << "key:" << (*it).first << "value:" << (*it).second << endl;
    }

    map<int, string, greater<int>>::size_type ret = mapA.erase(1);
    cout << "ret=" << ret << endl;

    multimap<int, string> mmapTeacher; //<班级,老师姓名>
    mmapTeacher.insert(pair<int, string>(101, "李老师"));
    mmapTeacher.insert(pair<int, string>(101, "张老师"));
    mmapTeacher.insert(pair<int, string>(102, "王老师"));
    mmapTeacher.insert(pair<int, string>(102, "赵老师"));

    // map 的查找
    map<int, string>::iterator it = mapStu.find(5);
    if (it != mapStu.end())
    { // 找到了
        cout << "mapStu.find(3) = " << (*it).second << endl;
    }
    else
    { // 没找到
        cout << "找不到键值为3的键值对!" << endl;
    }

    int count = mmapTeacher.count(101);
    multimap<int, string>::iterator mit = mmapTeacher.find(101);

    // for(; mit!=mmapTeacher.end(); mit++){
    //     if((*mit).first == 101){
    //         cout<<"mmapTeacher.find(101) = "<<(*mit).second<<endl;
    //     }else{
    //         break;
    //     }
    // }
    for (int i = 0; i < count; i++, mit++)
    {
        cout << "mmapTeacher.find(101) = " << (*mit).second << endl;
    }

    // equal_range 用法
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> mmiit = mmapTeacher.equal_range(101);

    // 第一个迭代器, 对应begin
    if (mmiit.first != mmapTeacher.end())
    {
        cout << "mmapTeacher.equal_range(101).begin =" << (*mmiit.first).second << endl;
    }

    // 第二个迭代器，对应end
    if (mmiit.second != mmapTeacher.end())
    {
        cout << "mmapTeacher.equal_range(101).end =" << (*mmiit.second).second << endl;
    }

    for (map<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); it++)
    {
        cout << "key: " << (*it).first << " value: " << (*it).second << endl;
    }
}

void queueTest()
{
    queue<int> queueInt;
    queueInt.push(1);
    queueInt.push(2);
    queueInt.push(3);
    queueInt.push(4);
    queueInt.pop();
    queueInt.pop();

    cout << queueInt.front() << endl;

    queue<int> queIntA;
    queIntA.push(1);
    queIntA.push(2);
    queIntA.push(3);
    queIntA.push(4);
    queIntA.push(5);

    queue<int, list<int>> queueList;

    queue<int> queIntB(queIntA); // 拷贝构造
    queue<int> queIntC;
    queIntC = queIntA;

    int iFront = queIntA.front(); // 1
    int iBack = queIntA.back();   // 5

    queIntA.front() = 66; // 66
    queIntA.back() = 88;  // 88

    cout << "==" << endl;
    cout << queIntA.front() << endl;
    cout << queIntA.back() << endl;
}

void priorityTest()
{
    // priority_queue<int> pqA; //默认情况下是值越大，优先级越大
    // priority_queue<int, list<int>, greater<int>> pqA;
    priority_queue<int, deque<int>, greater<int>> pqA; // 使用deque 值越小，优先级越大

    pqA.push(1);
    pqA.push(2);
    pqA.push(3);
    pqA.push(4);
    pqA.push(5);

    while (!pqA.empty())
    {
        cout << pqA.top() << " "; // 读取队首的元素,但元素不出列
        pqA.pop();                // 出队列
    }

    cout << endl;
}

void stackTest()
{
    stack<int> stkInt;
    stkInt.push(1);
    stkInt.push(2);
    stkInt.pop();
    stkInt.push(3);

    while (!stkInt.empty())
    {
        cout << stkInt.top() << " ";
        stkInt.pop();
    }
    cout << endl;

    stack<int> stkIntA;
    stkIntA.push(1);
    stkIntA.push(2);
    stkIntA.push(3);

    int &iTop = stkIntA.top(); // 3
    iTop = 88;                 // 88

    cout << "iTOP:" << iTop << endl;

    while (!stkIntA.empty())
    {
        cout << stkIntA.top() << " ";
        stkIntA.pop();
    }
    cout << endl;
}

void arrayTest()
{
    array<int, 6> a1;   // 一个存放int的array容器
    array<float, 6> a2; // 一个存放float的array容器

    // array<int, 6> a1 = {1, 2, 3, 4, 5, 6}; // 定义时同时初始化
}

void examTest()
{
    sizeFilter<int, set<int>> sf;
    for (int i = 0; i < 10; i++)
    {
        sf.insert(i * 5);
    }

    sf.erase(0);
    sf.erase(45);

    pair<int, bool> pb1 = sf.getMax();
    if (pb1.second)
    {
        cout << "max: " << pb1.first << std::endl;
    }
    else
    {
        cout << "Not Found." << std::endl;
    }

    // 获取最小值
    pair<int, bool> pb2 = sf.getMin();
    if (pb2.second)
    {
        cout << "min: " << pb2.first << std::endl;
    }
}

int main(void)
{

    // demo1();

    // demo2();

    // demo3();

    // vector_demo1();

    // dequeTest();

    // listTest();

    // templateTest();

    // emplaceTest();

    // setTest();

    // mapTest();

    // queueTest();

    // priorityTest();

    // stackTest();

    // arrayTest();

    examTest();

    system("pause");
    return 0;
}