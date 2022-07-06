#include <cstdio>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 105;
int n, m, a[maxn][maxn], b[maxn][maxn];

int dfs(int x, int y) {
	if (b[x][y]) return b[x][y];
	bool kup = a[x][y] < a[x - 1][y];
	bool kdown = a[x][y] < a[x + 1][y];
	bool kleft = a[x][y] < a[x][y - 1];
	bool kright = a[x][y] < a[x][y + 1];

	if (!(kup || kdown || kleft || kright))
		return b[x][y] = 1;

	if (kup)
		b[x][y] = max(b[x][y], dfs(x - 1, y) + 1);

	if (kdown)
		b[x][y] = max(b[x][y], dfs(x + 1, y) + 1);

	if (kleft)
		b[x][y] = max(b[x][y], dfs(x, y - 1) + 1);

	if (kright)
		b[x][y] = max(b[x][y], dfs(x, y + 1) + 1);

	return b[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);

	for (int c = 1; c <= n; c++)
		for (int d = 1; d <= m; d++)
			scanf("%d", &a[c][d]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int s = dfs(i, j);
			ans = max(ans, s);
		}
	}
	
	printf("%d", ans);
}