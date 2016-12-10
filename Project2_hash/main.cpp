#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "hashList.cpp"
#include "hashChain.cpp"
using namespace std;

int main() {
	/*hashList<int, int> *myHash = new hashList<int, int>(961);
	for (int i = 0; i < 500; i++) {
		int ran = 1 + rand() % 10000;
		pair<int, int> *pair1 = new pair<int, int>(ran, i);
		cout << "pair"<<i<<":key is " << pair1->first << " and value is " << pair1->second << endl;
		myHash->insert(*pair1);
	}

	int n = 1;
	while (n) {
		cout << "输入要查询的关键字（输入0则终止）：";
		cin >> n;
		if(n)
		cout << myHash->find(n)->second << endl;
	}*/

	hashChain<int, int> *my = new hashChain<int, int>(961);
	
	for (int i = 0; i < 500; i++) {
		int ran = 1 + rand() % 10000;
		pair<int, int> *pair1 = new pair<int, int>(ran, i);
		cout << "pair"<<i<<":key is " << pair1->first << " and value is " << pair1->second << endl;
		my->insert(*pair1);
	}

	int n = 1;
	while (n) {
		cout << "输入要查询的关键字（输入0则终止）：";
		cin >> n;
		if(n)
		cout << my->find(n)->second << endl;
	}
	
	cin.ignore();
	cin.ignore();
	return 0;
}




/*pair<int, int> *pair1 = new pair<int, int>(961, 1);
cout << "key is" << pair1->first << " and value is" << pair1->second << endl;
pair<int, int> *pair2 = new pair<int, int>(963, 2);
cout << "key is" << pair2->first << " and value is" << pair2->second << endl;
pair<int, int> *pair3 = new pair<int, int>(962, 3);
cout << "key is" << pair3->first << " and value is" << pair3->second << endl;*/

//sortedChain<int, int> *my = new sortedChain<int, int>();