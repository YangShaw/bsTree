#include <iostream>
#include <stdio.h>
using namespace std;

template<class T>
void insert(T a[], int &n, const T &x) {
	int i;
	for (i = n - 1; i >= 0&&x<a[i]; i--) {
		a[i + 1] = a[i];
	}
	a[i + 1] = x;
	n++;
}

//template<class T>
//class sparseNode
//{
//public:
//	int i;
//	int j;
//	T value;
//	sparseNode() {
//
//	}
//	sparseNode(int i, int j, T value) {
//		this->i = i;
//		this->j = j;
//		this->value = value;
//	}
//};


template<class T>
class sparseMatrix
{
public:
	sparseMatrix() {

	}
	sparseMatrix(int row,int col,int maxSize);
	~sparseMatrix();
	void set(int i, int j, T value);
	void transpone(sparseMatrix<T> *newSparseMatrix)const;
	//void add(sparseMatrix<T> *secondMatrix, sparseMatrix<T> *resultMatrix)const;
	void add(sparseMatrix<T> &secondMatrix, sparseMatrix<T> &resultMatrix)const;


	int row;
	int col;
	int maxSize;	//�����ܷ���Ԫ�صĸ���
	int elementSize;	//ʵ�ʷ���Ԫ�صĸ���
	T *value;
	int *rowArray;
	int *colArray;
	//sparseNode<T> *array;	//�洢����Ԫ�ص�����
};

template<class T>
sparseMatrix<T>::sparseMatrix(int row, int col, int maxSize)
{
	//�����Ҫ�����Ԫ��̫����Ӧ��ϡ�����
	if (maxSize > (row*col)*(row*col) / 3) {
		cout << "too many elements to be put into a sparseMartix." << endl;
	}
	else {
		this->row = row;
		this->col = col;
		this->maxSize = maxSize;
		this->elementSize = 0;

		//��1��ʼ����������һ�е�һ���з���Ԫ�أ������rowArray[1],����
		value = new T[maxSize+1];
		rowArray = new int[maxSize+1];
		colArray = new int[maxSize+1];
		//*array = new sparseNode<T>[maxSize];
	}
}

template<class T>
sparseMatrix<T>::~sparseMatrix()
{
	delete[]array;
}

template<class T>
void sparseMatrix<T>::set(int i, int j, T newValue) {

	int k;
	for (k = elementSize; k >= 1 && rowArray[k]>=i; k--) {
		if (i == rowArray[k])
			if (colArray[k]>j) {
				rowArray[k + 1] = rowArray[k];
				colArray[k + 1] = colArray[k];
				value[k + 1] = value[k];
			}
				
			else
				break;
		else {
			rowArray[k + 1] = rowArray[k];
			colArray[k + 1] = colArray[k];
			value[k + 1] = value[k];
		}
	}
	rowArray[k + 1] = i;
	colArray[k + 1] = j;
	value[k + 1] = newValue;
	elementSize++;

	/*sparseNode<T> *current = new sparseNode<T>(i, j, value);
	int k;
	for (k = elementSize - 1; k >= 0 && i >= array[k].i; k--) {
		if (i == array[k].i)
			if (j > array[k].j)
				array[k + 1] = array[k];
			else
				break;
		else
			array[k + 1] = array[k];
	}
	array[k + 1] = current;
	elementSize++;*/
}

template<class T>
void sparseMatrix<T>::transpone(sparseMatrix<T> *newSparseMatrix)const {
	//newSparseMatrix = new sparseMatrix<T>(this->col, this->row, this->maxSize);
	int *colSize = new int[col+1];	//�洢ԭ�����е�i�е�Ԫ�ظ�����Ҳ�����������е�i�е�Ԫ�ظ���
	int *rowNext = new int[col+1];	//�洢�������е�i�еĵ�һ��Ԫ�ص�������
	newSparseMatrix->elementSize = this->elementSize;

	//��ʼ��colSize
	for (int i = 1; i<=col; i++) {
		colSize[i] = 0;
	}

	//����ԭ����������Ԫ�أ���jλ����Ԫ�ص��к���Ϊ��������colSize�ж�Ӧ�к�λ�õĴ�С��һ��
	//�������ҵ���һ��λ�����λ�õ�Ԫ��
	//�����ҵ��к��к�Ԫ�����鶼�Ǵ�1��ʼ��ģ����������1��ʼ����
	for (int j = 1; j <= elementSize; j++) {
		colSize[colArray[j]]++;
	}

	rowNext[1] = colSize[1] == 0 ? 0 : 1;
	for (int i = 2; i <= col; i++) {
		rowNext[i] = rowNext[i - 1] + colSize[i - 1];
	}

	for (int index = 1; index <= elementSize; index++) {
		int j = rowNext[colArray[index]];
		rowNext[colArray[index]]++;
		newSparseMatrix->rowArray[j] = colArray[index];
		newSparseMatrix->colArray[j] = rowArray[index];
		newSparseMatrix->value[j] = value[index];
	}

}

