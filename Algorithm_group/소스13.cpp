/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T; //test ¼ö
	int N, M;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		vector<int> v1(N), v2(M);
		for (int i = 0; i < N; i++) { cin >> v1[i]; }
		for (int i = 0; i < M; i++) { cin >> v2[i]; }
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v1[i] <= v2[j]) break;
				else count++;
			}
		}
		cout << count << '\n';
	}
}
*/