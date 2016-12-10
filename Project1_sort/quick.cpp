#include <stdio.h>
#include <iostream>
#include "mysort.h"

template<class T>
void quickSort(T a[], int l, int r) {
	if (l < r) {	//�ݹ���ֹ������
		int left = l, right = r;
		T key = a[left];	//key�Ǳ��ֵ
		while (left<right) {	//���ҷֱ����м��ƽ����ƽ�������ֵ��Ⱥ���һ�ο��Ž���

			while (left<right&&a[right]>key)	//ֹͣ��������������һ����ÿ����������Ҫ�󣬲���Ҫ���κν�������һ��
												//����һ������Ҫ������
				right--;
			if (left < right)					//�ж�һ�����������������һ������ֹͣ�ģ�Ϊ�������������õ�ǰ����
				a[left++] = a[right];

			while (left < right&&a[left] < key)	//����Ǵ������ҵģ���������ȫͬ��
				left++;
			if (left < right)
				a[right--] = a[left];

		}
		a[left] = key;							//�����ƽ����ˣ���keyֵ�����м������
		quickSort(a, l, left - 1);
		quickSort(a, left + 1, r);
	}

}