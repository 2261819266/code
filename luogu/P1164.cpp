#include <cstdio>
#include <cstring>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxm = 10005, maxn = 105;
int n, m, a[maxn], dp[maxn][maxm];

int dfs(int x, int y) {
	if (y == 0)
		return 1;
	if (x == 0 || y < 0)
		return 0;
	if (dp[x][y] == -1) {
		dp[x][y] = dfs(x - 1, y) + dfs(x - 1, y - a[x]);
	}
	return dp[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
	}
	printf("%d", dfs(n, m));
}