#include <iostream>	
using namespace std;

template<class T>
void swapT(T a, T b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void printArray(T a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ",";
	}
}

template<class T>
void bubbleSort(T array[], int n) {
	int size = n;
	for (int i = size - 1; size > 0; size--) {
		
		for (int j = 0; j < size-1; j++) {
			if (array[j] < array[j + 1])
				swapT(array[j], array[j + 1]);
		}
	}
	printArray(array, n);
}

int main() {
	int n;
	cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++){
		int a;
		cin>>a;
		array[i]=a;
	}

	bubbleSort(array, n);

}