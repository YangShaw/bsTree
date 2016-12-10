#include <iostream>
#include <stdio.h>
#include "chain.cpp"
using namespace std;

int main() {
	int n = 0;
	int *array = NULL;
	cout << "输入 n:" << endl;
	cin >> n;
	cout << "输入" << n << "个数字如下：" << endl;
	array = new  int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	listChain<int> *myChain = new listChain<int>(array, n);
	cout << "这个链表为："<<*myChain << endl;

	cout << "输入一个元素插入表头：";
	int a1 = 0;
	cin >> a1;
	myChain->insertFirst(a1);
	cout << "插入头节点后："<<*myChain << endl;

	cout << "输入一个元素，删除之：";
	int a2 = 0;
	cin >> a2;
	myChain->erase(a2);
	cout << "删除链表中的元素后:"<<*myChain << endl;

	cout << "输入一个元素，找到它的位置";
	int a3 = 0;
	cin >> a3;
	cout << "找出链表中元素"<<a3<<"的位置:"<<myChain->findElemnet(a3) << endl;

	cout << "将链表逆序输出：";
	myChain->inverseOut();

	int m = 0;
	int *array2 = NULL;
	cout << endl;
	cout << "输入第二个链表的长度m:" << endl;
	cin >> m;
	cout << "输入" << m << "个数字如下：" << endl;
	array2 = new  int[m];
	for (int i = 0; i < m; i++) {
		cin >> array2[i];
	}
	
	listChain<int> *my2 = new listChain<int>(array2, m);
	cout << "待合并的第二个链表："<<*my2 << endl;

	cout << "合并后的新链表：";
	myChain->addRegularChain(my2);

	
	cin.ignore();
	cin.ignore();
}