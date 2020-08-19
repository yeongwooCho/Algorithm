/*
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int inputOfNumber; cin >> inputOfNumber;
	int* output = new int[inputOfNumber] {0};
	int h, w, n; //Ãş, Ãş´ç È£½Ç, ¼Õ´Ô¹øÂ°, ÃşÀÌ 0ÀÏ¶§
	for (int i = 0; i < inputOfNumber; i++) {
		cin >> h >> w >> n;
		if (n % h == 0) { output[i] = h * 100 + n / h; }
		else { output[i] = (n % h) * 100 + (n / h + 1); }

	}
	for (int i = 0; i < inputOfNumber; i++) { cout << output[i] << endl; }
	delete[] output;
}
*/