/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int bangIndex;
	string inputString, bangString;
	cin >> inputString >> bangString;

	stack<int> s;
	int step = 0;
	for (int i = 0; i < inputString.size(); i++) {
		if (inputString[i] == bangString[step]) {
			s.push(i);
			step++;
		}

		else if (inputString[i] == bangString[0]) {
			s.push(i);
			step = 1; //처음 문자가 들어 갔으니까
		}

		else { //이상한 문자 나오면 stack, step을 reset
			while (!s.empty()) s.pop(); step = 0;
		}

		//폭탄 찾으면 터뜨리기
		if (inputString[i] == bangString[bangString.size() - 1]
			&& step == bangString.size() && s.size() >= step && !s.empty()) {
			for (int k = 0; k < bangString.size(); k++) {
				bangIndex = s.top();
				s.pop();
				inputString[bangIndex] = '#';
			}

			//현재의 step을 찾아준다
			if (s.empty()) step = 0;
			else {
				for (int k = 0; k < bangString.size(); k++) {
					if (inputString[s.top()] == bangString[k]) {
						step = k + 1;
						break;
					}
				}
			}
		}
	}

	string output;
	for (int i = 0; i < inputString.size(); i++) {
		if (inputString[i] != '#')
			output.push_back(inputString[i]);
	}
	if (output.size() == 0) { cout << "FRULA"; }
	else cout << output;

	return 0;
}
*/