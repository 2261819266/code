#include <algorithm>
#include <cstdio>
#define ll long long

const int maxn = 1e5 + 5, maxw = 1e7 + 55;
ll w[maxn], v[maxn], dp[maxw], n, m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%lld%lld", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", w + i, v + i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= m; j++) {
			dp[j] = std::max(dp[j - w[i]] + v[i], dp[j]);
		}
	}
	printf("%lld", dp[m]);
	return 0;
}
