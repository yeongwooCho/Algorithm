#include <iostream>

using namespace std;

class Hanoi {
private :
	int numberOfDisks;
	int cycleCount;
	bool pin;
public :
	Hanoi() {
		cout << "Input a number of disks : ";
		cin >> numberOfDisks;
		cycleCount = 0;
		pin = false;  //��� ����� ������ �δ� pin
	}

	//Make myHanoi function !!!
	/*
	Hanoi�� ���������� �ذ� �����ϴ�.
	disk�� n���� �����Ѵٸ�, ���� ���� ��ũ�� ���������� ������ ���´ٸ�,
	������ ��� ��ũ���� n��° ��ũ���� �۱⶧���� ����� ������ ����.
	��, n-1��° ��ũ�� ���ϴ� �������� �ű�� ���� �����ϴ� ���̴�.
	n != 1 �̶�� n-1�� �������� ������� n�� �������� �ƴ� ���� �ϳ��̴�.
	n == 1 �� �Ǿ��ٸ� ���� ����� �Լ��� �ϳ��� ���������� �ȴ�.
	*/
	void myHanoi(int n, int from, int by, int to) {
		cycleCount++;
		if (n == 1) {
			if (pin == true) { printPath(from, to); }
		}

		else {
			myHanoi(n - 1, from, to, by);
			if (pin == true) { printPath(from, to); }
			myHanoi(n - 1, by, from, to);
		}
	}

	void printPath(int from, int to) {
		cout << from << " " << to << endl;
	}

	void playHanoi(int from, int by, int to) {
		myHanoi(numberOfDisks, from, by, to);
		if (pin == true) { return; }
		cout << cycleCount << endl;; //���Ƚ�����
		pin = true; //pin����
	}
};



int main(void)
{
	Hanoi hanoi;

	hanoi.playHanoi(1, 2, 3); //cycle�� �󸶳� ���Ҵ°��� ����ϴ� �ڵ�

	hanoi.playHanoi(1, 2, 3); //������ ��θ� ����ϴ� �ڵ�

	return 0;
}

