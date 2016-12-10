#include <stdio.h>
#include <iostream>
#include "chain.cpp"
#include "merge.cpp"
#include "quick.cpp"
#include "mysort.h"
using namespace std;



template<class T>
void printArray(T a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

//template <class T>
//class mySort<T> {
//public:
//	void selectionSort(T a[], int n);
//};

template<class T>
void selectionSort(T a[], int n) {
	for (int i = n-1; i >= 0; i--) {
		int indexOfMax = 0;
		for (int j = 0; j <= i; j++) {
			if (a[j] > a[indexOfMax])
				indexOfMax = j;
		}
		mySwap<T>(a[i], a[indexOfMax]);
		cout << "Step" << n - i << ":";
		printArray(a, n);
	}
	printArray(a, n);
}

template<class T>
void bubblSort(T a[], int n) {
	for (int i = n - 1; i >= 0; i--)  {
		for (int j = 0; j <= i-1; j++) {
			if (a[j + 1] < a[j]) {
				mySwap(a[j + 1], a[j]);
				cout << "Step" << n - i << ":";
				printArray(a, n);
			}
		}
		
	}
	printArray(a, n);
}

template<class T>
void insertSort(T a[], int n) {
	for (int i = 1; i < n ; i++) {
		T t = a[i];
		int j;
		for (j = i - 1; j >= 0&&t<a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
		cout << "Step" << n - i << ":";
		printArray(a, n);
	}
	printArray(a, n);
}


void radixSort(chain<int> &theChain, int range,int n) {
	int count = 0;
	chain<int> *bin = NULL;
	while (count<n) {
		bin = new chain<int>[range];
		int numberOfElements = theChain.size();
		for (int i = 0; i < numberOfElements; i++) {
			int number = theChain.getFirst();
			int temNumber = number;
			for (int j = 0; j < count; j++)
				temNumber = temNumber / range;
			bin[temNumber % range].insert(0, number);
			theChain.deleteE(0);
		}
		for (int k = range - 1; k >= 0; k--) {
			while (!bin[k].empty()) {
				int x = bin[k].getFirst();
				bin[k].deleteE(0);
				theChain.insert(0, x);
			}
		}
		count++;
		cout << "Step" << count << ":";
		theChain.printChain();
		cout << endl;
	}
	theChain.printChain();
	delete[] bin;
}




int main() {
	int a[] = { 2,25,26,65,77,44,15,3 };
	selectionSort(a, 8);
	cout << endl;

	int b[] = { 2,25,26,65,77,44,15,3 };
	bubblSort(b, 8);
	cout << endl;

	int c[] = { 2,25,77,65,26,44,15,3 };
	insertSort(c, 8);
	cout << endl;

	chain<int> *theChain = new chain<int>();
	theChain->insert(0, 30);
	theChain->insert(0, 153);
	theChain->insert(0, 442);
	theChain->insert(0, 771);
	theChain->insert(0, 65);
	theChain->insert(0, 26);
	theChain->insert(0, 211);
	theChain->insert(0, 25);
	radixSort(*theChain, 10, 3);
	cout << endl;
	cout << endl;

	int e[] = { 2,25,77,65,26,44,15,3,36,6666,21,2 };
	mergeSort(e, 12);
	cout << "mergeSort" << ":";
	printArray(e, 12);
	cout << endl;

	int f[] = { 2,25,77,65,26,44,15,3,36,6666,21,2 };
	quickSort(f, 0,11);
	cout << "quickSort" << ":";
	printArray(f, 12);

	cin.ignore();

}