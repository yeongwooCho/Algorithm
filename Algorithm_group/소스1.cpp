/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	int numberOfInstruction, num;
	string instruction;
	cin >> numberOfInstruction;
	vector<int> v;

	while (numberOfInstruction > 0) {
		cin >> instruction;
		if (instruction == "push") {
			cin >> num;
			q.push(num);
		}
		else if (instruction == "pop") {
			if (q.empty()) { v.push_back(-1); }
			else {
				v.push_back(q.front());
				q.pop();
			}
		}
		else if (instruction == "size") { v.push_back(q.size()); }
		else if (instruction == "empty") { v.push_back(q.empty()); }
		else if (instruction == "front") {
			if (q.empty()) { v.push_back(-1); }
			else { v.push_back(q.front()); }
		}
		else if (instruction == "back") {
			if (q.empty()) { v.push_back(-1); }
			else { v.push_back(q.back()); }
		}
		numberOfInstruction--;
	}
	for (auto& i : v) { cout << i << endl; }
	return 0;
}

*/