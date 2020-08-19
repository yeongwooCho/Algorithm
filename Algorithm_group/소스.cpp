/*

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int numberOfInstruction, num;
	string instruction;
	cin >> numberOfInstruction;
	
	vector<int> v;

	while (numberOfInstruction > 0) {
		cin >> instruction;

		if (instruction == "push") {
			cin >> num;
			s.push(num);
		}
		else if (instruction == "pop") {
			if (s.empty()) { v.push_back(-1); }
			else {
				v.push_back(s.top());
				s.pop();
			}
		}
		else if (instruction == "size") { v.push_back(s.size()); }
		else if (instruction == "empty") { v.push_back(s.empty()); }
		else if (instruction == "top") {
			if (s.empty()) { v.push_back(-1); }
			else { v.push_back(s.top()); }
		}
		numberOfInstruction--;
	}
	for (auto& i : v) {
		cout << i << endl;
	}

	return 0;
}
*/