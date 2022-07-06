#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 20005, maxm = 100;
int a[maxm], n, dp[maxm][maxn];

int dfs(int x, int v) {
	if (v == 0 || x == 0)
		return v;
	if (!dp[x][v]) {
		int x1 = dfs(x - 1, v);
		int x2 = a[x] > v ? 0x7fffffff : dfs(x - 1, v - a[x]);
		dp[x][v] = min(x1, x2);
	}
	return dp[x][v];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int e;
	scanf("%d%d", &e, &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
	}
	printf("%d", dfs(n, e));
}