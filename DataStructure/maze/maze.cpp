#include <iostream>
#include <fstream>
using namespace std;


class Node
{
private:
	friend class Stack;
	int row; //row
	int col; //column

	Node* next;
public:
	Node() { row = 0; col = 0; next = NULL; }
	Node(int r, int c) : row(r), col(c) { next = NULL; }

};
class Stack
{
private:
	Node* top;
	int size;
	int i;
	int* Matrix;
	int length;
	int* CheckPath;
public:
	Stack()
	{
		ifstream ifs;
		ifs.open("maze.inp");
		ifs >> size;
		Matrix = new int[size * size];
		CheckPath = new int[size * size];
		for(int i = 0; i < size*size; i++)
        {
            Matrix[i] = 0;
            CheckPath[i] = 0;
        }

		CheckPath[0] = 1;
		for (int i = 0; i < size*size; i++) {
			int n;
			char c;
			ifs >> n;
			Matrix[i] = n;
			if ((i%size) != (size-1)) { ifs >> c; }
		}

		top = new Node();
		length = 1;

		for(int i = 0; i <size*size; i++)
        {
            cout << Matrix[i] << ' ';
        }
	}



	void push(Node* n)
	{
		if (isEmpty()) { return; }
		n->next = top;
		top = n;

	}

	bool isEmpty()
	{
		if (top == NULL) { return true; }
		else { return false; }
	}

	void pop() //요거함 의심해봐
	{
		Node* newNode = top;
		top = top->next;
		CheckPath[top->row,top->col] = 0;
		delete newNode;

		length--;
	}

	bool StackCheck()
	{
		for (Node* ptr = top; ptr != NULL; ptr = ptr->next)
		{

		}
	}


	void path()
	{
		while (true)
		{
        CheckPath[0] = 1;
	    //cout << "------" << endl;
			int i = top->row;
			int j = top->col;
			//cout << "i = " << i <<endl;
			//cout << "j = " << j << endl;
			//cout << "length :"  << length << endl;
			if ((i == size - 1) && (j == size - 1)) { break; }

			while (!((i == size - 1) && (j == size - 1)))
                {
				if ((Matrix[(size * i) + j] & 8) == 8)
				{
					if ((CheckPath[size * (i + 1) + (j)]) == 0)
					{
						Node* newNode = new Node(i + 1, j);
						push(newNode);
						CheckPath[size * (i + 1) + (j)] += 1;
						length++;
						break;

					}
				}

				if ((Matrix[(size * i) + j] & 1) == 1)
				{
					if ((CheckPath[size * (i)+(j + 1)]) == 0)
					{
						Node* newNode = new Node(i, j + 1);
						push(newNode);
						CheckPath[size * (i)+(j + 1)] += 1;
						length++;
						break;
					}
				}
				if ((Matrix[(size * i) + j] & 2) == 2)
				{
					if ((CheckPath[size * (i - 1) + (j)]) == 0)
					{
						Node* newNode = new Node(i - 1, j);
						push(newNode);
						CheckPath[size * (i - 1) + (j)] += 1;
						length++;
						break;
					}
				}

				if ((Matrix[(size * i) + j] & 4) == 4)
				{
					if ((CheckPath[size * (i)+(j - 1)]) == 0)
					{
						Node* newNode = new Node(i, j - 1);
						push(newNode);
						CheckPath[size * (i)+(j - 1)] += 1;
						length++;
						break;
					}
				}
				if (isEmpty()) { return; }
				pop();
				break;
			}
		}
	}
	void Print()
	{

		int arrRow[length] = {};
		int arrCol[length] = {};
		int i = 0;
		for (Node* ptr = top; ptr != NULL; ptr = ptr->next)
		{
			arrRow[i] = ptr->row;
			arrCol[i] = ptr->col;
			i++;
		}
		/*
		cout << length << endl;
		for(int i = 0; i < length; i++)
        {
            cout << arrRow[length-1-i] << ", " << arrCol[length-1-i];
            if(i != length-1) {cout << endl;}
        }
*/
        ofstream ofs;
        ofs.open("maze.out");
        ofs << length << endl;
        for(int i = 0; i < length; i++)
        {
            ofs << arrRow[length-1-i] << ", " << arrCol[length-1-i];
            if(i != length-1) {ofs << endl;}
        }
	}
	~Stack()
	{
		delete[] Matrix;
	}
};

int main()
{
	Stack pathStack;
	pathStack.path();

	cout << "BBB" <<endl;
	pathStack.Print();

	return 0;
}
