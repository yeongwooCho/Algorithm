#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class GenListNode
{
	friend class GenList;
private:
	bool flag; //List(true == w) or Node(false == b)
	GenListNode* next; //�������� node��?
	char Nodename;
	union
	{
		GenListNode* dlink; //�Ͼ� �簢��
		int data; //� �簢��
	};
public:
	GenListNode(char name)
	{
		next = NULL;
		flag = 1;
		dlink = NULL;
		Nodename = name;
	}

	GenListNode(int d)
	{
		next = NULL;
		flag = 0;
		data = d;
		Nodename = 0;
	}
};

class GenList
{
private:
	int Number;
	GenListNode *first;
public:
	GenList(ifstream &f) //��ü ������ ���ÿ� GenList�ϼ���Ű��
	{
		f >> Number;
		int num = Number;
		GenListNode* A = new GenListNode('A');
		first = A;

		while (num > 0)
		{
			char ch1; char ch2;
			f >> ch1; f >> ch2;
			//���    //w or b

			if (ch2 == 'w')
			{
				char buf[100];
				f.getline(buf, 100);

				for (int i = 0; (2 * i) < (signed)strlen(buf); i++)
				{
					cout << buf[2 * i + 1] << endl; //������� ���� �޾ұ⿡ ������ ġ���
					InsertLink(ch1, buf[2 * i + 1]);
					//��� insert������ ���ؾ���
				}
			}
			else
			{
				int x1, y1, x2, y2;
				f >> x1 >> y1 >> x2 >> y2;
				int value = (x2 - x1) * (y2 - y1);
				//int���� 4���� ����� insert
				cout << ch1 << ' ' << ch2 << ' ' << value << endl;

				InsertData(ch1, value);
				//��� insert������ ���ؾ���
			}
			num--;
		}

	}

	void InsertLink(char host, char name)
	{
		GenListNode* newNode = new GenListNode(name);
		GenListNode* sear = search(host); //�� �̸��� ���� node
		cout << "���δ� : "<< sear->Nodename << endl;
		cout << "flag : " << sear->flag << endl << endl;
		if (sear->dlink == NULL) { sear->dlink = newNode; }
		else
		{
			GenListNode* check = sear->dlink;
			while (check->next != NULL)
			{
				check = check->next;
			}
			check->next = newNode;
		}
	}
	void InsertData(char host, int d)
	{
		GenListNode* sear = search(host); //�� �̸��� ���� node
		sear->data = d;
		sear->flag = 0;
		//������ �����͵��� 1�� �ް� �װ� ��簢���̸� flag�� 0���� ����
		cout << "���� : " << sear->Nodename << endl;
		cout << "flag : " << sear->flag << endl;
		cout << "���� �簢���̸� ���̴� " << sear->data << "����!";
		cout << endl <<endl;
	}

	GenListNode* search(char checkName)
	{
		//�ϴٵ����� ã�Ƴ�
		GenListNode* dli = NULL;
		GenListNode* ne = NULL;
		while (first != NULL) {
			if (first->Nodename == checkName) { return first; }
			if (first->flag == 0) { return search(first->next, checkName); }
			else { //����Ʈ�϶�
				if (first->dlink != NULL) { dli = search(first->dlink, checkName); }
				ne = search(first->next, checkName);
				//�˻��ϰ��ִ� ��尡 list�϶� �װ��� next�� ���°Ͱ� dlink�� ���°�
				if (dli == NULL)
				{
					if (ne != NULL) { return ne; }
					else return NULL;
				}
				else { return dli; }
			}
		}
		return NULL;
	}

	GenListNode* search(GenListNode* ptr, char checkName)
	{
		GenListNode* dli = NULL;
		GenListNode* ne = NULL;
		if (ptr != NULL) {
			if (ptr->Nodename == checkName) { return ptr; }
			if (ptr->flag == 0) { return search(ptr->next, checkName); }
			else {
				if (ptr->dlink != NULL) { dli = search(ptr->dlink, checkName); }
				ne = search(ptr->next, checkName);
				if (dli == NULL)
				{
					if (ne != NULL) { return ne; }
					else return NULL;
				}
				else { return dli; }
			}
		}
		return NULL;
	}

	int searchData(void)
	{
		char Check = first->Nodename;
		//first�� Nodename �� A�̴�.
		//���� �������� ��Ƶΰ� ++ �����ڷ� A���� Number��ŭ ���ĺ��� ���Ƹ��ڴ�
		int sumData = 0; // search�ؼ� ���� �簢���� ��簢���̸� data���� ���ϰڴ�
		GenListNode* ptr = NULL;
		int num = Number;
		while (num > 0)
		{
			ptr = search(Check); //Check�� search�ؼ� ��� �ҷ���
			//search�� Nodename�� �˻��ϴ� �� �̰�,
			//ó���� �־��� �簢�� ������ �� �̸��� ���� �̹Ƿ�, �� �˰����� ���
			if (ptr->flag == 0) { sumData += ptr->data; }

			Check++;  //A B C ...
			num--;
		}
		return sumData;

	}
	void Print(void)
	{
		int Sum = searchData();

		ofstream ofs;
		ofs.open("nested.out");
		ofs << Sum;
		cout << Sum;
		ofs.close();
	}
};


int main()
{
	ifstream ifs;
	ifs.open("nested.inp");
	GenList Nested(ifs);
	//�Է°� ���ÿ� Generalize List�� �ϼ���Ű��
	ifs.close();

	Nested.Print();
	//�ϼ��� ����Ʈ���� �����͸� ��ﻩ�� Print����

	return 0;
}
