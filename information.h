//information.h
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Information
{
	friend ostream& operator<<(ostream& output, Information& Target);//��������� 

	friend istream& operator>>(istream& input, Information& Target);//���������� 

	friend ofstream& operator<<(ofstream& output, Information& Target); //�ļ������� 

	friend ifstream& operator>>(ifstream& input, Information& Target);//�ļ������ 

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


bool operator ==(Information stu, string Name)//���صȺ�����������ڲ��� 
{
	if (stu.Name == Name || stu.Id == Name)
		return true;
	return false;
}

ostream& operator<<(ostream& output, Information& Target)
{
	output << "������" << Target.Name << endl;
	output << "��ַ��" << Target.Address << endl;
	output << "ѧ�ţ�" << Target.Id << endl;
	output << "�ɼ���" << Target.Score << endl;
	output << "�Ա�" << Target.Sex << endl;
	return output;
}
istream& operator>>(istream& input, Information& Target)
{
	cout << "������"; input >> Target.Name;
	cout << "��ַ��"; input >> Target.Address;
	cout << "ѧ�ţ�"; input >> Target.Id;
	cout << "�ɼ���"; input >> Target.Score;
	cout << "�Ա�"; input >> Target.Sex;
	return input;
}
ofstream& operator<<(ofstream& output, Information& Target)//�����ļ������
{
	output << Target.Name << endl;
	output << Target.Address << endl;
	output << Target.Id << endl;
	output << Target.Score << endl;
	output << Target.Sex << endl;
	return output;
}
ifstream& operator>>(ifstream& input, Information& Target)//�����ļ������� 
{
	input >> Target.Name;
	input >> Target.Address;
	input >> Target.Id;
	input >> Target.Score;
	input >> Target.Sex;
	return input;
}
