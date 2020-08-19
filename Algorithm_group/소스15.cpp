/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	set<int> s;
	int tableData;
	for (int i = 0; i < N; i++) {
		cin >> tableData; 
		s.insert(tableData);
	}

	int M; cin >> M;
	int checkData;
	for (int i = 0; i < M; i++) {
		cin >> checkData;
		if (s.find(checkData) != s.end()) { cout << "1\n"; }
		else { cout << "0\n"; }
	}
}
*/
