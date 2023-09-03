#include <algorithm>
#include <cstdio>

const int maxn = 100005, maxw = 100005;
int w[maxn], v[maxn], dp[maxw], n, W;

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = W; j > 0; j--) {
			dp[j] = std::max(dp[j], w[i] > j ? 0 : dp[j - w[i]] + v[i]);
		}
	}
	printf("%d", dp[W]);
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", &W);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", w + i, v + i);
	}
	solve();
}
