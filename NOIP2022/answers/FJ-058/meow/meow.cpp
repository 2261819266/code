#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e6 + 10;

typedef pair<int, int> PII;
typedef long long LL;

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

int q, n, k, stkn;
int g[N];

void solveit() {
	int stka[N], stkb[N];
	int op;
	int idxa = 0, idxb = 0;
	while(q--) {
		
		read(stkn);
		read(n);
		read(k);
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i) {
			read(g[i]);
			if(idxb && g[i] == stkb[idxb]) {
				printf("1 2\n");
				--idxb;
			}
			else if(!idxa) {
				stka[++idxa] = g[i];
				printf("1 1\n");
			}
			else if(g[i] == stka[idxa]) {
				printf("1 1\n");
				--idxa;
			}
			else {
				printf("1 2\n");
				stkb[++idxb] = g[i];
			}
		}
	}
	return;
	
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	read(q);
	if(q % 10 == 2) 
		solveit();
	return 0;
}
