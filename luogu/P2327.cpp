#include <cstdio>
#include <cstring>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 10005;
int a[maxn], dp[maxn][3][3], n;

void init() { memset(dp, -1, sizeof(dp)); }

int dfs(int x, bool k = false, bool kk = false) {
	if (x == 0)
		return a[1] - k - kk == 0 ? 1 : 0;
	int y = a[x + 1] - k - kk;
	if (y < 0 || y > 1)
		return 0;
	if (dp[x][k][kk] == -1) {
		int x1, x2;
		if (x == n)
			dp[x][k][kk] = dfs(x - 1, false, k) + dfs(x - 1, true, k);
		else {
			dp[x][k][kk] = y ? dfs(x - 1, true, k) : dfs(x - 1, false, k);
		}
	}
	return dp[x][k][kk];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
	}
	init();
	printf("%d", dfs(n));
}
