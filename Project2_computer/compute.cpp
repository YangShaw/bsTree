#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <sstream>
using namespace std;



//�ַ���ת����������������
template<class T>
T stringToNumber(const string& str) {
	istringstream iss(str);
	T num;
	iss >> num;
	return num;
}

template<class T>
string numberToString(T a) {
	stringstream ss;
	ss << a;
	return ss.str();
}

void computeThis(stack<string> &numbers,stack<pair<char,int>> &operators) {
	double result = stringToNumber<double>(numbers.top());
	numbers.pop();
	double result2 = stringToNumber<double>(numbers.top());		//����Ҫ����ȡ��������Ϊ-��/����Դ�����Ҫ��
	numbers.pop();

	cout << result2 << operators.top().first << result;
	switch (operators.top().first) {
	case '*': {
		result = result2*result;
		break;
	}
	case '/': {
		/*if (result == 0) {
			cout << "there cannot be a zero!" << endl;
			return;
		}*/
		result = result2/result;
		break;
	}
	case '+': {
		result = result2+result;
		break;
	}
	case '-': {
		result = result2-result;
		break;
	}
	}
	cout << "=" << result << endl;
	numbers.push(numberToString<double>(result));	//������Ľ���ٷ�ջ�У���������ջ�в�Ԫ�ر߰�ǰ����Լ���Ĳ��־�������
	operators.pop();								//���������Ѿ������ĵ�����ջ���Ƴ�

}

string divide(string s) {
	stack<string> *numbers = new stack<string>;
	stack<pair<char, int>> *operators = new stack<pair<char, int>>;
	int i = 0;
	int j = 0;
	int sign = 0;
	while (i < s.length()) {
		if (s[i] == '.' || (s[i] >= '0'&&s[i] <= '9')) {
			i++;
		}
		else {
			if (s.substr(j, i - j) != "") {		//�������ŵĴ��ڣ�����ǰ�沢û���������ж�һ��
				numbers->push(s.substr(j, i - j));
			}
			
			char oper = s[i];
			int m = 0;
			switch (oper)
			{
			case '+':
			case '-': {
				m = 1;
				break;
			}
			case '*':
			case '/':{
				m = 3;
				break;
			}
			case '(': {
				m = 5;
				break;
			}
			case ')': {
				while (operators->top().first!= '(') {
					computeThis(*numbers, *operators);
				}
				operators->pop();//ɾ��������
				if (!operators->empty()) {
					sign = operators->top().second%5;
				}
				else
					sign = 0;
				break;
			}
			}
			if (oper != ')') {
				while (m <= sign) {
					computeThis(*numbers, *operators);
					if (!operators->empty()) {
						sign = operators->top().second%5;
					}
					else
						sign = 0;
				}
				operators->push(pair<char, int>(oper, m));
				sign = operators->top().second % 5;
			}
				
			i++;
			j = i;
		}
	}
	if (i > j) {
		numbers->push(s.substr(j, i - j));
	}
	
	//computeThis(*numbers, *operators);
	int size = numbers->size();		//size����computthis�������治�ϸı䣬����Ҫ��ǰ��������������
	for (int i = 0; i < size-1; i++) {
		computeThis(*numbers, *operators);
	}
	return numbers->top();
	
}



int main() {
	cout << "����������������ʽ��(���� 3+��8*9��-2.5 ������0���˳���" << endl;
	string s = " ";
	
	while (s != "0") {
		cin >> s;
		
		

		if (s != "0") {
			cout << divide(s) << endl;
			cout << "����������������ʽ��(���� 3+��8*9��-2.5 ������0���˳���" << endl;
		}
		else
			return 0;
	}
	cin.ignore();
	cin.ignore();
	return 0;
}