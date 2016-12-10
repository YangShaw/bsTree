#include <iostream>
#include <stdio.h>
using namespace std;

template<class K,class E>
class hashList
{
public:
	hashList(int divisor);
	int search(const K& theKey)const;
	pair<const K, E>* find(const K& theKey)const;
	void insert(const pair<const K, E>& thePair);


	pair<const K, E>** table;
	int dSize;
	int divisor;
private:

};

template<class K,class E>
hashList<K,E>::hashList(int divisor)
{
	this->divisor = divisor;
	dSize = 0;
	table = new pair<const K, E>*[divisor];
	for (int i = 0; i < divisor; i++) {
		table[i] = NULL;
	}
}

template<class K, class E>
int hashList<K, E>::search(const K& theKey)const {
	int i = theKey %divisor;	//hash函数，得到关键字在除数D下的余数，这是起始桶的值
	int j = i;
	do {
		if (table[j] == NULL || table[j]->first == theKey) {
			return j;	//为空则这个桶可以放这个数对，关键字匹配则这个桶已经放了这个数对
		}
		j = (j + 1) % divisor;		
	} while (j != i);	//当j=i的时候说明又转了一圈回来了，说明没找到合适的桶
	return j;
}

template<class K,class E>
pair<const K, E>* hashList<K, E>::find(const K& theKey)const {
	int b = search(theKey);		//找到关键字对应的位置
	if (table[b] == NULL || table[b]->first != theKey) {
		cout << "cannot find the key!   "  << endl;
		pair<const K, E> *nonpair = new pair<const K, E>(0, 0);
		return nonpair;	//没找到这个数对。由于main方法里是输出find（）->second，所以如果没找到数对的时候返回NULL，
						//那么->second就会成为空，会出现异常，所以要在这里返回一个值为0 0的数对。
	}
	cout << "the value in " << theKey << " is ";
	return table[b];	//返回这个数对
}



template<class K,class E>
void hashList<K, E>::insert(const pair<const K, E>& thePair) {

	int b = search(thePair.first);		//找到关键字对应的位置

	if (table[b] == NULL) {		//只有是空值时才能插入
		table[b] = new pair<const K, E>(thePair);		
		dSize++;
	}
	else {
		if (table[b]->first == thePair.first) {
			table[b]->second = thePair.second;		//更新关键字对应的元素值
		}
		else {
			cout << "full table!" << endl;
			return;
		}
	}
}

