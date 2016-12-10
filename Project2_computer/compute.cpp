#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <sstream>
using namespace std;



//字符串转化成任意类型数字
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
	double result2 = stringToNumber<double>(numbers.top());		//必须要先提取出来，因为-和/运算对次序有要求
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
	numbers.push(numberToString<double>(result));	//运算完的结果再放栈中，这样边向栈中插元素边把前面可以计算的部分就算完了
	operators.pop();								//这个运算符已经被消耗掉，从栈中移出

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
			if (s.substr(j, i - j) != "") {		//由于括号的存在，可能前面并没有数，先判断一下
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
				operators->pop();//删除左括号
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
	int size = numbers->size();		//size会在computthis方法里面不断改变，所以要提前存起来！！！！
	for (int i = 0; i < size-1; i++) {
		computeThis(*numbers, *operators);
	}
	return numbers->top();
	
}



int main() {
	cout << "请输入合理的运算表达式：(例如 3+（8*9）-2.5 ，输入0则退出）" << endl;
	string s = " ";
	
	while (s != "0") {
		cin >> s;
		
		

		if (s != "0") {
			cout << divide(s) << endl;
			cout << "请输入合理的运算表达式：(例如 3+（8*9）-2.5 ，输入0则退出）" << endl;
		}
		else
			return 0;
	}
	cin.ignore();
	cin.ignore();
	return 0;
}