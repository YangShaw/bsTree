#include <iostream>
#include <stdio.h>
#include "sortedChain.cpp"

template<class K,class E>
class hashChain {
public:
	hashChain(int divisor);
	pair<K, E>* find(const K& theKey)const;
	void insert(const pair<K, E>& thePair);

	sortedChain<K, E> **table;
	int dSize;
	int divisor;
};

template<class K,class E>
hashChain<K, E>::hashChain(int divisor) {
	this->divisor = divisor;
	dSize = 0;
	table = new sortedChain<K, E>*[divisor];
	for (int i = 0; i < divisor; i++) {
		table[i] = new sortedChain<K, E>();		//这里不能套用hashlist中直接初始化为NULL的方式，而要每个初始化一个空链表
												//不然后面无法在table中的各个元素上进行find和insert操作。
	}
}

template<class K,class E>
pair<K, E>* hashChain<K, E>::find(const K& theKey)const {
	pair<K, E>* my = table[theKey%divisor]->find(theKey);
	return my;
}

template<class K,class E>
void hashChain<K, E>::insert(const pair<K, E>& thePair) {
	int b = thePair.first%divisor;
	int oldLength = table[b]->length;
	table[b]->insert(thePair);
	if (table[b]->length > oldLength) {
		dSize++;
	}
}

