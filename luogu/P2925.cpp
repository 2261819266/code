#include <algorithm>
#include <cstdio>

const int maxn = 1e6 + 5;
int w[maxn], dp[maxn], n, m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--) {
			dp[j] = std::max(dp[j], dp[j - w[i]] + w[i]);
		}
	}
	printf("%d", dp[m]);
	return 0;
}
