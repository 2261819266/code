#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 5008;
int a[maxn], p[maxn], q[maxn], dp[maxn][maxn], k, n, m;

int dfs(int x, int time) {
	if (x < 1 || time <= 0)
		return 0;
	if (!dp[x][time]) {
		if (p[x] > time)
			dp[x][time] = dfs(x - 1, time);
		else {
			int x1 = dfs(x - 1, time);
			int x2 = dfs(x - 1, time - p[x]) + q[x];
			dp[x][time] = max(x1, x2);
		}
	}
	return dp[x][time];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	{
		int x, y;
		scanf("%d%d", &x, &y);
		k = y / x;
	}
	scanf("%d%d", &m, &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
		a[c] *= k;
	}
	for (int c = 1; c <= m; c++) {
		scanf("%d%d", p + c, q + c);
		p[c] = a[p[c]];
	}
	int time;
	scanf("%d", &time);
	printf("%d", dfs(m, time));
}