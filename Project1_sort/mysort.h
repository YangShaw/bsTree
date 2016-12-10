#pragma once
template<class T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}