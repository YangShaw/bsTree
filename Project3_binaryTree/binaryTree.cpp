#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;


template<class T>
class binaryTreeNode {
public:
	T element;
	binaryTreeNode<T> *left;
	binaryTreeNode<T> *right;

	binaryTreeNode() {
		left = right = NULL;
	}

	binaryTreeNode(const T &theElement) {
		element = theElement;
		left = right = NULL;
	}

	binaryTreeNode(binaryTreeNode<T> *theLeft, binaryTreeNode<T> *theRight,const T &theElement ) {
		left = theLeft;
		right = theRight;
		element = theElement;
	}

};

template<class T>
void visit(binaryTreeNode<T> *t) {
	cout << t->element << " ";
}


template<class T>
class linkedBinaryTree {
public:
	int size;
	binaryTreeNode<T> *root;

	linkedBinaryTree() {
		head = NULL;
		size = 0;
	}

	linkedBinaryTree(binaryTreeNode<T> *theRoot);
	int getHeight(binaryTreeNode<T> *t)const;
	int getSize(binaryTreeNode<T> *t)const;
	void preOrder(binaryTreeNode<T> *t)const;
	void inOrder(binaryTreeNode<T> *t)const;
	void postOrder(binaryTreeNode<T> *t)const;
	void levelOrder(binaryTreeNode<T> *t)const;


};

template<class T>
linkedBinaryTree<T>::linkedBinaryTree(binaryTreeNode<T> *theRoot) {
	root = theRoot;
	size = getSize(root);
}


template<class T>
int linkedBinaryTree<T>::getHeight(binaryTreeNode<T> *t)const {
	if (t == NULL)
		return 0;
	int hl = getHeight(t->left);
	int hr = getHeight(t->right);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

template<class T>
int linkedBinaryTree<T>::getSize(binaryTreeNode<T> *t)const {
	if (t == NULL)
		return 0;
	int sl = getSize(t->left);
	int sr = getSize(t->right);
	return sl + sr + 1;
}



template<class T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *t)const {
	if (t != NULL) {
		visit(t);
		preOrder(t->left);
		preOrder(t->right);
	}
}

template<class T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *t)const {
	if (t != NULL) {
		inOrder(t->left);
		visit(t);
		inOrder(t->right);
	}
}

template<class T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *t)const {
	if (t != NULL) {
		postOrder(t->left);
		postOrder(t->right);
		visit(t);
	}
}

template<class T>
void linkedBinaryTree<T>::levelOrder(binaryTreeNode<T> *t)const {
	queue<binaryTreeNode<T>*> *que=new queue<binaryTreeNode<T>*>();		//��Ϊ���ҽڵ㶼��ָ�����ͣ�����������д洢�Ľڵ�Ҳ������ָ������
	while (t != NULL) {
		visit(t);
		if (t->left != NULL)
			que->push(t->left);
		if (t->right != NULL)
			que->push(t->right);

		if (!que->empty()) {
			t = que->front();
			que->pop();
		}
		else
			return;
	}
}



int *pre = new int[100];
int *in = new int[100];
int *a;
void find(int prel, int prer, int inl, int inr) {
	int i = a[pre[prel]];
	int j = i - inl;
	int k = inr - i;
	if (j) {
		find(prel + 1, prel + j, inl, i - 1);
	}
	if (k) {
		find(prel + j + 1, prer, i + 1, inr);
	}
	cout << pre[prel]<<" ";
}

int main() {
	
	

	binaryTreeNode<int> *t8 = new binaryTreeNode<int>(8);
	binaryTreeNode<int> *t1 = new binaryTreeNode<int>(t8,NULL,1);
	binaryTreeNode<int> *t2 = new binaryTreeNode<int>(2);
	binaryTreeNode<int> *t3 = new binaryTreeNode<int>(t1,t2,3);
	binaryTreeNode<int> *t4 = new binaryTreeNode<int>(4);
	binaryTreeNode<int> *t5 = new binaryTreeNode<int>(5);
	binaryTreeNode<int> *t6 = new binaryTreeNode<int>(t4,t5,6);
	binaryTreeNode<int> *t7 = new binaryTreeNode<int>(t3,t6,7);

	linkedBinaryTree<int> *tree = new linkedBinaryTree<int>(t7);
	cout << "ǰ������:";
	tree->preOrder(tree->root);
	cout << endl;
	cout << "��������:";
	tree->inOrder(tree->root);
	cout << endl;
	cout << "��������:";
	tree->postOrder(tree->root);
	cout << endl;
	cout << "�������:";
	tree->levelOrder(tree->root);
	cout << endl;
	cout << "Ԫ�ظ���Ϊ:" << tree->size << endl;
	cout << "�������߶�Ϊ:" << tree->getHeight(tree->root) << endl;

	cout << "��������������Ԫ�ظ�����";
	int n;
	cin >> n;
	a = new int[n];
	cout << "������ǰ�����У�";
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	cout << "�������������У�";
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		a[in[i]] = i;
	}
	cout << "��ú�������Ϊ��";
	find(0, n - 1, 0, n - 1);
	cout << endl;

	/*preOrder(t7);
	cout << endl;
	inOrder(t7);
	cout << endl;
	postOrder(t7);
	cout << endl;
	levelOrder(t7);
	cout << endl;*/
	system("Pause");


}

