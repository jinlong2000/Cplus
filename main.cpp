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
		cout << "\nѧ������ϵͳ"
			<< "\n-------------------------"
			<< "\n1.���ײ�����һ��ѧ����Ϣ��"
			<< "\n2.��β������һ��ѧ����Ϣ��"
			<< "\n3.���ײ�ɾ��һ��ѧ����Ϣ��"
			<< "\n4.��β��ɾ��һ��ѧ����Ϣ��"
			<< "\n5.���ײ����ѧ����Ϣ��"
			<< "\n6.��β�����ѧ����Ϣ��"
			<< "\n7.����������ѧ����"
			<< "\n8.��ѧ�Ų���ѧ��"
			<< "\n9.��ѧ����Ϣ��ѧ�Ŵ�С��������"
			<< "\n10.��ѧ����Ϣ�������Ӹߵ�������"
			<< "\n11.��ѧ����Ϣ����ָ���ļ��С�"
			<< "\n12.��ȡָ���ļ��е�ѧ����Ϣ��"
			<< "\n0.�˳���"
			<< "\n------------------------"
			<< "\n��������ѡ��";
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
			cout << "��������Ҫ��ѯ��ѧ��������";
			cin >> p;
			List.Search_According_Name(p);
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			string n;
			cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�";
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
