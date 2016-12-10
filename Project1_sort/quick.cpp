#include <stdio.h>
#include <iostream>
#include "mysort.h"

template<class T>
void quickSort(T a[], int l, int r) {
	if (l < r) {	//递归终止的条件
		int left = l, right = r;
		T key = a[left];	//key是标尺值
		while (left<right) {	//左右分别往中间推进，推进到二者值相等后这一次快排结束

			while (left<right&&a[right]>key)	//停止的条件有两个，一种是每个数都符合要求，不需要做任何交换，另一种
												//是有一个数需要交换。
				right--;
			if (left < right)					//判断一下是满足了上面的哪一个条件停止的，为后者则把这个数拿到前面来
				a[left++] = a[right];

			while (left < right&&a[left] < key)	//这个是从左往右的，和上面完全同理
				left++;
			if (left < right)
				a[right--] = a[left];

		}
		a[left] = key;							//左右推进完了，把key值赋到中间这个数
		quickSort(a, l, left - 1);
		quickSort(a, left + 1, r);
	}

}