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
//};		//写着玩的类

template<class T>		//交换元素
void swapT(T& a, T& b) { //引用参数，做到改变实体
	T temp = a;
	a = b;
	b = temp;
}

template<class T>		//打印数组
void printArray(T a[], int n) {
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << "," << a[i];
	}
}

template<class T>		//冒泡排序
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

template<class T>		//选择排序
void selectSort(T array[], int n) {
	bool isSort = false;
	for (int i = n; !isSort&&i > 1; i--) {
		int indexOfMax = 0;
		isSort = true;

		//选择最大元素，然后和最右边的交换
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