#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

inline int read() {
	int n = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') { n = n * 10 + c - 48, c = getchar();}
	return n;
}

int t, n, m, k, a[1000005], z[305][2], top = 1, con[305];
bool ii[305];

struct color {
	int x, y;
} c[305];

inline void pu(int col, int p) {
	if (con[p] == 0)
	z[p][0] = col, c[col] = (color){p, 0};
	else z[p][1] = col, c[col] = (color){p, 1};
	con[p]++;
	printf("1 %d\n", p);
	
}

inline void ins(int col) {
	if (!c[col].x){
	  for (int i = 1; i < n; i++)
	    if (con[i] < 2) {
	    	pu(col, i);
	    	break;
		}}
	else {
		if (c[col].y){
			printf("1 %d\n", c[col].x);
			con[c[col].x]--;
			c[col] = c[0];
		}
		else {
			printf("1 %d\n", n);
			printf("2 %d %d\n", c[col].x, n);
			con[c[col].x]--;
			if (con[c[col].x]) {
				int p = c[col].x;
				z[p][0] = z[p][1];
				c[z[p][1]].y--;
			}
			c[col] = c[0];
		}
	}
}

inline void ins2(int col) {
	if (!c[col].x){
	  for (int i = 1; i <= n; i++)
	    if (con[i] < 2) {
	    	pu(col, i);
	    	break;
		}}
	else {
		if (c[col].y){
			printf("1 %d\n", c[col].x);
			con[c[col].x]--;
			c[col] = c[0];
		}
		else {
			printf("1 %d\n", n);
			printf("2 %d %d\n", c[col].x, n);
			con[c[col].x]--;
			if (con[c[col].x]) {
				int p = c[col].x;
				z[p][0] = z[p][1];
				c[z[p][1]].y--;
			}
			c[col] = c[0];
		}
	}
}

inline void work1() {
	for (int i = 1; i <= m; i++) {
		ins(a[i]);
	}
}

inline void work2() {
	for (int i = 1; i <= m; i++) {
		ins2(a[i]);
	}
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	t = read();
	while (t--) {
		n = read(), m = read(), k = read();
		for (int i = 1; i <= m; i++)
			a[i] = read();
		if (t == 1001) work1();
		else work2();
	}
}
