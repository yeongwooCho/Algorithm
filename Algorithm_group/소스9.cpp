/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int numOfInput; cin >> numOfInput;
	vector<string> v;
	string str("");
	for (int i = 0; i < numOfInput; i++) {
		cin >> str; v.push_back(str);
	}

	bool check = true;
	for (int i = 0; i < str.length(); i++) {
		check = true;
		for (int j = 0; j < numOfInput-1; j++) {
			if (v[j][i] != v[j + 1][i]) { check = false; break; }
		}
		if (check == false) cout << '?';
		else cout << v[0][i];
	}
}
*/