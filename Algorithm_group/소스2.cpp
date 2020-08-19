/*
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;

	stack<int> s;
	vector<int> v;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') { v.push_back(0); }
		else {
			v.push_back(1);
			if (v[i - 1] == 0 && v[i] == 1) { v[i - 1] = 2; v[i] = 3; }
		}
	}

	int numberOfPieces = 0;
	int topIndex = 0;

	for (int i = 0; i < input.size(); i++) {
		if (v[i] == 0) {
			numberOfPieces++;
			s.push(i);
		} //stack에는 index값을 넣는다.
		else if (v[i] == 1) {
			if (!s.empty()) {
				topIndex = s.top();
				s.pop();
			}
			else { numberOfPieces += s.size(); }
		}
		else if (v[i] == 2) {
			numberOfPieces += s.size();
		}
	}

	cout << numberOfPieces;
	return 0;
}
*/