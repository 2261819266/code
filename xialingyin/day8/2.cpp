#include<cstdio>
#include<cmath>
const int maxn = 100000 + 5;
struct tree {
	int fa;
	int sd;
	int next[10];
	int sonn;
} a[maxn];

int getroot(int n) {
	for (int c = 1; c <= n; c++) {
		if (a[c].fa == 0)
			return c;
	}
	return 0;
}

int getsd(int rt, int k) {
	int num;
	for (num = 0;; num++) {
		if (k == rt) {
			return num;
		} else {
			k = a[k].fa;
		}
	}
}
int n, m, c, d, e, rt;
int main() {
	freopen("lca.in", "r", stdin);
////	freopen("lca.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (c = 1; c < n; c++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[y].fa = x;
		a[x].next[++a[x].sonn]=y;
	}
	rt = getroot(n);
	for (c = 1; c <= n; c++) {
		a[c].sd = getsd(rt, c);
	}
	for (c = 0; c < m; c++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d", std::min(a[x].sd, a[y].sd));
	}
	
}