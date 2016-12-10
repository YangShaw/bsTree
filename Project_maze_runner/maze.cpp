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
	position here = position(1, 1);		//当前位置坐标

	//分别向上下左右移动的操作，也就是最优先往右找，最后往上返回
	position move[4];
	move[0].row = 0; move[0].col = 1;	//right
	move[1].row = 1; move[1].col = 0;	//down
	move[2].row = 0; move[2].col = -1;	//left
	move[3].row = -1; move[3].col = 0;	//up

	int option = 0;
	int sign = 3;	//最多判断四个方向

	while (here.row != n || here.col != m) {	//没有到达终点

		int r, c;	//分别存向某个方向移动后的坐标，判断一下是否为0，r和c起到暂时保存坐标的作用
		while (option <= sign)	//只要还没四个方向都判断完就可以继续option++
		{
			r = here.row + move[option].row;
			c = here.col + move[option].col;
			if (maze[r][c] == '0') {		//是通路才能break
				break;
			}
			option++;
		}

		if (option <= sign) {	//找到了可以移动的位置，也就是上面的while是通过break跳出的
			//cout << "(" << here.row << "," << here.col << ")" << endl;	
			path->push(here);
			here.row = r;
			here.col = c;
			maze[r][c] = '1';		//阻断退路
			option = 0;			//到达新位置，从0（向右）开始找通路
		}

		else {			//未找到，需要返回前一个位置再找
			if (path->empty())		//一直返回返回到栈中没有位置了，GG。
				return false;
			else {
				//cout << "(" << here.row << "," << here.col << ")" << endl;
				position reback = path->top();
				path->pop();
				if (reback.row == here.row) {
					//与上一个位置在同一行，只有两种情况。
					//右返回左：返回后从1开始查就可以。因为0（向右）已被证实不可过
					//左返回右：返回后只能从3开始查了。因为既然已经到了2（左），说明0,1已经都是不通的了
					option = 2 + reback.col - here.col;
				}
				else {
					//与上一个位置在同一列（因为肯定要么同行要么同列），也有两种情况：
					//下返回上：返回后从2开始查，同理
					//上返回下：继续返回(从4查）。因为在前一个的时候从下往上已经说明其他方向都是死路了，那么往上又是死路，说明前一个位置也要返回。
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

	cout << "(" << n << "," << m << ")" << endl;	//出口没有存入栈中

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
	ifstream infile("C:\\Users\\豫\\Desktop\\数据结构\\ds.txt");
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.getline(a[ti], n+1);	//为什么要比长度大1？
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

	//迷宫边界设为1
	for (int i = 0; i < m + 2; i++) {	//第一行和最后一行
		maze[0][i] = maze[n + 1][i] = '1'; 
	}

	for (int j = 0; j < n + 2; j++) {	//第一列和最后一列
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