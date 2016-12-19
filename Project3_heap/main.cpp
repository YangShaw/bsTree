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
	root->father = theroot;		//标志找到头了
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
				//只在最下面这一层有入队的需求，后面如果还不满足就只在倒数第二层网上while，而这些都和入队无关了
				
				heapNode *currentnode = newNode->father;	//不能用原节点操作，因为会改变父子关系。只能交换每个节点的key，而不能交换节点本身
				while (currentnode->father != theroot&&currentnode->key > currentnode->father->key) {
					int currentkey = currentnode->key;
					currentnode->key = currentnode->father->key;
					currentnode->father->key = currentkey;
					currentnode = currentnode->father;
				}
			
			}	
			else {
				que->push(newNode);		//大小合适就不用改 直接插入。而这一层都合适说明上面的全都合适，所以把while
										//语句放在上面的if分支里就可以了！
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