#include <stdio.h>
#include <iostream>

template<class T>
void mergeSort(T a[], int n) {	//这个方法是决定从哪个数组向哪个数组归并
	T *b = new T[n];	//新建一个同样大小的数组用来和原数组之间互相归并，最后删掉
	int part = 1;	//每一次归并的子序列的长度
	while (part < n) {	//只要part还没到n的大小就可以一直归并下去
		mergePass(a, b, n, part);	//a到b的归并，归并结果放到b里，具体的归并实现在另一个函数
		part = part * 2;	//每归并一次，子序列长度即变为原来的一倍
		mergePass(b, a, n, part);	//b到a的归并，由于b只是临时的数组，所以最终还是要归并回a中
		part = part * 2;
	}
	delete[] b;
}

template<class T>
void mergePass(T a[], T b[], int n, int part) {	//这整个方法中都是a到b的归并，也就是把a中的若干组子序列（两两）归并
												//到b中，所以在下面不足2个后也是a到b的归并。
	int i = 0;
	while (i <= n - part * 2) {//说明至少还有一组（2个）可以归并
		merge(a, b, i, i + part - 1, i + part * 2 - 1);
		i = i + part * 2;
	}

	//在剩下不足一组（2个）之后，看看是还剩完整的一个还是没有完整的一个
	if (i + part < n) {	//还剩完整的一个（子序列）
		merge(a, b, i, i + part - 1, n - 1);
	}
	else {	//不足完整的一个（子序列）,则直接复制过去
		for (int j = i; j < n; j++)
			b[j] = a[j];
	}
}

template<class T>
void merge(T c[], T d[], int startOfFirst, int endOfFirst, int endOfSecond) {
	int first = startOfFirst;
	int second = endOfFirst + 1;	//分别是第一个子序列和第二个子序列的索引
	int result = startOfFirst;

	while ((first <= endOfFirst) && (second <= endOfSecond)) {	//两个的数据段都还没有归并完,只要有一个归并完就结束
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
	if (first > endOfFirst) {	//第二个没有归并完
		for (int i = second; i <= endOfSecond; i++) {
			d[result] = c[i];
			result++;
		}
	}
	else {	//第一个没有归并完
		for (int i = first; i <= endOfFirst; i++) {
			d[result] = c[i];
			result++;
		}
	}
}