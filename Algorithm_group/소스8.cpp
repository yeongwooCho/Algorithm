/*
#include <iostream>
#include <set>
using namespace std;

struct Inst { int country, numOfstudent, score; };
struct myOrder {
	bool operator() (const Inst& left, const Inst& right) const { 
		return left.score > right.score;
	}
};
void print(const Inst& in) { cout << in.country << ' ' << in.numOfstudent << endl; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<Inst, myOrder> s; //�������� ��������
	Inst ins;
	int numOfInput; cin >> numOfInput;
	for (int i = 0; i < numOfInput; i++) {
		cin >> ins.country >> ins.numOfstudent >> ins.score;
		s.insert(ins);
	}

	//���� : 1�� �ݸ޴� 2�� ���޴� //3���� ���󸶴� �޴� ������ �����.
	int countryGold = s.begin()->country;
	int countrySilver = (++s.begin())->country;

	if (countryGold != countrySilver || numOfInput == 2) {
		//ó������ ������� �������̴�. numOfInput��ŭ ����ϸ� 2���� ��쵵 �ùٸ���.
		set<Inst, myOrder>::iterator it = s.begin();
		for (int i = 0; i < numOfInput && i < 3; i++) { print(*it); it++; }
	}
	else {//input�� 3�� �̻��̰�, ������ ���� ����� ���� ���޴� ����.
		print(*s.begin()); print(*(++s.begin()));
		for (set<Inst, myOrder>::iterator it = s.begin(); it != s.end(); it++) {
			if (countryGold != it->country) { print(*it); break; }
		}
	}
}
*/