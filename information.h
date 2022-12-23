//information.h
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Information
{
	friend ostream& operator<<(ostream& output, Information& Target);//输出流重载 

	friend istream& operator>>(istream& input, Information& Target);//输入流重载 

	friend ofstream& operator<<(ofstream& output, Information& Target); //文件输入流 

	friend ifstream& operator>>(ifstream& input, Information& Target);//文件输出流 

	friend bool operator ==(Information, string);
public:
	Information();
	Information(Information&);
	~Information();
	operator float();
	operator double();
	string Name;
	string Address;
	string Id;
	string Score;
	string Sex;
};

Information::Information() :Name("\0"), Address("\0"), Id("\0"), Score("\0"), Sex("\0") {}

Information::Information(Information& Value)
{
	Address = Value.Address;
	Id = Value.Id;
	Name = Value.Name;
	Score = Value.Score;
	Sex = Value.Sex;
}

Information::~Information() {}

Information::operator float()
{
	float Temp = 0;
	for (int i = 0; Score[i]; i++)
	{
		Temp *= 10;
		Temp += (Score[i] - '0');
	}
	return Temp;
}

Information::operator double()
{
	double Temp = 0;
	for (int i = 0; Id[i]; i++)
	{
		Temp *= 10;
		Temp += (Id[i] - '0');
	}
	return Temp;
}


bool operator ==(Information stu, string Name)//重载等号运算符，便于查找 
{
	if (stu.Name == Name || stu.Id == Name)
		return true;
	return false;
}

ostream& operator<<(ostream& output, Information& Target)
{
	output << "姓名：" << Target.Name << endl;
	output << "地址：" << Target.Address << endl;
	output << "学号：" << Target.Id << endl;
	output << "成绩：" << Target.Score << endl;
	output << "性别：" << Target.Sex << endl;
	return output;
}
istream& operator>>(istream& input, Information& Target)
{
	cout << "姓名："; input >> Target.Name;
	cout << "地址："; input >> Target.Address;
	cout << "学号："; input >> Target.Id;
	cout << "成绩："; input >> Target.Score;
	cout << "性别："; input >> Target.Sex;
	return input;
}
ofstream& operator<<(ofstream& output, Information& Target)//重载文件输出流
{
	output << Target.Name << endl;
	output << Target.Address << endl;
	output << Target.Id << endl;
	output << Target.Score << endl;
	output << Target.Sex << endl;
	return output;
}
ifstream& operator>>(ifstream& input, Information& Target)//重载文件输入流 
{
	input >> Target.Name;
	input >> Target.Address;
	input >> Target.Id;
	input >> Target.Score;
	input >> Target.Sex;
	return input;
}
