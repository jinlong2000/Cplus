//main.cpp
#include <iostream>
#include "information.h"
#include "class.h" 
#include<string>
using namespace std;
int main()
{
	DoubleLinkList <Information> List;
	int Option;
	Information Value;
	do
	{
		cout << "\n学籍管理系统"
			<< "\n-------------------------"
			<< "\n1.在首部插入一个学生信息。"
			<< "\n2.在尾部插入一个学生信息。"
			<< "\n3.从首部删除一个学生信息。"
			<< "\n4.从尾部删除一个学生信息。"
			<< "\n5.从首部输出学生信息。"
			<< "\n6.从尾部输出学生信息。"
			<< "\n7.按姓名查找学生。"
			<< "\n8.按学号查找学生"
			<< "\n9.将学生信息按学号从小到大排序。"
			<< "\n10.将学生信息按分数从高到低排序。"
			<< "\n11.将学生信息存入指定文件中。"
			<< "\n12.读取指定文件中的学生信息。"
			<< "\n0.退出。"
			<< "\n------------------------"
			<< "\n输入您的选择：";
		cin >> Option;
		switch (Option)
		{

		case 1:
		{
			cout << "\n";
			cin >> Value;
			List.inserart_At_Front(Value);
			system("pause");
			system("cls");
			break;

		}
		case 2:
		{
			cout << "\n";
			cin >> Value;
			List.inserart_At_Rear(Value);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			List.Remove_From_Front();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			List.Remove_From_Rear();
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			List.Traverse_Forward();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			List.Tracerse_Backward();
			system("pause");
			system("cls");
			break;
		}
		case 12:
		{
			List.Read_File();
			system("pause");
			system("cls");
			break;
		}
		case 11:
		{
			List.Write_file();
			system("pause");
			system("cls");
			break;
		}

		case 9:
		{
			List.Sort_Data_By_Id();
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			List.Sort_Data_By_Score();
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			string p;
			cout << "请输入你要查询的学生姓名：";
			cin >> p;
			List.Search_According_Name(p);
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			string n;
			cout << "请输入你要查询的学生学号：";
			cin >> n;
			List.Search_According_Id(n);
			system("pause");
			system("cls");
			break;
		}

		default:
		{
			Option = 0;
			break;
		}
		}
	} while (Option != 0);
	return 0;
}
