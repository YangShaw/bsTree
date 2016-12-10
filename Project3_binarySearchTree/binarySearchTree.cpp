#include <iostream>
#include <stdio.h>
using namespace std;

template<class T>
class binaryTreeNode {
public:
	T element;
	binaryTreeNode<T> *left;
	binaryTreeNode<T> *right;

	binaryTreeNode() {1
		left = right = NULL;
	}

	binaryTreeNode(const T &theElement) {
		element = theElement;
		left = right = NULL;
	}

	binaryTreeNode(binaryTreeNode<T> *theLeft, binaryTreeNode<T> *theRight, const T &theElement) {
		left = theLeft;
		right = theRight;
		element = theElement;
	}

};


template<class K,class E>
class bsTree {
public:
	binaryTreeNode<pair<K, E>> *root;
	int size;
	bsTree() {
		root = NULL;
		size = 0;
	}

	int getSize()const {
		return size;
	}
	
	pair<K, E>* find(const K &theKey)const;
	void insert(const pair<K, E> &thePair);
	void ascend();

private:
	void inOrder(binaryTreeNode<pair<K,E>> *t) {
		if (t != NULL) {
			inOrder(t->left);
			cout << "(" << t->element.first << "," << t->element.second << ")";
			inOrder(t->right);
		}
	}
};

template<class K,class E>
pair<K, E>* bsTree<K, E>::find(const K &theKey)const {
	binaryTreeNode<pair<K, E>> *current = root;
	while(current!=NULL)
	{
		if (current->element.first < theKey)
			current = current->right;
		else
		{
			if (current->element.first > theKey)
				current = current->left;
			else
				return &current->element;
		}
	}
	cout << "cannot find it!" << endl;
	pair<K, E> *zero = new pair<K, E>(0, 0);
	return zero;
}

template<class K,class E>
void bsTree<K, E>::insert(const pair<K, E> &thePair) {
	binaryTreeNode<pair<K, E>> *current = root, *currentLast = NULL;
	while (current != NULL) {
		currentLast = current;
		if (current->element.first < thePair.first)
			current = current->right;
		else
		{
			if (current->element.first > thePair.first)
				current = current->left;
			else {
				current->element.second = thePair.second;		//�ҵ��ؼ�����ͬ�Ľڵ�ֱ�Ӹ���
				return;		
			}
		}
	}

	binaryTreeNode<pair<K, E>> *newNode = new binaryTreeNode<pair<K, E>>(thePair);
	if (root != NULL)
		if (currentLast->element.first < thePair.first)
			currentLast->right = newNode;
		else
			currentLast->left = newNode;
	else
		root = newNode;

	size++;
}

template<class K,class E>
void bsTree<K, E>::ascend() {
	inOrder(root);
}

int main() {
	bsTree<int, int> *bs = new bsTree<int,int>();
	cout << "����Ԫ�ظ���:" << endl;
	int n;
	cin >> n;
	cout << "��������" << n << "��Ԫ�صĹؼ��ֺ�ֵ:" << endl;
	pair<int,int> *arr = new pair<int,int>[n];
	for (int i = 0; i < n; i++) {
		int key,value;
		cin >> key;
		cin >> value;
		arr[i] = pair<int, int>(key, value);
		bs->insert(arr[i]);
	}
	int command = 1;
	while (command) {
		cout << "����1������		2�����ؼ�������		0���˳�" << endl;
		cin >> command;
		switch (command)
		{
		case 1: {
			cout << "����Ҫ�����Ĺؼ���" << endl;
			int key;
			cin >> key;
			pair<int, int> *temp = bs->find(key);
			cout << "Ŀ��ڵ�Ϊ��";
			cout << "(" << temp->first << "," << temp->second << ")" << endl;
			break;
		}
		case 2: {
			bs->ascend();
			cout << endl;
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "��������ȷ�����" << endl;
			break;
		}
		}
	}
	system("Pause");
}
