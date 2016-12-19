#include <iostream>
#include <stdio.h>
#include "graph.cpp"
#include <queue>
using namespace std;

template<class T>
class adjacencyWDigraph {
public:
	adjacencyWDigraph(int nov, T theNoEdge=0);
	void print() const;
	int numOfVertice() const;
	int numOfEdge() const;
	bool existsEdge(int i, int j) const;
	void insertEdge(int i, int j, T weight);
	void eraseEdge(int i, int j);
	void bfs(int v, bool *reach);
	void dfs(int v, bool *reach);
protected:
	int n;
	int e;
	T **a;
	T noEdge;
	
};

template<class T>
adjacencyWDigraph<T>::adjacencyWDigraph(int nov,T theNoEdge=0) {
	if (nov < 0) {
		cout << "illegal value!" << endl;
		return;
	}
	noEdge = theNoEdge;
	n = nov;
	e = 0;
	a = new T*[n + 1];	//索引从1开始
	for (int i = 0; i < n + 1; i++) {
		a[i] = new T[n + 1];
	}
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n + 1; j++) {
			a[i][j] = noEdge;
		}
	}
}

template<class T>
int adjacencyWDigraph<T>::numOfEdge() const {
	return e;
}

template<class T>
int adjacencyWDigraph<T>::numOfVertice() const {
	return n;
}

template<class T>
bool adjacencyWDigraph<T>::existsEdge(int i, int j) const {
	if (i<1 || j<1 || i>n || j>n) {
		cout << "illegal value!" << endl;
		return false;
	}
	else if (a[i][j] == noEdge)
		return false;
	else
		return true;
}

template<class T>
void adjacencyWDigraph<T>::insertEdge(int i, int j, T weight) {
	if (i<1 || j<1 || i>n || j>n) {
		cout << "illegal value!" << endl;
		return;
	}
	if (a[i][j] == noEdge) {
		e++;
	}
	a[i][j] = weight;
}

template<class T>
void adjacencyWDigraph<T>::eraseEdge(int i, int j) {
	if (a >= 1 && j >= 1C&&a <= n&&j <= n&&a[i][j] != noEdge) {
		a[i][j] = noEdge;
		e--;
	}
}

template<class T>
void adjacencyWDigraph<T>::print()const {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (a[i][j] != noEdge)
				cout << "("<<i<<","<<j<<")"<<":"<<a[i][j] << " ";
		}
	}
}

template<class T>
void adjacencyWDigraph<T>::bfs(int v, bool *reach) {
	reach = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		reach[i] = false;
	}
	queue<int> *que = new queue<int>();
	cout << v;
	for (int i = 1; i <= n; i++) {
		if (a[v][i] != noEdge) {
			que->push(i);
			reach[i] = true;
		}
	}
	reach[v] = true;
	while (!que->empty()) {
		v = que->front();
		que->pop();
		cout << "→" << v;
		for (int i = 1; i <= n; i++) {
			if (reach[i] == false&&a[v][i] != noEdge) {
				que->push(i);
				reach[i] = true;
			}
		}
	}
}

template<class T>
void adjacencyWDigraph<T>::dfs(int i, bool *reach) {

}