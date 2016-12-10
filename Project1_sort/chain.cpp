#include <iostream>

template<class T>
class chainNode
{
public:

	T element;
	chainNode<T> *next;

	chainNode() {}
	chainNode(const T& element) {
		this->element = element;
	}
	chainNode(const T& element, chainNode<T> *next) {
		this->element = element;
		this->next = next;
	}
};


template<class T>
class chain
{
protected:
	chainNode<T> *first;
	int length;
	void checkIndex(int index) {
		if (index > length || index<0) {
			std::cout << "IMPROPER!";
			return;
		}
	}
public:

	chain() {
		first = NULL;
		length = 0;
	}
	//create a new and empty chain.
	/*chain(int size = 10) {
	if (size < 1)
	{
	std::cout << "Initial capacity" << size << "must be > 0";
	return;
	}
	first = NULL;
	length = 0;
	}*/

	//copy an existed list to this new chain.
	chain(const chain<T>& list) {
		length = list.length;
		if (length == 0) {
			first = NULL;
			retrun;
		}

		chainNode<T> *sourceNode = list.first;
		first = new chainNode<T>(sourceNode->element);//sourceNode is a point variable so we should use '->' to get the object it points to;
		sourceNode = sourceNode->next;
		chainNode<T> *recentNode = first;
		while (sourceNode != NULL) {
			recentNode->next = new chainNode<T>(sourceNode->element, sourceNode->next);
			recentNode = recentNode->next;
			sourceNode = sourceNode->next;
		}
		recentNode->next = NULL;
	}

	//~chain() {
	//	chain<T> *current = new chain<T>();
	//	current = first->next;
	//	while (current != 0) {
	//		delete first;
	//		first = current;
	//		current = current->next;
	//	}
	//	delete first;
	//}

	bool empty() const {
		return length == 0;
	}

	int size() const {
		return length;
	}

	T getFirst() const {
		return first->element;
	}

	int indexOfElement(const T& theElement) const {
		chainNode<T> *current = first;
		int index = 0;
		while (current != NULL&&current->element != theElement) {
			current = current->next;
			index++;
		}

		if (current = NULL)
			return -1;
		else
			return index;
	}

	void deleteE(int index) {
		checkIndex(index);
		chainNode<T> *denode;
		if (index == 0) {
			denode = first;
			first = first->next;
		}
		else {
			chainNode<T> *current = first;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			denode = current->next;
			current->next = current->next->next;
		}
		length--;
		delete denode;

	}

	void insert(int index, const T& theElement) {
		checkIndex(index);

		if (index == 0) {
			first = new chainNode<T>(theElement, first);
		}
		else {
			chainNode<T> *current = first;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			current->next = new chainNode<T>(theElement, current->next);
		}
		length++;
	}

	/*void output(ostream& out) const{
	for (chainNode<T> *current = first; current != null; current = current->next) {
	out << current->element << " ";
	}
	}

	ostream& operator<<(ostream &out, const chain<T>& x) {
	x.output(out);
	return out;
	}*/

	void printChain()const {
		chainNode<T> *current = first;
		for (int i = 0; i < length; i++) {
			cout << current->element << " ";
			current = current->next;
		}
	}




};
