#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define BUFSIZE 1024

// 实现文件的二进制拷贝
int copyFile(const char *dest, const char *src)
{
    FILE *fp1 = NULL, *fp2 = NULL;

    fopen_s(&fp1, src, "rb");

    if (fp1 == NULL)
    {
        return -1;
    }

    fopen_s(&fp2, dest, "wb");

    if (fp1 == NULL)
    {
        return -2;
    }

    char buffer[BUFSIZE];
    int readlen, writelen;

    while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0)
    {
        writelen = fwrite(buffer, 1, readlen, fp2);
        if (readlen != writelen)
        {
            return -3;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

// 第一种情况，throw 普通类型，和函数返回传值是一样的
int copyfile2(char *dest, char *src)
{
    FILE *fp1 = NULL, *fp2 = NULL;

    // rb 只读方式打开一个二进制文件，只允许读取数据
    fopen_s(&fp1, src, "rb");

    if (fp1 == NULL)
    {
        // int ret = -1;
        char ret = 'a';
        throw ret;
    }

    // wb 以只写的方式打开或新建一个二进制文件，只允许写数据。
    fopen_s(&fp2, dest, "wb");
    if (fp2 == NULL)
    {
        throw -2;
    }

    char buffer[BUFSIZE];
    int readlen, writelen;

    // 如果读到数据，则大于0
    while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0)
    {
        writelen = fwrite(buffer, 1, readlen, fp2);
        if (readlen != writelen)
        {
            throw -3;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int copyfile1(char *dest, char *src)
{
    return copyfile2(dest, src);
}

// 第二种情况，throw 字符串类型，实际抛出的指针，而且，修饰指针的const 也要严格进行类型匹配
int copyfile3(char *dest, char *src)
{
    FILE *fp1 = NULL, *fp2 = NULL;

    // rb 只读方式打开一个二进制文件，只允许读取数据
    fopen_s(&fp1, src, "rb");

    if (fp1 == NULL)
    {
        const char *error = "大佬,你的源文件打开有问题";
        printf("throw 前,error 的地址：%p\n", error);
        throw error;
    }

    // wb 以只写的方式打开或新建一个二进制文件，只允许写数据。
    fopen_s(&fp2, dest, "wb");
    if (fp2 == NULL)
    {
        throw -2;
    }

    char buffer[BUFSIZE];
    int readlen, writelen;

    // 如果读到数据，则大于0
    while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0)
    {
        writelen = fwrite(buffer, 1, readlen, fp2);
        if (readlen != writelen)
        {
            throw -3;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

// int copyfile1(char *dest, char *src)
// {
//     return copyfile3(dest, src);
// }

/*
设计一个数组类容器 Vector，重载[]操作，数组初始化时，对数组的个数进行有效检查
1）index<0 抛出异常errNegativeException
2）index = 0 抛出异常 errZeroException
3）index>1000抛出异常errTooBigException
4）index<10 抛出异常errTooSmallException
5）errSizeException类是以上类的父类，实现有参数构造、并定义virtual void printError()输出错误。

*/
using namespace std;
class errSizeException
{
public:
    errSizeException(int size)
    {
        m_size = size;
    }
    virtual void printError()
    {
        std::cout << "size:" << m_size << std::endl;
    }

protected:
    int m_size;
};

class errNegativeException : public errSizeException
{
public:
    errNegativeException(int size) : errSizeException(size){};
    virtual void printError()
    {
        std::cout << "errNegativeException size: " << m_size << std::endl;
    }
};

class errZeroException : public errSizeException
{
public:
    errZeroException(int size) : errSizeException(size)
    {
    }

    virtual void printError()
    {
        cout << "errZeroException size: " << m_size << endl;
    }
};

class errTooBigException : public errSizeException
{
public:
    errTooBigException(int size) : errSizeException(size)
    {
    }

    virtual void printError()
    {
        cout << "errTooBigException size: " << m_size << endl;
    }
};

class errTooSmallException : public errSizeException
{
public:
    errTooSmallException(int size) : errSizeException(size)
    {
    }

    virtual void printError()
    {
        cout << "errTooSmallException size: " << m_size << endl;
    }
};

class Vector
{
public:
    Vector(int size = 128); // 构造函数

    int getLength(); // 获取内部储存的元素个数

    int &operator[](int index);

    ~Vector();

private:
    int *m_base;
    int m_len;
};

Vector::Vector(int len)
{
    if (len < 0)
    {
        throw errNegativeException(len);
    }
    else if (len == 0)
    {
        throw errZeroException(len);
    }
    else if (len > 1000)
    {
        throw errTooBigException(len);
    }
    else if (len < 10)
    {
        throw errTooSmallException(len);
    }

    m_len = len;
    m_base = new int[len];
}

Vector::~Vector()
{
    if (m_base)
        delete[] m_base;
    m_len = 0;
}

int Vector::getLength()
{
    return m_len;
}

int &Vector::operator[](int index)
{
    return m_base[index];
}

class Student
{
public:
    Student(int age)
    {
        if (age > 249)
        {
            throw out_of_range("年龄太大");
        }
        m_age = age;
        m_space = new int[1024 * 1024 * 100];
    }

private:
    int m_age;
    int *m_space;
};

int main(void)
{
    // int ret = 0;

    // try
    // {
    //     ret = copyfile1("dest.txt", "src.txt");
    // }
    // catch (int error)
    // {
    //     printf("出现异常啦！%d\n", error);
    // }
    // catch (char error)
    // {
    //     printf("出现异常啦！%c\n", error);
    // }

    // ret = copyFile("dest.txt", "src.txt");

    // if(ret != 0){
    // 	switch(ret){
    // 	case -1:
    // 		printf("打开源文件失败!\n");
    // 		break;
    // 	case -2:
    // 		printf("打开目标文件失败!\n");
    // 		break;
    // 	case -3:
    // 		printf("拷贝文件时失败!\n");
    // 		break;
    // 	default:
    // 		printf("出现未知的情况!\n");
    // 		break;
    // 	}
    // }

    // try
    // {
    //     Vector v(10);
    //     for (int i = 0; i < v.getLength(); i++)
    //     {
    //         v[i] = i + 10;
    //         printf("v[i]: %d\n", v[i]);
    //     }
    // }
    // catch (errSizeException &err)
    // {
    //     err.printError();
    // }

    try
    {
        for (int i = 1; i < 1024; i++)
        {
            Student *vc = new Student(25);
        }
    }
    catch (out_of_range &e)
    {
        cout << "捕捉到异常：" << e.what() << endl;
    }
    catch (bad_alloc &e)
    {
        cout << "捕捉到动态内存分配的异常：" << e.what() << endl;
    }

    system("pause");
    return 0;
}
