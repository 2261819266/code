#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 1005, P = 998244353;

template<typename T>
inline void read(T &X) {
	X = 0;
	bool f = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		f |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch)) {
		X = (X * 10) + (ch ^ 48);
		ch = getchar();
	}
	X = f ? -X : X;
}

int n, m, c, f;
LL resc, resf;
int tem;
int q, id;
char g[N][N];
int s[N][N];
int r[N][N];
vector<PII> alls;

void print() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << s[i][j] <<" ";
		cout << endl;
	}
}

void renewC() {
	int len = alls.size();
	for (int i = 0; i < len; ++i)
		for (int j = i + 2; j < len; ++j)
			resc = (resc + alls[i].first * alls[j].first) % P; 
	for (int i = 0, j = 1; j < len; ++i, ++j)
		if(alls[j].second - alls[i].second > 1) 
			resc = (resc + alls[i].first * alls[j].first) % P;
	alls.clear();
}

void renewF() {
	int len = alls.size();
	for (int i = 0; i < len; ++i)
		for (int j = i + 2; j < len; ++j) 
			resf = (resf + alls[i].first * alls[j].first * r[alls[j].second][tem]) % P;
		
	for (int i = 0, j = 1; j < len; ++i, ++j)
		if(alls[j].second - alls[i].second > 1) 
			resf = (resf + alls[i].first * alls[j].first * r[alls[j].second][tem]) % P;
		
	alls.clear();
}

void init() {
	memset(s, 0, sizeof(s));
	memset(r, 0, sizeof(r));
	int num;
	for (int i = 1; i <= n; ++i) {
		num = -1;
		for (int j = m; j; --j) {
			if(g[i][j] == '0') ++num;
			else num = -1;
			s[i][j] = num;
		}
	}
	for (int j = 1; j <= m; ++j) {
		num = -1;
		for (int i = n; i; --i) {
			if(g[i][j] == '0') ++num;
			else num = -1;
			r[i][j] = num;
		}
	}
	
}

void solveC() {
	if(!c) {
		cout << "0 ";
		return;
	}
	for (int i = 1; i <= m; ++i) {
		alls.clear();
		for (int j = 1; j <= n; ++j) {
			if(g[j][i] == '1') 
				renewC();
			else if(s[j][i]) alls.push_back({s[j][i], j});
		}
		renewC();
	}
	cout << resc << " ";
	return;
}

void solveF() {
	
	if(!f) {
		puts("0");
		return;
	}
	for (int i = 1; i <= m; ++i) {
		alls.clear();
		tem = i;
		for (int j = 1; j <= n; ++j) {
			if(g[j][i] == '1')
				renewF();
			else if(s[j][i]) 
				alls.push_back({s[j][i], j});
		}
		renewF();
	}
	cout << resf <<endl;
	return;
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	read(q);
	read(id);
	while(q --) {
		resc = 0, resf = 0;
		read(n);
		read(m);
		read(c);
		read(f);
		for (int i = 1; i <= n; ++i)
			scanf("%s", g[i] + 1);
		init();
		solveC();
		solveF();
	}	
	return 0;
}
