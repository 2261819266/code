#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 1005;
int w[maxn], v[maxn], dp[maxn][maxn], n, W;

int dfs(int x, int y) {
	if (y <= 0 || x <= 0)
		return 0;
	if (!dp[x][y]) {
		int x1 = dfs(x - 1, y);
		if (w[x] > y)
			dp[x][y] = x1;
		else {
			int x2 = dfs(x - 1, y - w[x]) + v[x];
			dp[x][y] = max(x1, x2);
		}
	}
	return dp[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &W);
	for (int c = 1; c <= n; c++) {
		scanf("%d%d", w + c, v + c);
	}
	printf("%d", dfs(n, W));
}
