#include <iostream>
#include <stdio.h>
#include "chain.cpp"
using namespace std;

int main() {
	int n = 0;
	int *array = NULL;
	cout << "���� n:" << endl;
	cin >> n;
	cout << "����" << n << "���������£�" << endl;
	array = new  int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	listChain<int> *myChain = new listChain<int>(array, n);
	cout << "�������Ϊ��"<<*myChain << endl;

	cout << "����һ��Ԫ�ز����ͷ��";
	int a1 = 0;
	cin >> a1;
	myChain->insertFirst(a1);
	cout << "����ͷ�ڵ��"<<*myChain << endl;

	cout << "����һ��Ԫ�أ�ɾ��֮��";
	int a2 = 0;
	cin >> a2;
	myChain->erase(a2);
	cout << "ɾ�������е�Ԫ�غ�:"<<*myChain << endl;

	cout << "����һ��Ԫ�أ��ҵ�����λ��";
	int a3 = 0;
	cin >> a3;
	cout << "�ҳ�������Ԫ��"<<a3<<"��λ��:"<<myChain->findElemnet(a3) << endl;

	cout << "���������������";
	myChain->inverseOut();

	int m = 0;
	int *array2 = NULL;
	cout << endl;
	cout << "����ڶ�������ĳ���m:" << endl;
	cin >> m;
	cout << "����" << m << "���������£�" << endl;
	array2 = new  int[m];
	for (int i = 0; i < m; i++) {
		cin >> array2[i];
	}
	
	listChain<int> *my2 = new listChain<int>(array2, m);
	cout << "���ϲ��ĵڶ�������"<<*my2 << endl;

	cout << "�ϲ����������";
	myChain->addRegularChain(my2);

	
	cin.ignore();
	cin.ignore();
}