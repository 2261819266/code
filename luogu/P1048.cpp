#include <cstdio>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 105;
int a[maxn], b[maxn], dp[1005], n;

// int dfs(int x, int time) {
// 	if (time <= 0 || x <= 0)
// 		return 0;
// 	if (!dp[x][time]) {
// 		if (a[x] > time) {
// 			return dfs(x - 1, time);
// 		}
// 		int x1 = dfs(x - 1, time), x2 = dfs(x - 1, time - a[x]) + b[x];
// 		dp[x][time] = max(x1, x2);
// 	}
// 	return dp[x][time];
// }\

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int t;
	scanf("%d%d", &t, &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d%d", a + c, b + c);
	}
	for (int c = 1; c <= n; c++) {
		for (int d = t; d >= a[c]; d--) {
			dp[d] = max(dp[d], dp[d - a[c]] + b[c]);
		}
	}
	printf("%d", dp[t]);
	return 0;
}