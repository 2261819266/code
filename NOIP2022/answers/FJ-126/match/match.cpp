#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long cgz;
const int N = 3e3 + 10;
int T, n, a[N], b[N];
cgz res[N][N], pre[N][N];

int Q;
struct Query {
	int l; 
	int r;
} qu[N];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &b[i]);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++ i) {
		scanf("%d%d", &qu[i].l, &qu[i].r);
	}
	for (int i = 1; i <= n; ++ i) {
		int maxa = a[i], maxb = b[i];
		for (int j = i; j <= n; ++ j) {
			maxa = max(maxa, a[j]); 
			maxb = max(maxb, b[j]);
			res[i][j] = maxa * maxb;
		}
	}
	for (int i = 1; i <= n; ++ i) {
		pre[i][i] = res[i][i];
		for (int j = i + 1; j <= n; ++ j) {
			pre[i][j] = pre[i][j - 1] + res[i][j];
		}
	}
	for (int i = 1; i <= Q; ++ i) {
		cgz ans = 0;
		for (int l = qu[i].l; l <= qu[i].r; ++ l)
			ans += pre[l][qu[i].r];
		printf("%llu\n", ans);
	}
	
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
