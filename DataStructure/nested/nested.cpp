#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class GenListNode
{
	friend class GenList;
private:
	bool flag; //List(true == w) or Node(false == b)
	GenListNode* next; //다음꺼가 node야?
	char Nodename;
	union
	{
		GenListNode* dlink; //하얀 사각형
		int data; //까만 사각형
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
	GenList(ifstream &f) //객체 생성과 동시에 GenList완성시키자
	{
		f >> Number;
		int num = Number;
		GenListNode* A = new GenListNode('A');
		first = A;

		while (num > 0)
		{
			char ch1; char ch2;
			f >> ch1; f >> ch2;
			//노드    //w or b

			if (ch2 == 'w')
			{
				char buf[100];
				f.getline(buf, 100);

				for (int i = 0; (2 * i) < (signed)strlen(buf); i++)
				{
					cout << buf[2 * i + 1] << endl; //공백까지 같이 받았기에 공백은 치운다
					InsertLink(ch1, buf[2 * i + 1]);
					//어디에 insert할지를 정해야지
				}
			}
			else
			{
				int x1, y1, x2, y2;
				f >> x1 >> y1 >> x2 >> y2;
				int value = (x2 - x1) * (y2 - y1);
				//int변수 4개로 계산후 insert
				cout << ch1 << ' ' << ch2 << ' ' << value << endl;

				InsertData(ch1, value);
				//어디에 insert할지를 정해야지
			}
			num--;
		}

	}

	void InsertLink(char host, char name)
	{
		GenListNode* newNode = new GenListNode(name);
		GenListNode* sear = search(host); //그 이름을 가진 node
		cout << "주인님 : "<< sear->Nodename << endl;
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
		GenListNode* sear = search(host); //그 이름을 가진 node
		sear->data = d;
		sear->flag = 0;
		//들어오는 데이터들은 1로 받고 그게 까만사각형이면 flag를 0으로 수정
		cout << "나는 : " << sear->Nodename << endl;
		cout << "flag : " << sear->flag << endl;
		cout << "검은 사각형이며 넓이는 " << sear->data << "이지!";
		cout << endl <<endl;
	}

	GenListNode* search(char checkName)
	{
		//싹다뒤져서 찾아내
		GenListNode* dli = NULL;
		GenListNode* ne = NULL;
		while (first != NULL) {
			if (first->Nodename == checkName) { return first; }
			if (first->flag == 0) { return search(first->next, checkName); }
			else { //리스트일때
				if (first->dlink != NULL) { dli = search(first->dlink, checkName); }
				ne = search(first->next, checkName);
				//검색하고있는 노드가 list일때 그것의 next로 가는것과 dlink로 가는것
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
		//first의 Nodename 는 A이다.
		//여기 노드네임을 담아두고 ++ 연산자로 A부터 Number만큼 알파벳을 세아리겠다
		int sumData = 0; // search해서 나온 사각형이 까만사각형이면 data들을 더하겠다
		GenListNode* ptr = NULL;
		int num = Number;
		while (num > 0)
		{
			ptr = search(Check); //Check를 search해서 노드 불러옴
			//search가 Nodename로 검색하는 것 이고,
			//처음에 주어진 사각형 갯수가 그 이름의 개수 이므로, 이 알고리즘을 사용
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
	//입력과 동시에 Generalize List를 완성시키자
	ifs.close();

	Nested.Print();
	//완성된 리스트에서 데이터를 쏙쏙빼서 Print하자

	return 0;
}
