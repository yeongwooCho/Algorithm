/*
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int inputOfNumber; cin >> inputOfNumber;
	vector<pair<int, int>> couple;
	int w, h; //몸무게, 키
	int* output = new int[inputOfNumber] {0}; 
	//데이터 받기
	for (int i = 0; i < inputOfNumber; i++) {
		cin >> w >> h; 
		couple.push_back(make_pair(w, h));
	}
	//순위메기기
	for (int i = 0; i < inputOfNumber; i++) {
		for (int j = 0; j < inputOfNumber; j++) {
			if (couple[i].first > couple[j].first && couple[i].second > couple[j].second) 
				output[j]++;
		}
	}
	//출력 //순위는 1등부터
	for (int i = 0; i < inputOfNumber; i++) { cout << output[i] + 1 << ' '; }
	delete[] output;
}
*/