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
		pin = false;  //경로 출력의 제한을 두는 pin
	}

	//Make myHanoi function !!!
	/*
	Hanoi는 제귀적으로 해결 가능하다.
	disk가 n개가 존재한다면, 제일 밑의 디스크를 목적지까지 가져다 놓는다면,
	그위의 모든 디스크들은 n번째 디스크보다 작기때문에 경로의 제한이 없다.
	즉, n-1번째 디스크를 원하는 목적지로 옮기는 것을 수행하는 것이다.
	n != 1 이라면 n-1의 목적지는 출발점과 n의 목적지가 아닌 남은 하나이다.
	n == 1 이 되었다면 이제 재귀적 함수를 하나씩 빠져나오게 된다.
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
		cout << cycleCount << endl;; //경로횟수출력
		pin = true; //pin변경
	}
};



int main(void)
{
	Hanoi hanoi;

	hanoi.playHanoi(1, 2, 3); //cycle이 얼마나 돌았는가를 출력하는 코드

	hanoi.playHanoi(1, 2, 3); //각각의 경로를 출력하는 코드

	return 0;
}