template<class T>
ostream& operator<<(ostream& out, sparseMatrix<T> &x) {
	int index = 1;
	for (int a = 1; a <= x.row; a++) {
		for (int b = 1; b <= x.col; b++) {
			if (index > x.elementSize) {
				out << 0 << "\t";
				continue;
			}

			if (x.rowArray[index] == a&&x.colArray[index] == b) {
				out << x.value[index] << "\t";
				index++;
			}

			/*if (array[index].i == a&&array[index].j == b) {
			out << T << " ";
			index++;
			}*/
			else
				out << 0 << "\t";
		}
		out << endl;
	}
	return out;
}

template<class T>
void sparseMatrix<T>::add(sparseMatrix<T> &secondMatrix, sparseMatrix<T> &resultMatrix)const {
	if (row != secondMatrix.row || col != secondMatrix.col) {
		cout << "cannot be added!" << endl;
		return;
	}
	

	/*resultMatrix.row = row;
	resultMatrix.col = col;
	resultMatrix.maxSize = row*col;
	resultMatrix.value = new T[resultMatrix.maxSize + 1];
	resultMatrix.rowArray = new int[resultMatrix.maxSize + 1];
	resultMatrix.colArray = new int[resultMatrix.maxSize + 1];*/

	int i = 1;
	int j = 1;
	int k = 1;
	while (i <= this->elementSize&&j <= secondMatrix.elementSize) {
		if (this->rowArray[i] < secondMatrix.rowArray[j]) {		//��������Ϊa����һ�������Ϊb��a������b����ǰ�棬��a
			resultMatrix.rowArray[k] = this->rowArray[i];
			resultMatrix.colArray[k] = this->colArray[i];
			resultMatrix.value[k] = this->value[i];
			k++;
			i++;
		}
		else if (this->rowArray[i] > secondMatrix.rowArray[j]) {	//a������b���к��棬�Ͳ���b�е�Ԫ��
			resultMatrix.rowArray[k] = secondMatrix.rowArray[j];
			resultMatrix.colArray[k] = secondMatrix.colArray[j];
			resultMatrix.value[k] = secondMatrix.value[j];
			k++;
			j++;
		}
		else {	//a,b�к���ȣ����ж�һ���к�
			if (this->colArray[i] < secondMatrix.colArray[j]) {		//a���к�С������a
				resultMatrix.rowArray[k] = this->rowArray[i];
				resultMatrix.colArray[k] = this->colArray[i];
				resultMatrix.value[k] = this->value[i];
				k++;
				i++;
			}
			else if (this->colArray[i]>secondMatrix.colArray[j]){		//b���к�С������b
				resultMatrix.rowArray[k] = secondMatrix.rowArray[j];
				resultMatrix.colArray[k] = secondMatrix.colArray[j];
				resultMatrix.value[k] = secondMatrix.value[j];
				k++;
				j++;
			}
			else		//a,b�к���ȣ��ж϶��ߺ��Ƿ�Ϊ��
			{
				T result = this->value[i] + secondMatrix.value[j];
				if (result != 0) {
					resultMatrix.rowArray[k] = this->rowArray[i];
					resultMatrix.colArray[k] = this->colArray[i];
					resultMatrix.value[k] = result;
					k++;
				}
				i++;
				j++;	//�����Ƿ�����㣬a��b��ȷʵ���Ƕ���һ��Ԫ���ˣ�����i++��j++Ҫд��if�������
			}
		}
	}
	while (i <= this->elementSize) {
		resultMatrix.rowArray[k] = this->rowArray[i];
		resultMatrix.colArray[k] = this->colArray[i];
		resultMatrix.value[k] = this->value[i];
		k++;
		i++;
	}

	while (j<=secondMatrix.elementSize){
		resultMatrix.rowArray[k] = secondMatrix.rowArray[j];
		resultMatrix.colArray[k] = secondMatrix.colArray[j];
		resultMatrix.value[k] = secondMatrix.value[j];
		k++;
		j++;
	}
	resultMatrix.elementSize = k;	//��һ�д���ǳ��ؼ�����Ϊ����ǻ��ھ�������elementsize���ж���ֹ�ģ������
									//��ͷ����Ĵ�����ÿ�θ��;���ֵʱ��û��elementsize++���������Ҫ������ôһ�䡣

}



