#include <cstdio>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 1005;
int a[maxn], dp[maxn][maxn];

inline int f(int x) {
	if (!a[x])
		for (int c = 1; c < x; c++) {
			if (x % c == 0)
				a[x] += c;
		}
	return a[x];
}

int dfs(int x, int y) {
	if (x > y)
		return 0;
	if (!dp[x][y]) {
		int xx = dfs(x + 1, y), yy = dfs(x + 1, y - x) + f(x);
		dp[x][y] = max(xx, yy);
	}
	return dp[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	printf("%d", dfs(1, n));
}