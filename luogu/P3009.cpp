#include <cstdio>
#include <cstring>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define ansGetMax(X) (ans = max(X, ans))
#define inf (int)0xfefefefe

const int maxn = 1000000;
int a[maxn], n, dp[maxn];

void init() { memset(dp, 0xfe, sizeof(dp)); }

// int dfs(int x, bool k = false) {
// 	if (x > n)
// 		return 0;
// 	if (dp[x][k] != inf)
// 		return dp[x][k];
// 	if (k) {
// 		return max(dfs(x + 1, true) + a[x], a[x]);
// 	} else {
// 		return max(dfs(x + 1, false), dfs(x + 1, true) + a[x]);
// 	}
// }

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	init();
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
	}
	int ans = dp[1] = a[1];
	for (int c = 2; c <= n; c++) {
		dp[c] = max(dp[c - 1] + a[c], a[c]);
		ansGetMax(dp[c]);
	}
	printf("%d", ans);
}