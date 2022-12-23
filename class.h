//class.h
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
using namespace std;
template <class NodeType>class Node;
template <class NodeType>class DoubleLinkList;
template <class NodeType>
class Node
{
private:
	friend class DoubleLinkList<NodeType>;//˫�����ǽڵ����Ԫ 
	friend ostream& operator<<(ostream&, NodeType&);
	friend istream& operator<<(istream&, NodeType&);
public:
	Node();
	Node(NodeType&);
	~Node();
	NodeType Data;//������ 
	Node<NodeType>* NextNode;//��ָ�� 
	Node<NodeType>* PreviousNode;//��ָ��	
};
template<class NodeType>
ostream& operator<<(ostream& output, Node<NodeType>& Target)
{
	output << Target.Data;
	return output;
}
template <class NodeType>
istream& operator<<(istream& input, Node<NodeType>& Target)
{
	input >> Target.Data;
	return input;
}
template <class NodeType>
Node<NodeType>::Node() :Data(), NextNode(NULL), PreviousNode(NULL)//�����޲ι��캯�� 
{
}
template <class NodeType>
Node<NodeType>::Node(NodeType& Value)//�����вι��캯�� 
{
	Data = Value;
	NextNode = NULL;
	PreviousNode = NULL;
}
template <class NodeType>
Node<NodeType>::~Node()//������������ 
{
}
template <class NodeType>
class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList();
	bool isEmpty();
	void inserart_At_Front(NodeType& Value);//ͷ������ 
	void inserart_At_Rear(NodeType& Value);//β������ 
	bool Remove_From_Front();
	bool Remove_From_Rear();
	void Traverse_Forward();//��ͷ������ 
	void Tracerse_Backward();//��β������ 
	int Lenth_of_DoubleLinkList();//�õ�˫����ĳ��� 
	Node<NodeType>* CreateNode(NodeType& Value);//����һ��˫���� 
	void Sort_Data_By_Id();//��ѧ������ 
	void Sort_Data_By_Score();//���������� 
	void Read_File();//���ļ� 
	void Write_file();//д�ļ� 
	void Search_According_Name(string n);//�����ֲ�ѯ 
	void Search_According_Id(string p);//��ѧ�Ų�ѯ 
