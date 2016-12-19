#include <iostream>
#include <stdio.h>
#include "adjacencyWDigraph.cpp"
using namespace std;

int main() {
	adjacencyWDigraph<double> *gra = new adjacencyWDigraph<double>(10, 1000);
	gra->insertEdge(1, 2, 5);
	gra->insertEdge(2, 5, 5);
	gra->insertEdge(1, 3, 5);
	gra->insertEdge(1, 4, 5);
	gra->insertEdge(4, 3, 5);
	gra->insertEdge(3, 5, 5);
	gra->insertEdge(4, 6, 5);
	gra->insertEdge(6, 3, 5);
	gra->insertEdge(4, 7, 5);
	gra->insertEdge(5, 8, 5);
	gra->insertEdge(6, 8, 10);
	gra->insertEdge(7, 8, 5);
	gra->insertEdge(7, 9, 5);
	gra->insertEdge(1, 2, 5);
	gra->insertEdge(10, 8, 5);
	cout << gra->numOfEdge() << endl;
	cout << gra->existsEdge(3, 6) << endl;
	cout << gra->existsEdge(1, 5) << endl;
	gra->print();

	bool *reach=NULL;
	gra->bfs(1, reach);
	system("Pause");
}