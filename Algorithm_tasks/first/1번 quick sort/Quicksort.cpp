#include <iostream>
using namespace std;
void printArray(int* arr, int len); //array의 요소에 접근하여 값을 확인
void swap(int* arr, int n1, int n2); //array에서 해당 index의 값을 swap
void showCurrent(int i, int j, int p); //쪼개지는 과정에서 각각의 patition들의 start, end, pivot 의 값 확인
void myQuicksort(int* arr, int len);
void myQuicksort(int* arr, int start, int end);

int main() {
	//int arr[] = { 6,1,4,3,5,7,9,2,8,0 };
	//int test[] = { 9,8,7,6,5,4,3,4,3,5 };
	int S[] = { 15,22,13,27,12,10,20,25 };

	//myQuicksort(arr, sizeof(arr) / sizeof(int));
	//printArray(arr, sizeof(arr) / sizeof(int));

	//myQuicksort(test, sizeof(test) / sizeof(int));
	//printArray(test, sizeof(test) / sizeof(int));

	myQuicksort(S, sizeof(S) / sizeof(int));
	printArray(S, sizeof(S) / sizeof(int));

	return 0;
}

void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void swap(int* arr, int n1, int n2) {
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = temp;
}

void showCurrent(int i, int j, int p) {
	cout << "i : " << i << endl;
	cout << "j : " << j << endl;
	cout << "pivot : " << p << endl;
}

void myQuicksort(int* arr, int len) {
	myQuicksort(arr, 0, len - 1);
}
void myQuicksort(int* arr, int start, int end) {
	if (start >= end) { return; } //한칸으로 쪼개지면 그만두어라
	int pivot = (start + end) / 2;  //중간값을 pivot으로 잡음
	int i = start; //start 대신 비교로 사용할 i
	int j = end; //end 대신 비교로 사용할 j

	//while 문이 통과되면 pivot을 기준으로 2개의 patition으로 구분된다.
	while (i + 1 <= j) {
		//showCurrent(i, j, pivot); //과제이해용 코드
		//printArray(arr, 10);

		/*과제ppt 그림과 같이 pivot를 기준으로
		pivot보다 크지만 index가 작거나, pivot보다 작지만 index가 큰 두 값을 지정하도록
		두 while 문을 설정하였다.
		여기서 i의 최대값과 j의 최소값은 pivot이 된다.*/
		while (arr[pivot] >= arr[i] && i < pivot) { i++; }
		while (arr[pivot] <= arr[j] && j > pivot) { j--; }

		/*이제 i와 j의 값을 비교하여 위의 while문을 통과한 두 값의 위치를 바꾼다.
		하지만 문제가 존재한다.
		index i와 j의 해당 값을 변경하는 과정에서 i 또는 j 가 pivot 가 되어버리면
		중심이 되어야할 pivot의 값이 변경되는 것이다.
		그리고 2개의 patition으로 나눌때 pivot이 제일 작은 값이라 가정하면,
		pivot index의 변경 또한 필요하다
		그렇기에 i가 pivot index가 된다면 pivot보다 큰값의 index에 해당 하는 값과
		swap 해야할 상황이 온다면 그값을 pivot index위치에 놔두고 오른쪽으로 이동해야 한다.
		기준이 오른쪽으로 가야됨을 의미한다.
		그 반대의 경우도 그럴 것이다.*/
		if (i < j) {
			swap(arr, i, j);
			if (i == pivot) {
				swap(arr, i + 1, j);
				pivot++;
			}
			else if (j == pivot) {
				swap(arr, i, j - 1);
				pivot--;
			}
		}
	}

	myQuicksort(arr, start, pivot - 1);
	myQuicksort(arr, pivot + 1, end);
}

