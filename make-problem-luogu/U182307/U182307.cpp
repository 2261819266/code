#include <cstdio>
#include <cstring>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 105;
int a[maxn], dp[maxn];

int read() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++)
		scanf("%d", a + c);
	memset(dp, -1, sizeof(dp));
	return n;
}

int dfs(int k) {
	if (k == 0)
		return 0;
	if (k == 1)
		return a[1];
	int ans = a[k];
	if (dp[k] == -1)
		for (int c = 1; c < k; c++) {
			ans = max(ans, dfs(c) + dfs(k - c));
		}
	return ans;
}

int main() { printf("%d\n", dfs(read())); }