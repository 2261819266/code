#include <algorithm>
#include <cstdio>

const int maxn = 1e5 + 5;
int a[maxn], dp[maxn], n;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i && a[i] >= 0; j++) {
			if (a[i] >= a[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
	if (dp[n] <= 0)
		puts("Impossible");
	else
		printf("%d\n", dp[n]);
	return 0;
}
