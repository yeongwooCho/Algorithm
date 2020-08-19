/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) { q.push(i); }

	cout << '<';
	while (!q.empty()) {
		//k이면 k-1번째 까지는 앞에서 빼서 뒤로 넣는다. 
		for (int i = 1; i < k; i++) { q.push(q.front()); q.pop(); }
		cout << q.front(); q.pop();
		if (!q.empty()) cout << ", ";
	}
	cout << '>';
}
*/