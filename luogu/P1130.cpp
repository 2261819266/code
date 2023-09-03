#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 2005;
int a[maxn][maxn], dp[maxn][maxn];

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int c = 1; c <= m; c++) {
		for (int d = 1; d <= n; d++) {
			scanf("%d", &a[c][d]);
		}
	}
	for (int c = n; c > 0; c--) {
		for (int d = 1; d <= m; d++) {
			dp[d][c] = min(dp[d][c + 1], dp[d % m + 1][c + 1]) + a[d][c];
		}
	}
	int maxx = 0x7fffffff;
	for (int c = 1; c <= m; c++) {
		maxx = min(maxx, dp[c][1]);
	}
	printf("%d", maxx);
}