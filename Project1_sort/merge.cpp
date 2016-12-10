#include <stdio.h>
#include <iostream>

template<class T>
void mergeSort(T a[], int n) {	//��������Ǿ������ĸ��������ĸ�����鲢
	T *b = new T[n];	//�½�һ��ͬ����С������������ԭ����֮�以��鲢�����ɾ��
	int part = 1;	//ÿһ�ι鲢�������еĳ���
	while (part < n) {	//ֻҪpart��û��n�Ĵ�С�Ϳ���һֱ�鲢��ȥ
		mergePass(a, b, n, part);	//a��b�Ĺ鲢���鲢����ŵ�b�����Ĺ鲢ʵ������һ������
		part = part * 2;	//ÿ�鲢һ�Σ������г��ȼ���Ϊԭ����һ��
		mergePass(b, a, n, part);	//b��a�Ĺ鲢������bֻ����ʱ�����飬�������ջ���Ҫ�鲢��a��
		part = part * 2;
	}
	delete[] b;
}

template<class T>
void mergePass(T a[], T b[], int n, int part) {	//�����������ж���a��b�Ĺ鲢��Ҳ���ǰ�a�е������������У��������鲢
												//��b�У����������治��2����Ҳ��a��b�Ĺ鲢��
	int i = 0;
	while (i <= n - part * 2) {//˵�����ٻ���һ�飨2�������Թ鲢
		merge(a, b, i, i + part - 1, i + part * 2 - 1);
		i = i + part * 2;
	}

	//��ʣ�²���һ�飨2����֮�󣬿����ǻ�ʣ������һ������û��������һ��
	if (i + part < n) {	//��ʣ������һ���������У�
		merge(a, b, i, i + part - 1, n - 1);
	}
	else {	//����������һ���������У�,��ֱ�Ӹ��ƹ�ȥ
		for (int j = i; j < n; j++)
			b[j] = a[j];
	}
}

template<class T>
void merge(T c[], T d[], int startOfFirst, int endOfFirst, int endOfSecond) {
	int first = startOfFirst;
	int second = endOfFirst + 1;	//�ֱ��ǵ�һ�������к͵ڶ��������е�����
	int result = startOfFirst;

	while ((first <= endOfFirst) && (second <= endOfSecond)) {	//���������ݶζ���û�й鲢��,ֻҪ��һ���鲢��ͽ���
		if (c[first] <= c[second]) {
			d[result] = c[first];
			result++;
			first++;
		}
		else {
			d[result] = c[second];
			result++;
			second++;
		}
	}
	if (first > endOfFirst) {	//�ڶ���û�й鲢��
		for (int i = second; i <= endOfSecond; i++) {
			d[result] = c[i];
			result++;
		}
	}
	else {	//��һ��û�й鲢��
		for (int i = first; i <= endOfFirst; i++) {
			d[result] = c[i];
			result++;
		}
	}
}