/*
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	int rest;
	while (b != 0) { rest = a % b; a = b; b = rest; }
	return a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; //test°¹¼ö
	int n; //ÇÏ³ªÀÇ testÀÇ data°¹¼ö
	vector<int> v(100);
	long long resultSum[100]{ 0 };

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) { cin >> v[j]; }
		for (int x = 0; x < n - 1; x++) {
			for (int y = x + 1; y < n; y++) {
				resultSum[i] += static_cast<long long>(gcd(v[x], v[y]));
			}
		}
	}
	for (int i = 0; i < t; i++) { cout << resultSum[i] << '\n'; }
}
*/