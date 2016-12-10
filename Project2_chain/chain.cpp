#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class listNode {
public:
	T element;
	listNode<T> *next;
	listNode(const T &theElement) {
		this->element = theElement;
	}
};

template<class T>
class listChain {
public:
	listChain();
	listChain(T a[],int n);
	bool isEmpty() const;
	int getLength() const;
	void insertFirst(const T &theElement);
	void erase(const T &theElement);
	int findElemnet(const T &theElement)const;
	void output(ostream &out)const;
	void inverseOut()const;
	void addChain(listChain<T> *secondChain);
	void addRegularChain(listChain<T> *secondChain);

private:
	listNode<T> *first;
	int length;		//节点个数
};

template<class T>
listChain<T>::listChain() {
	length = 0;
	first = NULL;
}

//输入数列，创建链表
template<class T>
listChain<T>::listChain(T a[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		insertFirst(a[i]);
	}
	length = n;
}

//链表是否为空
template<class T>
bool listChain<T>::isEmpty() const {
	return length == 0;
}

template<class T>
int listChain<T>::getLength() const {
	return length;
}


//自表首插入元素
template<class T>
void listChain<T>::insertFirst(const T &theElement) {
	listNode<T> *newNode = new listNode<T>(theElement);
	newNode->next = first;
	first = newNode;
	length++;
}

//删除指定元素
template<class T>
void listChain<T>::erase(const T &theElement) {
	if (first->element == theElement) {
		first = first->next;
		length--;
	}
	else {
		listNode<T> *current = first;
		while (current ->next!= NULL&&current->next->element != theElement)
			current = current->next;

		if (current->next == NULL) {
			cout << "cannot find this element!";
			return;
		}
		else {
			current->next = current->next->next;
			length--;
		}

	}
}

//查询表中是否有指定元素
template<class T>
int listChain<T>::findElemnet(const T &theElement)const {
	int index = 1;
	
		listNode<T> *current = first;
		while (current != NULL&&current->element != theElement) {
			current = current->next;
			index++;
		}
		if (current == NULL) {
			cout << "cannot find this element!";
			return 0;
		}
		else {
			return index;
		}
}

//重载操作符
template<class T>
void listChain<T>::output(ostream &out)const {
	for (listNode<T> *current = first; current != NULL; current = current->next) {
		out << current->element << " ";
	}
}

template<class T>
ostream& operator<<(ostream &out, const listChain<T> &x) {
	x.output(out);
	return out;
}

//倒序输出
template<class T>
void listChain<T>::inverseOut()const {
	int n = getLength();
	T *array = new T[n];
	listNode<T> *current = first;
	for (int i = 0; i < n; i++) {
		array[i] = current->element;
		current = current->next;
	}
	for (int i = n - 1; i >= 0; i--)
		cout << array[i] << " ";
	cout << endl;

}

//合并两个链表
template<class T>
void listChain<T>::addChain(listChain<T> *secondChain) {
	int n = getLength();
	int n2 = secondChain->getLength();
	listNode<T> *current = first;
	for (int i = 0; i < n-1; i++) {
		current = current->next;
	}
	current->next = secondChain->first;
	length = length + n2;
}

//合并两个有序链表
template<class T>
void listChain<T>::addRegularChain(listChain<T> *secondChain) {
	listNode<T> *chainA = this->first;
	listNode<T> *chainB = secondChain->first;
	int n1 = this->getLength();
	int n2 = secondChain->getLength();
	T *tempArray = new T[n1+n2];
	int index = 0;

	while (chainA != NULL&&chainB != NULL) {
		if (chainA->element > chainB->element) {
			tempArray[index] = chainB->element;
			chainB = chainB->next;
			index++;
		}
		else {
			tempArray[index] = chainA->element;
			chainA = chainA->next;
			index++;
		}
	}
	while (chainA != NULL) {
		tempArray[index] = chainA->element;
		chainA = chainA->next;
		index++;
	}
	while (chainB != NULL) {
		tempArray[index] = chainB->element;
		chainB = chainB->next;
		index++;
	}

	listChain<T> *tempChain = new listChain<T>(tempArray, n1 + n2);
	cout << *tempChain;
}





