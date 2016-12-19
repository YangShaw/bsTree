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
			que->pop();		//之前一个节点的左右都放满了，可以忽略掉这一个了。
			que->push(newNode);
		}
	}
	size++;		//注意这个和队列里的元素个数没有关系，每插入一个数目就增加一。
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