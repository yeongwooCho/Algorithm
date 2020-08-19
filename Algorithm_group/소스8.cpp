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

	set<Inst, myOrder> s; //점수기준 내림차순
	Inst ins;
	int numOfInput; cin >> numOfInput;
	for (int i = 0; i < numOfInput; i++) {
		cin >> ins.country >> ins.numOfstudent >> ins.score;
		s.insert(ins);
	}

	//점수 : 1등 금메달 2등 은메달 //3등은 나라마다 메달 제한이 생긴다.
	int countryGold = s.begin()->country;
	int countrySilver = (++s.begin())->country;

	if (countryGold != countrySilver || numOfInput == 2) {
		//처음부터 순서대로 금은동이다. numOfInput만큼 출력하면 2개인 경우도 올바르다.
		set<Inst, myOrder>::iterator it = s.begin();
		for (int i = 0; i < numOfInput && i < 3; i++) { print(*it); it++; }
	}
	else {//input이 3개 이상이고, 금은을 받은 나라는 동을 못받는 경우다.
		print(*s.begin()); print(*(++s.begin()));
		for (set<Inst, myOrder>::iterator it = s.begin(); it != s.end(); it++) {
			if (countryGold != it->country) { print(*it); break; }
		}
	}
}
*/