private:
	Node<NodeType>* FirstNode;
	Node<NodeType>* RearNode;
};
template <class NodeType>
DoubleLinkList<NodeType>::DoubleLinkList() :FirstNode(NULL), RearNode(NULL)//˫������޲ι��캯��
{
}
template <class NodeType>
DoubleLinkList<NodeType>::~DoubleLinkList()//˫������������� 
{
	Node<NodeType>* CurrentNode = FirstNode, * TempNode;
	while (CurrentNode != NULL)
	{
		TempNode = CurrentNode;
		CurrentNode = CurrentNode->NextNode;
		delete TempNode;
	}

}
template <class NodeType>
bool DoubleLinkList<NodeType>::isEmpty()//�ж������Ƿ�Ϊ�� 
{
	if (FirstNode == NULL)
	{
		cout << "���ǵ�һλѧ������Ϣ" << endl;
		return true;
	}
	else
		return false;
}
template <class NodeType>
Node <NodeType>* DoubleLinkList<NodeType>::CreateNode(NodeType& Value)//����һ������ 
{
	Node<NodeType>* NewNode = new Node<NodeType>(Value);
	assert(NewNode != NULL);
	return NewNode;
}
template <class NodeType>
void DoubleLinkList<NodeType>::inserart_At_Front(NodeType& Value)//ͷ�巨 
{
	Node<NodeType>* NewNode = CreateNode(Value);
	if (isEmpty())
		FirstNode = RearNode = NewNode;
	else
	{
		FirstNode->PreviousNode = NewNode;
		NewNode->NextNode = FirstNode;
		FirstNode = NewNode;
		FirstNode->PreviousNode = NULL;
	}
	//cout<<FirstNode->Data;
	cout << "\n������ɹ�" << endl;

}
template <class NodeType>
void DoubleLinkList<NodeType>::inserart_At_Rear(NodeType& Value)//β�巨 
{
	Node<NodeType>* NewNode = CreateNode(Value);
	if (isEmpty())
		FirstNode = RearNode = NewNode;
	else
	{
		RearNode->NextNode = NewNode;
		NewNode->PreviousNode = RearNode;
		RearNode = NewNode;
		RearNode->NextNode = NULL;
	}
	//cout<<RearNode->Data;
	cout << "\n������ɹ�" << endl;
}
template <class NodeType>
bool DoubleLinkList<NodeType>::Remove_From_Front()//ͷ��ɾ�� 
{
	if (isEmpty())
	{
		cout << "\nû��ѧ����Ϣ���޷�ɾ����" << endl;
		return false;
	}
	else
	{
		Node<NodeType>* CurrentNode = FirstNode;
		if (FirstNode == RearNode)
			FirstNode = RearNode = NULL;
		else
		{
			FirstNode = FirstNode->NextNode;
			FirstNode->PreviousNode = NULL;
		}
		delete CurrentNode;
		cout << "\n�ɹ�ɾ����һ��ѧ������Ϣ" << endl;
		return true;

	}
}
template <class NodeType>
bool DoubleLinkList<NodeType>::Remove_From_Rear()//β��ɾ�� 
{
	if (isEmpty())
	{
		cout << "û��ѧ����Ϣ���޷�ɾ����" << endl;
		return false;
	}
	else
	{
		Node<NodeType>* CurrentNode = RearNode;
		if (FirstNode == RearNode)
			FirstNode = RearNode = NULL;
		else
		{
			RearNode = RearNode->PreviousNode;
			RearNode->NextNode = NULL;
		}
		delete CurrentNode;
		cout << "\n�ɹ�ɾ�����һ��ѧ������Ϣ" << endl;
		return true;
	}
}
template <class NodeType>
void DoubleLinkList<NodeType>::Traverse_Forward()//ͷ������ 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		cout << CurrentNode->Data << " ";
		CurrentNode = CurrentNode->NextNode;
	}
}
template <class NodeType>
void DoubleLinkList<NodeType>::Tracerse_Backward()//β������ 
{
	Node<NodeType>* CurrentNode = RearNode;
	while (CurrentNode != NULL)
	{
		cout << CurrentNode->Data << " ";
		CurrentNode = CurrentNode->PreviousNode;
	}

}
template <class NodeType>
void DoubleLinkList<NodeType>::Sort_Data_By_Id()//��ѧ������ 
{
	Node<NodeType>* CurrentNode, * NewNode;
	NodeType TempNode;
	for (NewNode = FirstNode; NewNode != NULL; NewNode = NewNode->NextNode)
	{
		for (CurrentNode = NewNode->NextNode; CurrentNode != NULL; CurrentNode = CurrentNode->NextNode)
		{
			if ((double)NewNode->Data > (double)CurrentNode->Data)
			{
				TempNode = CurrentNode->Data;
				CurrentNode->Data = NewNode->Data;
				NewNode->Data = TempNode;
			}
		}
	}
	cout << "\n��ѧ�Ŵ�С��������ɹ�" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Sort_Data_By_Score()//���������� 
{
	Node<NodeType>* CurrentNode, * NewNode;
	NodeType TempNode;
	for (NewNode = FirstNode; NewNode != NULL; NewNode = NewNode->NextNode)
	{
		for (CurrentNode = NewNode->NextNode; CurrentNode != NULL; CurrentNode = CurrentNode->NextNode)
		{
			if ((float)NewNode->Data < (float)CurrentNode->Data)
			{
				TempNode = CurrentNode->Data;
				CurrentNode->Data = NewNode->Data;
				NewNode->Data = TempNode;
			}
		}
	}
	cout << "\n�������Ӹߵ�������ɹ�" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Read_File()//���ļ��ж�ȡ��Ϣ 
{
	ifstream file("user.txt", ios::in);
	NodeType TempData;
	if (!file)
	{
		cout << "û��ԭʼ�ļ���" << endl;
		system("pause");
		exit(0);
	}
	Node<NodeType>* NewNode = new Node<NodeType>;
	NewNode->PreviousNode = NULL;
	NewNode->NextNode = NULL;
	FirstNode = RearNode = NewNode;
	file >> NewNode->Data;
	while (!file.eof())//eof()���ļ�ĩβ������� 
	{
		NewNode = new Node<NodeType>;
		NewNode->PreviousNode = RearNode;
		RearNode->NextNode = NewNode;
		NewNode->NextNode = NULL;
		RearNode = NewNode;
		file >> NewNode->Data;
		//cout<<NewNode->Data<<endl;
	}
	if (RearNode == FirstNode)
	{
		delete RearNode;
		FirstNode = RearNode = NULL;
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		RearNode = RearNode->PreviousNode;
		delete RearNode->NextNode;
		RearNode->NextNode = NULL;
		cout << "��ȡ�ɹ�" << endl;
	}
	file.close();
}
template <class NodeType>
void DoubleLinkList<NodeType>::Write_file()//����Ϣд���ļ��� 
{
	ofstream out("user.txt");
	if (!out)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		out << CurrentNode->Data;
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "�ɹ�д��" << endl;
	out.close();
}
template <class NodeType>
void DoubleLinkList<NodeType>::Search_According_Id(string p)//��ѧ������ 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		if (CurrentNode->Data == p)
		{
			cout << "��ѧ������ϢΪ��" << endl;
			cout << CurrentNode->Data << endl;
			return;
		}
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "û�и�ѧ����" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Search_According_Name(string n)//���������� 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		if (CurrentNode->Data == n)
		{
			cout << "��ѧ������ϢΪ��" << endl;
			cout << CurrentNode->Data << endl;
			return;
		}
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "û�и�ѧ����" << endl;
}

