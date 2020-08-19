/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int K; cin >> K; //랜선의 수
	int N; cin >> N; //필요한 랜선의 수
	vector<long long> v(K);
	for (int i = 0; i < K; i++) { cin >> v[i];}
	sort(v.begin(), v.end());
	
	long long maxlenLine, count;
	long long start = 1, end = v[K - 1];
	while (start <= end) {
		count = 0;
		maxlenLine = (start + end) / 2;
		for (int i = 0; i < K; i++) { count += (v[i] / maxlenLine); }
		
		if (N > count) { end = maxlenLine - 1; }
		else if (N <= count) { start = maxlenLine + 1; }
	}
	cout << end;
}
*/