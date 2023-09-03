#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 505;
int v[maxn], q[maxn], k[maxn], dp[maxn][maxn][maxn], n;

int dfs(int x, int y, int z) {
	if (y <= 0 || z <= 0 || x == 0)
		return 0;
	if (!dp[x][y][z]) {
		if (y < v[x] || z < q[x])
			dp[x][y][z] = dfs(x - 1, y, z);
		else {
			int x1 = dfs(x - 1, y, z);
			int x2 = dfs(x - 1, y - v[x], z - q[x]) + k[x];
			dp[x][y][z] = max(x1, x2);
		}
	}
	return dp[x][y][z];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int vmax, qmax;
	scanf("%d%d%d", &vmax, &qmax, &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d%d%d", v + c, q + c, k + c);
	}
	printf("%d", dfs(n, vmax, qmax));
}
