#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

class position {
public:
	int row;
	int col;
	position() {
		row = 0;
		col = 0;
	}
	position(int i, int j) {
		row = i;
		col = j;
	}
};

bool findPath(vector< vector<char> > &maze, int n, int m, stack<position> *path) {
	position here = position(1, 1);		//��ǰλ������

	//�ֱ������������ƶ��Ĳ�����Ҳ���������������ң�������Ϸ���
	position move[4];
	move[0].row = 0; move[0].col = 1;	//right
	move[1].row = 1; move[1].col = 0;	//down
	move[2].row = 0; move[2].col = -1;	//left
	move[3].row = -1; move[3].col = 0;	//up

	int option = 0;
	int sign = 3;	//����ж��ĸ�����

	while (here.row != n || here.col != m) {	//û�е����յ�

		int r, c;	//�ֱ����ĳ�������ƶ�������꣬�ж�һ���Ƿ�Ϊ0��r��c����ʱ�������������
		while (option <= sign)	//ֻҪ��û�ĸ������ж���Ϳ��Լ���option++
		{
			r = here.row + move[option].row;
			c = here.col + move[option].col;
			if (maze[r][c] == '0') {		//��ͨ·����break
				break;
			}
			option++;
		}

		if (option <= sign) {	//�ҵ��˿����ƶ���λ�ã�Ҳ���������while��ͨ��break������
			//cout << "(" << here.row << "," << here.col << ")" << endl;	
			path->push(here);
			here.row = r;
			here.col = c;
			maze[r][c] = '1';		//�����·
			option = 0;			//������λ�ã���0�����ң���ʼ��ͨ·
		}

		else {			//δ�ҵ�����Ҫ����ǰһ��λ������
			if (path->empty())		//һֱ���ط��ص�ջ��û��λ���ˣ�GG��
				return false;
			else {
				//cout << "(" << here.row << "," << here.col << ")" << endl;
				position reback = path->top();
				path->pop();
				if (reback.row == here.row) {
					//����һ��λ����ͬһ�У�ֻ�����������
					//�ҷ����󣺷��غ��1��ʼ��Ϳ��ԡ���Ϊ0�����ң��ѱ�֤ʵ���ɹ�
					//�󷵻��ң����غ�ֻ�ܴ�3��ʼ���ˡ���Ϊ��Ȼ�Ѿ�����2���󣩣�˵��0,1�Ѿ����ǲ�ͨ����
					option = 2 + reback.col - here.col;
				}
				else {
					//����һ��λ����ͬһ�У���Ϊ�϶�Ҫôͬ��Ҫôͬ�У���Ҳ�����������
					//�·����ϣ����غ��2��ʼ�飬ͬ��
					//�Ϸ����£���������(��4�飩����Ϊ��ǰһ����ʱ����������Ѿ�˵��������������·�ˣ���ô����������·��˵��ǰһ��λ��ҲҪ���ء�
					option = 3 + reback.row - here.row;
				}
				here = reback;
			}
		}
	}
	return true;
}

void printPath(vector< vector<char> > &maze, int n, int m, stack<position> *path) {
	position current;
	stack<position> *temp = new stack<position>;
	while (!path->empty()) {
		current = path->top();
		maze[current.row][current.col] = '8';
		temp->push(current);
		path->pop();
	}
	maze[n][m] = '8';

	while (!temp->empty()) {
		current = temp->top();
		cout << "(" << current.row << "," << current.col << ")" << endl;
		temp->pop();
	}

	cout << "(" << n << "," << m << ")" << endl;	//����û�д���ջ��

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main() {

	int n, m=0;
	cout << "input the size of the maze:" << endl;
	cin >> n;
	cin >> m;

	char a[20][20];
	int ti = 0;
	ifstream infile("C:\\Users\\ԥ\\Desktop\\���ݽṹ\\ds.txt");
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.getline(a[ti], n+1);	//ΪʲôҪ�ȳ��ȴ�1��
			ti++;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			cout << a[j][k] << " ";
		}
		cout << endl;
	}
	
	vector< vector<char> > maze(n+2);

	for (int i = 0; i < n+2; i++) {
		maze[i].resize(m+2);
	}
	
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			maze[i][j] = a[i-1][j-1];
		}
	}

	//�Թ��߽���Ϊ1
	for (int i = 0; i < m + 2; i++) {	//��һ�к����һ��
		maze[0][i] = maze[n + 1][i] = '1'; 
	}

	for (int j = 0; j < n + 2; j++) {	//��һ�к����һ��
		maze[j][0] = maze[j][m + 1] = '1';
	}

	
	stack<position> *path = new stack<position>;
	if (findPath(maze, n, m, path)) {
		printPath(maze, n, m, path);
	}
	else {
		cout << "No way to go!" << endl;
	}

	system("Pause");
}