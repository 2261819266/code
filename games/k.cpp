#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;
using std::queue;
using std::stack;
typedef struct Point {
	int x;
	int y;
	int d; //方向 若方向为-1，则表示起点
} Point;
queue<Point> mqueue;
stack<Point> mstack;
Point pos, pos1;
int m, n;					  //迷宫行（tm-1）/2和列（tn-1）/2
int tm, tn;					  //实际作图
int x, y, tx1, tx2, ty1, ty2; //点坐标
int d;
int s[10000000];
int maze[1000][1000], mark[1000][1000];				 //最大迷宫
int sign[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //上下左右四个方向 0上 1下 2上 3下
Point start;
int Find_x(int x);
void unionSets(int node1, int node2);
void Init();
int getAdd(int x, int y);
void foundpath();
void fixmaze();
int connected(int node1, int node2);
void Findpath();
void changemaze();
int main() {
	Init();
	cout << "请输入迷宫规模2x-1,2y-1：（x y）" << endl;
	cin >> m >> n;
	tm = m * 2 + 1;
	tn = n * 2 + 1;
	start.x = 1;
	start.y = 1;
	start.d = -1;
	mqueue.push(start);
	for (int i = 0; i < tm; i++) {
		for (int j = 0; j < tn; j++) {
			maze[i][j] = 1;
			mark[i][j] = 0;
		}
	}
	for (int i = 1; i < tm - 1; i += 2) {
		for (int j = 1; j < tn - 1; j += 2)
			maze[i][j] = 0;
	}
	srand(time(NULL));
	foundpath();
	fixmaze();
	cout << "迷宫全图：" << endl;
	for (int i = 0; i < tm; i++) {
		for (int j = 0; j < tn; j++) {
			if (maze[i][j] == 1)
				cout << "▇";
			else if (maze[i][j] == 0)
				cout << "□";
		}
		cout << endl;
	}
	Findpath();
	changemaze();
	cout << "找到的通路：“..”表示：" << endl;
	for (int i = 0; i < tm; i++) {
		for (int j = 0; j < tn; j++) {
			if (maze[i][j] == 1)
				cout << "▇";
			else if (maze[i][j] == 0)
				cout << "□";
			else if (maze[i][j] == -1)
				cout << "..";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
int connected(int node1, int node2) { return Find_x(node1) == Find_x(node2); }
int Find_x(int x) {
	if (s[x] < 0)
		return x;
	else
		return Find_x(s[x]);
};
void unionSets(int node1, int node2) {
	int root1 = Find_x(node1);
	int root2 = Find_x(node2);
	if (root1 == root2)
		return;
	if (s[root2] < s[root1])
		s[root1] = root2;
	else {
		if (s[root1] == s[root2])
			s[root1]--;
		s[root2] = root1;
	}
};
int getAdd(int x, int y) { return (x * tn + y); };
void Init() {
	for (int i = 0; i < 10000000; ++i)
		s[i] = -1;
};
void foundpath() {
	while (connected(getAdd(1, 1), getAdd(tm - 2, tn - 2)) != 1) {
		do {
			x = rand() % (tm - 2) + 1;
			y = rand() % (tn - 2) + 1;
		} while (maze[x][y] == 0);
		d = x % 2;
		if (d == 0) {
			tx1 = x + 1;
			ty1 = y;
			tx2 = x - 1;
			ty2 = y;
			if (connected(getAdd(tx1, ty1), getAdd(tx2, ty2)) != 1) {
				maze[x][y] = 0;
				unionSets(Find_x(getAdd(tx1, ty1)), Find_x(getAdd(tx2, ty2)));
			}
		} else if (d == 1) {
			tx1 = x;
			ty1 = y + 1;
			tx2 = x;
			ty2 = y - 1;
			if (connected(getAdd(tx1, ty1), getAdd(tx2, ty2)) != 1) {
				maze[x][y] = 0;
				unionSets(Find_x(getAdd(tx1, ty1)), Find_x(getAdd(tx2, ty2)));
			}
		}
	}
}
void fixmaze() {
	for (int i = 1; i < tm - 1; i++) {
		for (int j = 1; j < tn - 1; j++) {
			if (maze[i - 1][j] == 1 && maze[i + 1][j] == 1 && maze[i][j + 1] == 1 &&
				maze[i][j - 1] == 1) {
				maze[i][j] = 1;
			}
		}
	}
	for (int i = 1; i < tm - 1; i++) {
		for (int j = 1; j < tn - 1; j++) {
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 1 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 1 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 1 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 1 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 1 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 1 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 1 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 1 && maze[i + 1][j + 1] == 0) {
				maze[i][j] = 1;
			}
			if (maze[i - 1][j - 1] == 0 && maze[i - 1][j] == 0 && maze[i - 1][j + 1] == 0 &&
				maze[i][j - 1] == 0 && maze[i][j] == 0 && maze[i][j + 1] == 0 &&
				maze[i + 1][j - 1] == 0 && maze[i + 1][j] == 0 && maze[i + 1][j + 1] == 1) {
				maze[i][j] = 1;
			}
		}
	} //局部优化，防止出现大面积通路
}
void Findpath() {
	int flag = 0;
	int i, j;
	while (!mqueue.empty()) {
		i = mqueue.front().x;
		j = mqueue.front().y;
		mark[i][j] = 1;
		for (int k = 0; k < 4; k++) {
			if (mark[i + sign[k][0]][j + sign[k][1]] == 0 &&
				maze[i + sign[k][0]][j + sign[k][1]] == 0) {
				pos.x = i + sign[k][0];
				pos.y = j + sign[k][1];
				pos.d = k;
				mark[pos.x][pos.y] = 1;
				mqueue.push(pos);
				if (mqueue.back().x == tm - 2 && mqueue.back().y == tn - 2) {
					mstack.push(mqueue.front());
					mstack.push(mqueue.back());
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			break;
		mstack.push(mqueue.front());
		if (!mqueue.empty())
			mqueue.pop();
	}
}
void changemaze() {
	int i, j, k;
	i = mstack.top().x;
	j = mstack.top().y;
	k = mstack.top().d;
	maze[i][j] = -1;
	while (mstack.size() > 0) {
		if (mstack.top().x == i - sign[k][0] && mstack.top().y == j - sign[k][1]) {
			i = i - sign[k][0];
			j = j - sign[k][1];
			k = mstack.top().d;
			maze[i][j] = -1;
			if (!mstack.empty())
				mstack.pop();
		} else if (!mstack.empty())
			mstack.pop();
	}
}