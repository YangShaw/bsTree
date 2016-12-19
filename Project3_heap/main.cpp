#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class heapNode {
public:
	int key;
	heapNode *left;
	heapNode *right;
	heapNode *father;
	heapNode(int theKey, heapNode *l, heapNode *r) {
		key = theKey;
		left = l;
		right = r;
		father = NULL;
	}
};

class myheap {
public:
	heapNode *root;
	heapNode *theroot = new heapNode(0, NULL, NULL);
	queue<heapNode*> *que;
	int size;

	myheap(heapNode *theRoot);
	//void insert(heapNode *newNode);
	void insert(int key);
	void print(heapNode *root) const;
};

myheap::myheap(heapNode *theRoot) {
	root = theRoot;
	que = new queue<heapNode*>;
	size = 1;
	que->push(root);
	root->father = theroot;		//��־�ҵ�ͷ��
}

void myheap::insert(int key) {
	heapNode *newNode = new heapNode(key, NULL, NULL);
	if (que->empty()) {
		que->push(newNode);
		newNode->father = theroot;
		
	}
	else {
		heapNode *temp = que->front();
		if (temp->left == NULL) {
			temp->left = newNode;
			newNode->father = temp;
			int childkey = newNode->key;
			int fatherkey = newNode->father->key;
			if (childkey>fatherkey) {
				newNode->key = fatherkey;
				newNode->father->key = childkey;
				que->push(newNode);
				//ֻ����������һ������ӵ����󣬺���������������ֻ�ڵ����ڶ�������while������Щ��������޹���
				
				heapNode *currentnode = newNode->father;	//������ԭ�ڵ��������Ϊ��ı丸�ӹ�ϵ��ֻ�ܽ���ÿ���ڵ��key�������ܽ����ڵ㱾��
				while (currentnode->father != theroot&&currentnode->key > currentnode->father->key) {
					int currentkey = currentnode->key;
					currentnode->key = currentnode->father->key;
					currentnode->father->key = currentkey;
					currentnode = currentnode->father;
				}
			
			}	
			else {
				que->push(newNode);		//��С���ʾͲ��ø� ֱ�Ӳ��롣����һ�㶼����˵�������ȫ�����ʣ����԰�while
										//�����������if��֧��Ϳ����ˣ�
			}
			
			
		}
		else {
			temp->right = newNode;
			newNode->father = temp;
			int childkey = newNode->key;
			int fatherkey = newNode->father->key;
			if (childkey>fatherkey) {
				newNode->key = fatherkey;
				newNode->father->key = childkey;
				que->pop();
				que->push(newNode);

				heapNode *currentnode = newNode->father;	
				while (currentnode->father != theroot&&currentnode->key > currentnode->father->key) {
					int currentkey = currentnode->key;
					currentnode->key = currentnode->father->key;
					currentnode->father->key = currentkey;
					currentnode = currentnode->father;
				}
			}
			else {
				que->pop();
				que->push(newNode);
			}
			
		}
	}
	size++;		
}


void visit(heapNode *t) {
	cout << t->key << "," << t->father->key << ". ";
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