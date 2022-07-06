
// https://www.luogu.com.cn/problem/P3865

#include <cstdio>
#include <algorithm>

using std::max;
const int maxn = 1e6 + 9, maxlog = 21;

int n, m, lo[maxn] = {0, 0, 1};
int a[maxn], dp[maxn][maxlog];

void makeLog() {
	for (int i = 3; i <= n; i++) {
		lo[i] = lo[i >> 1] + 1;
	}
}

int f(int l, int r) {
	int size = lo[r - l + 1];
	return max(dp[l][size], dp[r - (1 << size) + 1][size]);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d", &n, &m);
	makeLog();
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int j = 0; j <= lo[n]; j++) {
		for (int i = 1; i <= n; i++) {
			if (j == 0) dp[i][0] = a[i];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", f(l, r));
	}
	return 0;
}
