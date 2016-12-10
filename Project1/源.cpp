#include <iostream>
#include <string>
#include "aa.h"

using std::string;
using std::wstring;
using std::cin;
using std::cout;
using std::endl;



//class Exercise {
//public:
//	Exercise() {}
//	int Compute(int n) {
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			sum += i;
//		}
//		return sum;
//	}
//	void StringPrint(char *arr, unsigned int n) {
//		for (int i = 0; i < n; i++) {
//			cout << arr[i];
//		}
//		cout << endl;
//	}
//};		//д�������

template<class T>		//����Ԫ��
void swapT(T& a, T& b) { //���ò����������ı�ʵ��
	T temp = a;
	a = b;
	b = temp;
}

template<class T>		//��ӡ����
void printArray(T a[], int n) {
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << "," << a[i];
	}
}

template<class T>		//ð������
void bubbleSort(T array[], int n) {
	int size = n;
	for (int i = size; i > 1; i--) {

		for (int j = 0; j < i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapT(array[j], array[j + 1]);
			}

		}
	}
}

template<class T>		//ѡ������
void selectSort(T array[], int n) {
	bool isSort = false;
	for (int i = n; !isSort&&i > 1; i--) {
		int indexOfMax = 0;
		isSort = true;

		//ѡ�����Ԫ�أ�Ȼ������ұߵĽ���
		for(int j = 1; j < i; j++){
			if (array[indexOfMax] <= array[j]) 
				indexOfMax = j;
			else
				isSort = false;
		}
		swapT(array[indexOfMax], array[i - 1]);
	}
}




int main() {
	

	/*int n;
	cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		array[i] = a;
	}

	selectSort(array, n);
	printArray(array, n);*/

	int a[] = { 1,2,3,4,5 };
	func(1);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		cout << a[i];
	cin.ignore();
	cin.ignore();
	return 0;
}