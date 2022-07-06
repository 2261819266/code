#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 30005, maxm = 30;
int v[maxm], w[maxm], dp[maxm][maxn];

int dfs(int x, int y) {
	if (x == 0 || y == 0)
		return 0;
	if (!dp[x][y]) {
		if (v[x] > y) {
			return dfs(x - 1, y);
		}
		int x1 = dfs(x - 1, y), x2 = dfs(x - 1, y - v[x]) + v[x] * w[x];
		dp[x][y] = max(x1, x2);
	}
	return dp[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int c = 1; c <= m; c++) {
		scanf("%d%d", v + c, w + c);
	}
	printf("%d", dfs(m, n));
}