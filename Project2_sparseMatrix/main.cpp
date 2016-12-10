#include <iostream>
#include <stdio.h>
#include "sparseMatrix.cpp"

int main() {
	cout << "请输入稀疏矩阵的行列数和可能的最大元素数" << endl;
	int m, n, maxsize;
	cin >> m >> n >> maxsize;
	sparseMatrix<int> *sm = new sparseMatrix<int>(m, n, maxsize);
	int a, b, c;
	a = 1;
	while (a) {
		cout << "请向矩阵中按行，列，元素顺序插入元素。输入（0,0,0）为结束" << endl;
		cin >> a >> b >> c;
		if (a)
			sm->set(a, b, c);
	}
	cout << *sm;

	int count=9;
	while (count) {
		cout << "请输入 1、转置	2、求和	   0、退出" << endl;
		cin >> count;
		switch (count)
		{
		case 1: {
			sparseMatrix<int> *sm2 = new sparseMatrix<int>(sm->col, sm->row, sm->maxSize);
			sm->transpone(sm2);
			cout << *sm2;
			break;
		}
		case 2: {
			cout << "请输入第二个稀疏矩阵的行列数和可能的最大元素数" << endl;
			int m, n, maxsize;
			cin >> m >> n >> maxsize;
			sparseMatrix<int> *sm3 = new sparseMatrix<int>(m, n, maxsize);
			int a, b, c;
			a = 1;
			while (a) {
				cout << "请向矩阵中按行，列，元素顺序插入元素。输入（0,0,0）为结束" << endl;
				cin >> a >> b >> c;
				if (a)
					sm3->set(a, b, c);
			}
			sparseMatrix<int> *sm4 = new sparseMatrix<int>(m, n, maxsize);
			sm->add(*sm3, *sm4);
			cout << *sm4;

		}
		case 0:
			break;
		}
	}
	

	/*sparseMatrix<int> *sm = new sparseMatrix<int>(4, 4, 8);
	sm->set(1, 1, 1);
	sm->set(2, 2, 2);
	sm->set(2, 4, 3);
	sm->set(2, 3, 4);
	sm->set(3, 2, 5);
	sm->set(4, 4, 6);
	cout << *sm;
	cout << endl;
	sparseMatrix<int> *sm2 = new sparseMatrix<int>(sm->col,sm->row,sm->maxSize);
	sm->transpone(sm2);
	cout << *sm2;

	sparseMatrix<int> *sm3 = new sparseMatrix<int>(4,4,16);
	sm->add(*sm2, *sm3);
	cout << *sm3;*/

	cin.ignore();
	cin.ignore();
}