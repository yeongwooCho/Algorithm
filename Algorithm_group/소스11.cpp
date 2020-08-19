/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(const pair<int, string> a, const pair<int, string> b) { return a.first < b.first; }
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int numOfInput; cin >> numOfInput;
	vector<pair<int, string>> v(numOfInput);
	for (int i = 0; i < numOfInput; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	stable_sort(v.begin(), v.end(), compare);
	for (auto& it : v) { cout << it.first << ' ' << it.second << '\n'; }
}
*/