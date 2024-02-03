#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// 需求:让用户输入姓名和年龄,并保存到文件中

void wirteTXT()
{
    string name;
    int age;
    ofstream outfile;
    outfile.open("user.txt", ios::out | ios::trunc);
    // outfile.open("user.txt");

    while (1)
    {
        cout << "请输入姓名:" << endl;
        cin >> name;

        // 将输入写入文件
        if (cin.eof())
        {
            break;
        }

        cout << "请输入年龄: " << endl;
        cin >> age;

        stringstream s;
        s << "name:" << name << "\t\tage:" << age << endl;
        outfile << s.str();
    }

    outfile.close();
}

void readTXT()
{
    string name;
    int age;
    string line;
    ifstream infile;
    infile.open("user.txt");

    while (1)
    {
        getline(infile, line);
        if (infile.eof())
        {
            break;
        }

        sscanf_s(line.c_str(), "姓名:%s 年龄:%d", name, sizeof(name), &age);
        cout << "姓名:" << name << "\t\t年龄:" << age << endl;
    }
    infile.close();
}

void binaryWrite()
{
    string name;
    int age;
    ofstream outfile;
    outfile.open("user.dat", ios::out | ios::trunc | ios::binary);

    while (1)
    {
        cout << "请输入姓名:";
        cin >> name;
        if (cin.eof())
        {
            break;
        }

        outfile << name << "\t";

        cout << "请输入姓名:";
        cin >> age;

        outfile.write((char *)&age, sizeof(age));
    }
    outfile.close();
}

void binaryRead()
{
    string name;
    int age;
    ifstream infile;
    infile.open("user.dat", ios::in | ios::binary);

    while (1)
    {
        infile >> name;
        if (infile.eof())
        { // 判断文件是否结束
            break;
        }
        cout << name << "\t";

        // 跳过中间的制表符
        char tmp;
        infile.read(&tmp, sizeof(tmp));

        // infile >> age; //从文本文件中读取整数, 使用这个方式
        infile.read((char *)&age, sizeof(age));
        cout << age << endl; // 文本文件写入
    }

    // 关闭打开的文件
    infile.close();
}

// 函数：从指定位置读取文件内容
void readFromPosition(const std::string &filename, std::streampos position)
{
    // 打开文件
    std::ifstream infile(filename, std::ios::binary);

    if (infile.is_open())
    {
        // 移动文件指针到指定位置
        infile.seekg(position);

        // 从指定位置开始读取文件内容
        std::string content;
        getline(infile, content);

        // 输出读取的内容
        std::cout << "Content from position " << position << ": " << content << std::endl;

        // 关闭文件
        infile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

int seekgTest()
{
    ifstream infile;

    infile.open("write.cpp");
    if (!infile.is_open())
    {
        return 1;
    }

    infile.seekg(-5, infile.end);
    while (!infile.eof())
    {
        string line;
        getline(infile, line);
        cout << line << endl;
    }
    return 0;
};

int tellgTest()
{
    ifstream infile;
    infile.open("write.cpp");
    if(!infile.is_open())
    {
        return 1;
    }

    infile.seekg(-808,infile.end);
    int len = infile.tellg();
    cout << "len:" << len << endl;
    infile.close();
    return 0;
}

int seekpTest()
{
    ofstream outfile;

    outfile.open("test.txt");
    if(!outfile.is_open())
    {
        return 1;
    }

    outfile << "123456";

    outfile.seekp(4, outfile.beg);
    outfile << "AABBCC";
    return 0;
}

void writeNumbers()
{
    ofstream stream;
    int num;
    int n;
    stream.open("num.txt");
    if(!stream.is_open())
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    while(1)
    {
        cout << "请输入一个整数" << endl;
        cin >> num;

        if(cin.eof())
        {
            break;
        }

        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            // cin.ignore();
            cout << "请重新输入" << endl;
            cin >> num;
        }
        stream << num << "\t";
        if(++n %10 ==0)
        {
            stream << endl;
        }
    }
    stream.close();
}

void readNumbers()
{
    ifstream stream;
    int max, min, sum =0;
    int num;
    int count =0;

    stream.open("num.txt");
    if(!stream.is_open())
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }

    stream >> num;
    max = num;
    min = num;
    sum += num;

    while(1)
    {
        stream >> num;
        if (stream.eof()) {
			break;
		}

		count ++;
		sum += num;
		if (num > max) {
			max = num;
		}
		else if (num < min) {
			min = num;
		}

    }
    cout << "max=" << max << endl;
	cout << "min=" << min << endl;
	cout << "average=" << sum / count << endl;

	stream.close();


}

int main()
{

    // wirteTXT();

    // readTXT();

    // binaryWrite();

    // binaryRead();
    // seekgTest(); 

    // tellgTest();

    // seekpTest();

    // writeNumbers();

    readNumbers();

    system("pause");
    return 0;
}