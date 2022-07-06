#include <algorithm>
#include <cmath>
#include <cstdio>

const int maxn = 105;
int a[maxn], dp[maxn][maxn * maxn][maxn], num;

int dfs(int x, int y, int k) {
	if (x < k || k < 0 || y > num) {
		return 0;
	}
	if (!x)
		return y;
	if (!dp[x][y][k]) {
		int x1, x2;
		x2 = dfs(x - 1, y + a[x], k - 1);
		x1 = dfs(x - 1, y, k);
		dp[x][y][k] = std::max(x1, x2);
	}
	return dp[x][y][k];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, k = 0;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
		k += a[c];
	}
	num = k / 2;
	int maxx = 0;
	// printf("%d", dfs(n, 0, n / 2));
	for (int c = 0; c <= n; c++) {
		for (int d = num - a[c]; d >= 0; d--) {
			for (int e = 0; e <= n / 2; e++) {
				if (c == 0 && e == 0) {
					dp[c][d][e] = a[c];
				}
				if (c == 0 || e == 0) {
					continue;
				}
				dp[c][d][e] = std::max(dp[c - 1][d][e], dp[c - 1][d + a[c]][e - 1]);
				maxx = std::max(maxx, dp[c][d][e]);
			}
		}
	}
	printf("%d", maxx);
	return 0;
}
