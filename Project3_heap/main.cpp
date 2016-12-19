#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class heapNode {
public:
	int key;
	heapNode *left;
	heapNode *right;
	heapNode(int theKey, heapNode *l, heapNode *r) {
		key = theKey;
		left = l;
		right = r;
	}
};

class myheap {
public:
	heapNode *root;
	queue<heapNode*> *que;
	int size;

	myheap(heapNode *theRoot);
	void insert(heapNode *newNode);
	void insert(int key);
	void print(heapNode *root) const;
};

myheap::myheap(heapNode *theRoot) {
	root = theRoot;
	que = new queue<heapNode*>;
	size = 1;
	que->push(root);
}

void myheap::insert(int key) {
	heapNode *newNode = new heapNode(key, NULL, NULL);
	if (que->empty()) {
		que->push(newNode);
	}
	else {
		heapNode *temp = que->front();
		if (temp->left == NULL) {
			temp->left = newNode;
			que->push(newNode);
		}
		else {
			temp->right = newNode;
			que->pop();		
			que->push(newNode);
		}
	}
	size++;		
}

void myheap::insert(heapNode *newNode) {
	if (que->empty()) {
		que->push(newNode);
	}
	else {
		heapNode *temp = que->front();
		if (temp->left == NULL) {
			temp->left = newNode;
			que->push(newNode);
		}
		else {
			temp->right = newNode;
			que->pop();		//֮ǰһ���ڵ�����Ҷ������ˣ����Ժ��Ե���һ���ˡ�
			que->push(newNode);
		}
	}
	size++;		//ע������Ͷ������Ԫ�ظ���û�й�ϵ��ÿ����һ����Ŀ������һ��
}


void visit(heapNode *t) {
	cout << t->key << " ";
}

void myheap::print(heapNode *t)const {
	if (t != NULL) {
		visit(t);
		print(t->left);
		print(t->right);
	}
}




int main() {
	heapNode *myroot = new heapNode(1, NULL, NULL);
	myheap *theheap = new myheap(myroot);
	theheap->insert(2);
	theheap->insert(3);
	theheap->insert(4);
	theheap->insert(5);
	theheap->insert(6);
	theheap->insert(7);
	theheap->print(myroot);
	system("Pause");
}