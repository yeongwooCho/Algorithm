/*
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, sum, count; 
	cin >> N;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		sum = 0; count = 0;
		for (int k = 0; k < input.size(); k++) {
			if (input[k] == 'O') { ++count; sum += count; }
			else { count = 0; }
		}
		cout << sum << endl;
	}
}
*/