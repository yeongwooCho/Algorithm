#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
private:
	int start;
	int end;
	int value;
public:
	Date() : start(0), end(0), value(0) {}
	Date(int s, int e, int v) :start(s), end(e), value(v) {}

	int getStart() const { return start; }
	int getEnd() const { return end; }
	int getValue() const { return value; }

	void setStart(int _start) { start = _start; }
	void setEnd(int _end) { end = _end; }
	void setValue(int _value) { value = _value; }
	
	bool operator<(Date s) const {
		return this->end < s.getEnd();
	}
	
	void print() const {
		cout << start << ' ' << end << ' ' << value;
	}
};

class Money {
private:
	int n;
	long long output;
	vector<Date> v;
public:
	Money();
	~Money() { vector<Date>().swap(v); }
	int getSize() const { return n; }
	long long getOutput() const { return output; }

	void printDate() const {
		cout << n << endl; //size
		for (auto& data : v) { //vector�� ����� ���
			data.print();
			cout << endl;
		}
	}
	void printOutput() const { 
		cout << endl << endl;
		cout << "output" << endl << output << endl;
	}

	int binarySearch(int first, int last, int pivot);
	int binarySearch(int current);
 
	void maxEarn(); //�ִ��� ���ϴ� �Լ�
};

int main() {
	Money money;
	//money.printDate(); //�Էµ� ������� ������ ���

	money.maxEarn();
	money.printOutput();
	return 0;
}



Money::Money() : n(0), output(0) {
	/*
	//file I/O for testfile
	ifstream ifs;
	ifs.open("test_input2.txt");
	if (ifs.is_open()) {
		ifs >> n;
		v.reserve(n);

		Date tmp;
		int tmp1, tmp2, tmp3;
		for (int i = 0; i < n; i++) {
			ifs >> tmp1 >> tmp2 >> tmp3;
			tmp.setStart(tmp1); 
			tmp.setEnd(tmp2); 
			tmp.setValue(tmp3);
			v.push_back(tmp);
		}
	}
	ifs.close();
	*/
	cin >> n;
	v.reserve(n);
	Date tmp;
	int tmp1, tmp2, tmp3;

	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		tmp.setStart(tmp1);
		tmp.setEnd(tmp2);
		tmp.setValue(tmp3);
		v.push_back(tmp);
	}
}

int Money::binarySearch(int first, int last, int pivot) {
	int observe = (first + last) / 2;

	if (first + 1 < last) { //3�� �̻��϶�
		if (v[pivot].getStart() > v[observe].getEnd()) {
			return binarySearch(observe, last, pivot);
		}
		else {
			return binarySearch(first, observe - 1, pivot);
		}
	}
	else { //1�� or 2��
		if (v[pivot].getStart() > v[last].getEnd()) { return last; }
		else if (v[pivot].getStart() > v[first].getEnd()) { return first; }
		else { return -1; }
	}
}

int Money::binarySearch(int current) {
	return binarySearch(0, current - 1, current);
}

void Money::maxEarn() {
	sort(v.begin(), v.end()); //sort algorithm�� Quick sort�̸� O(nlogn)�̴�.

	long long* optimal = new long long[n] {0}; //��������� �ִ밪�� ���� �迭
	optimal[0] = v[0].getValue(); //�ʱ�ȭ
	int indexOfCurrent = 1; //���� index
	int k; //�����Ҵ� index

	while (indexOfCurrent < n) {
		k = binarySearch(indexOfCurrent); //����step�� ������ index�� ����ؿ´�.

		if (k < 0) {
			if (v[indexOfCurrent].getValue() > optimal[indexOfCurrent - 1]) {
				optimal[indexOfCurrent] = v[indexOfCurrent].getValue();
			}
			else {
				optimal[indexOfCurrent] = optimal[indexOfCurrent - 1];
			}
			indexOfCurrent++;
			continue;
		}

		// if(�־������� �� > �ȳ������� ��) 
		if (optimal[k] + v[indexOfCurrent].getValue() > optimal[indexOfCurrent - 1]) {
			optimal[indexOfCurrent] = optimal[k] + v[indexOfCurrent].getValue();
		}
		else {
			optimal[indexOfCurrent] = optimal[indexOfCurrent - 1];
		}
		indexOfCurrent++;
	}
	output = optimal[n - 1];
}
