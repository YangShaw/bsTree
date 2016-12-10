#include <iostream>
#include <stdio.h>
using namespace std;

template<class K,class E>
class pairNode {
public:

	pairNode(pair<K, E> theElement, pairNode<K, E>* theNext) {
		element = theElement;
		next = theNext;
	}

	pair<K, E> element;
	pairNode<K, E> *next;
};

template<class K,class E>
class sortedChain {
public:
	sortedChain();
	pair<K, E>* find(const K& theKey)const;
	void insert(const pair<K, E> &thePair);
	void output(ostream &out)const;

	pairNode<K, E>* first;
	int length;
};

template<class K,class E>
sortedChain<K, E>::sortedChain() {
	first = NULL;
	length = 0;
}

template<class K,class E>
pair<K, E>* sortedChain<K, E>::find(const K& theKey)const {
	pairNode<K, E> *current = first;
	while (current != NULL&&current->element.first != theKey)
		current = current->next;

	if (current != NULL&&current->element.first == theKey) {
		return &current->element;
	}
	pair<K, E> *m11 = new pair<K, E>(0, 0);
	cout << "cannot find the key!" << endl;
	return m11;
}

template<class K,class E>
void sortedChain<K, E>::insert(const pair<K, E> &thePair) {
	pairNode<K, E> *current = first;
	pairNode<K, E> *tail = NULL;
	
	while (current != NULL&&current->element.first < thePair.first) {
		tail = current;
		current = current->next;
	}

	if (current != NULL&&current->element.first == thePair.first) {
		current->element = thePair;	//若已存在这个数对，则覆盖原来的这个数对,length不用自增
		return;
	}
	//否则就是current的first已经大于thepair的first了，应该在current前面插入一个新节点，所以用tail来记录current前面的节点

	pairNode<K, E> *newNode = new pairNode<K, E>(thePair, current);

	if (tail == NULL)
		first = newNode;
	else
		tail->next = newNode;

	length++;
	return;
}

template<class K,class E>
void sortedChain<K,E>::output(ostream &out)const {
	for (pairNode<K,E> *current = first; current != NULL; current = current->next) {
		out << current->element.first << " " << current->element.second << " " << endl;
	}
}

template<class K,class E>
ostream& operator<<(ostream &out, const sortedChain<K,E> &x) {
	x.output(out);
	return out;
}