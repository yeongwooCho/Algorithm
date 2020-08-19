/*
#include <iostream>
using namespace std;

int sumChange10(int num) {
	int sum = 0;
	while (num > 10) { sum += num % 10; num /= 10; }
	return sum + num;
}

int sumChange12(int num) {
	int sum = 0;
	while (num > 12) { sum += num % 12; num /= 12; }
	return sum + num;
}

int sumChange16(int num) {
	int sum = 0;
	while (num > 16) { sum += num % 16; num /= 16; }
	return sum + num;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum10;
	for (int i = 1000; i < 10000; i++) {
		sum10 = sumChange10(i);
		if (sum10 == sumChange12(i) && sum10 == sumChange16(i)) {
			cout << i << endl;
		}
	}
}
*/