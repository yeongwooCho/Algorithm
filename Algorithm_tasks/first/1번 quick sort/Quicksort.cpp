#include <iostream>
using namespace std;
void printArray(int* arr, int len); //array�� ��ҿ� �����Ͽ� ���� Ȯ��
void swap(int* arr, int n1, int n2); //array���� �ش� index�� ���� swap
void showCurrent(int i, int j, int p); //�ɰ����� �������� ������ patition���� start, end, pivot �� �� Ȯ��
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
	if (start >= end) { return; } //��ĭ���� �ɰ����� �׸��ξ��
	int pivot = (start + end) / 2;  //�߰����� pivot���� ����
	int i = start; //start ��� �񱳷� ����� i
	int j = end; //end ��� �񱳷� ����� j

	//while ���� ����Ǹ� pivot�� �������� 2���� patition���� ���еȴ�.
	while (i + 1 <= j) {
		//showCurrent(i, j, pivot); //�������ؿ� �ڵ�
		//printArray(arr, 10);

		/*����ppt �׸��� ���� pivot�� ��������
		pivot���� ũ���� index�� �۰ų�, pivot���� ������ index�� ū �� ���� �����ϵ���
		�� while ���� �����Ͽ���.
		���⼭ i�� �ִ밪�� j�� �ּҰ��� pivot�� �ȴ�.*/
		while (arr[pivot] >= arr[i] && i < pivot) { i++; }
		while (arr[pivot] <= arr[j] && j > pivot) { j--; }

		/*���� i�� j�� ���� ���Ͽ� ���� while���� ����� �� ���� ��ġ�� �ٲ۴�.
		������ ������ �����Ѵ�.
		index i�� j�� �ش� ���� �����ϴ� �������� i �Ǵ� j �� pivot �� �Ǿ������
		�߽��� �Ǿ���� pivot�� ���� ����Ǵ� ���̴�.
		�׸��� 2���� patition���� ������ pivot�� ���� ���� ���̶� �����ϸ�,
		pivot index�� ���� ���� �ʿ��ϴ�
		�׷��⿡ i�� pivot index�� �ȴٸ� pivot���� ū���� index�� �ش� �ϴ� ����
		swap �ؾ��� ��Ȳ�� �´ٸ� �װ��� pivot index��ġ�� ���ΰ� ���������� �̵��ؾ� �Ѵ�.
		������ ���������� ���ߵ��� �ǹ��Ѵ�.
		�� �ݴ��� ��쵵 �׷� ���̴�.*/
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

