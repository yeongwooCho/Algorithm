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
	int w, h; //������, Ű
	int* output = new int[inputOfNumber] {0}; 
	//������ �ޱ�
	for (int i = 0; i < inputOfNumber; i++) {
		cin >> w >> h; 
		couple.push_back(make_pair(w, h));
	}
	//�����ޱ��
	for (int i = 0; i < inputOfNumber; i++) {
		for (int j = 0; j < inputOfNumber; j++) {
			if (couple[i].first > couple[j].first && couple[i].second > couple[j].second) 
				output[j]++;
		}
	}
	//��� //������ 1�����
	for (int i = 0; i < inputOfNumber; i++) { cout << output[i] + 1 << ' '; }
	delete[] output;
}
*/