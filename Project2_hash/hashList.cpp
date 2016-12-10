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
	int i = theKey %divisor;	//hash�������õ��ؼ����ڳ���D�µ�������������ʼͰ��ֵ
	int j = i;
	do {
		if (table[j] == NULL || table[j]->first == theKey) {
			return j;	//Ϊ�������Ͱ���Է�������ԣ��ؼ���ƥ�������Ͱ�Ѿ������������
		}
		j = (j + 1) % divisor;		
	} while (j != i);	//��j=i��ʱ��˵����ת��һȦ�����ˣ�˵��û�ҵ����ʵ�Ͱ
	return j;
}

template<class K,class E>
pair<const K, E>* hashList<K, E>::find(const K& theKey)const {
	int b = search(theKey);		//�ҵ��ؼ��ֶ�Ӧ��λ��
	if (table[b] == NULL || table[b]->first != theKey) {
		cout << "cannot find the key!   "  << endl;
		pair<const K, E> *nonpair = new pair<const K, E>(0, 0);
		return nonpair;	//û�ҵ�������ԡ�����main�����������find����->second���������û�ҵ����Ե�ʱ�򷵻�NULL��
						//��ô->second�ͻ��Ϊ�գ�������쳣������Ҫ�����ﷵ��һ��ֵΪ0 0�����ԡ�
	}
	cout << "the value in " << theKey << " is ";
	return table[b];	//�����������
}



template<class K,class E>
void hashList<K, E>::insert(const pair<const K, E>& thePair) {

	int b = search(thePair.first);		//�ҵ��ؼ��ֶ�Ӧ��λ��

	if (table[b] == NULL) {		//ֻ���ǿ�ֵʱ���ܲ���
		table[b] = new pair<const K, E>(thePair);		
		dSize++;
	}
	else {
		if (table[b]->first == thePair.first) {
			table[b]->second = thePair.second;		//���¹ؼ��ֶ�Ӧ��Ԫ��ֵ
		}
		else {
			cout << "full table!" << endl;
			return;
		}
	}
}

