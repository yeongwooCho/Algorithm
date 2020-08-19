/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N; //나무의 수
	int M; cin >> M; //필요한 나무의 길이
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) { cin >> v[i]; }
	sort(v.begin(), v.end(), greater<int>());
	int maxTree = v[0]; 
	int sum = 0;

	while (maxTree >= 0) {
		sum = 0;
		for (int i = 0; (v[i] - maxTree) > 0 && i < N; i++) {
			sum += (v[i] - maxTree);
		}
		if (M <= sum) { cout << maxTree << '\n'; break; } //check
		
		maxTree -= (M - sum) / N;
		if ((M - sum) / N == 0 && (M - sum) % N > 0) maxTree--;
	}
}
*/