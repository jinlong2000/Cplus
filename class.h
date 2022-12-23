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
	friend class DoubleLinkList<NodeType>;//双链表是节点的友元 
	friend ostream& operator<<(ostream&, NodeType&);
	friend istream& operator<<(istream&, NodeType&);
public:
	Node();
	Node(NodeType&);
	~Node();
	NodeType Data;//数据域 
	Node<NodeType>* NextNode;//右指针 
	Node<NodeType>* PreviousNode;//左指针	
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
Node<NodeType>::Node() :Data(), NextNode(NULL), PreviousNode(NULL)//结点的无参构造函数 
{
}
template <class NodeType>
Node<NodeType>::Node(NodeType& Value)//结点的有参构造函数 
{
	Data = Value;
	NextNode = NULL;
	PreviousNode = NULL;
}
template <class NodeType>
Node<NodeType>::~Node()//结点的析构函数 
{
}
template <class NodeType>
class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList();
	bool isEmpty();
	void inserart_At_Front(NodeType& Value);//头部插入 
	void inserart_At_Rear(NodeType& Value);//尾部插入 
	bool Remove_From_Front();
	bool Remove_From_Rear();
	void Traverse_Forward();//从头部遍历 
	void Tracerse_Backward();//从尾部遍历 
	int Lenth_of_DoubleLinkList();//得到双链表的长度 
	Node<NodeType>* CreateNode(NodeType& Value);//创建一个双链表 
	void Sort_Data_By_Id();//按学号排序 
	void Sort_Data_By_Score();//按分数排序 
	void Read_File();//读文件 
	void Write_file();//写文件 
	void Search_According_Name(string n);//按名字查询 
	void Search_According_Id(string p);//按学号查询 
private:
	Node<NodeType>* FirstNode;
	Node<NodeType>* RearNode;
};
template <class NodeType>
DoubleLinkList<NodeType>::DoubleLinkList() :FirstNode(NULL), RearNode(NULL)//双链表的无参构造函数
{
}
template <class NodeType>
DoubleLinkList<NodeType>::~DoubleLinkList()//双链表的析构函数 
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
bool DoubleLinkList<NodeType>::isEmpty()//判断链表是否为空 
{
	if (FirstNode == NULL)
	{
		cout << "这是第一位学生的信息" << endl;
		return true;
	}
	else
		return false;
}
template <class NodeType>
Node <NodeType>* DoubleLinkList<NodeType>::CreateNode(NodeType& Value)//创建一个链表 
{
	Node<NodeType>* NewNode = new Node<NodeType>(Value);
	assert(NewNode != NULL);
	return NewNode;
}
template <class NodeType>
void DoubleLinkList<NodeType>::inserart_At_Front(NodeType& Value)//头插法 
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
	cout << "\n结点插入成功" << endl;

}
template <class NodeType>
void DoubleLinkList<NodeType>::inserart_At_Rear(NodeType& Value)//尾插法 
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
	cout << "\n结点插入成功" << endl;
}
template <class NodeType>
bool DoubleLinkList<NodeType>::Remove_From_Front()//头部删除 
{
	if (isEmpty())
	{
		cout << "\n没有学生信息，无法删除！" << endl;
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
		cout << "\n成功删除第一个学生的信息" << endl;
		return true;

	}
}
template <class NodeType>
bool DoubleLinkList<NodeType>::Remove_From_Rear()//尾部删除 
{
	if (isEmpty())
	{
		cout << "没有学生信息，无法删除！" << endl;
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
		cout << "\n成功删除最后一个学生的信息" << endl;
		return true;
	}
}
template <class NodeType>
void DoubleLinkList<NodeType>::Traverse_Forward()//头部遍历 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		cout << CurrentNode->Data << " ";
		CurrentNode = CurrentNode->NextNode;
	}
}
template <class NodeType>
void DoubleLinkList<NodeType>::Tracerse_Backward()//尾部遍历 
{
	Node<NodeType>* CurrentNode = RearNode;
	while (CurrentNode != NULL)
	{
		cout << CurrentNode->Data << " ";
		CurrentNode = CurrentNode->PreviousNode;
	}

}
template <class NodeType>
void DoubleLinkList<NodeType>::Sort_Data_By_Id()//按学号排序 
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
	cout << "\n按学号从小到大排序成功" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Sort_Data_By_Score()//按分数排序 
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
	cout << "\n按分数从高到低排序成功" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Read_File()//从文件中读取信息 
{
	ifstream file("user.txt", ios::in);
	NodeType TempData;
	if (!file)
	{
		cout << "没有原始文件！" << endl;
		system("pause");
		exit(0);
	}
	Node<NodeType>* NewNode = new Node<NodeType>;
	NewNode->PreviousNode = NULL;
	NewNode->NextNode = NULL;
	FirstNode = RearNode = NewNode;
	file >> NewNode->Data;
	while (!file.eof())//eof()到文件末尾会读两次 
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
		cout << "文件为空" << endl;
	}
	else
	{
		RearNode = RearNode->PreviousNode;
		delete RearNode->NextNode;
		RearNode->NextNode = NULL;
		cout << "读取成功" << endl;
	}
	file.close();
}
template <class NodeType>
void DoubleLinkList<NodeType>::Write_file()//把信息写入文件中 
{
	ofstream out("user.txt");
	if (!out)
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		out << CurrentNode->Data;
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "成功写入" << endl;
	out.close();
}
template <class NodeType>
void DoubleLinkList<NodeType>::Search_According_Id(string p)//按学号排序 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		if (CurrentNode->Data == p)
		{
			cout << "该学生的信息为：" << endl;
			cout << CurrentNode->Data << endl;
			return;
		}
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "没有该学生！" << endl;
}
template <class NodeType>
void DoubleLinkList<NodeType>::Search_According_Name(string n)//按姓名查找 
{
	Node<NodeType>* CurrentNode = FirstNode;
	while (CurrentNode != NULL)
	{
		if (CurrentNode->Data == n)
		{
			cout << "该学生的信息为：" << endl;
			cout << CurrentNode->Data << endl;
			return;
		}
		CurrentNode = CurrentNode->NextNode;
	}
	cout << "没有该学生！" << endl;
}

