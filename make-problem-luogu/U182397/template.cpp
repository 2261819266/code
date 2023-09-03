#include <algorithm>
#include <cstdio>
#define ll long long

const int maxn = 1000;
int n, m, a[maxn][maxn];
int dp[maxn][maxn];

int dfs(int x, int y) {
	if (x > n || y > m)
		return 0x3fffffff;
	if (x == n && y == m)
		return a[x][y];
	if (dp[x][y] == 0)
		dp[x][y] = std::min(dfs(x + 1, y), dfs(x, y + 1)) + a[x][y];
	return dp[x][y];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", dfs(1, 1));
}
