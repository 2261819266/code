#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 105 * 4;
int n, a[maxn], dp[maxn][maxn][2], s[maxn];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d", &n);
	f(i, 1, n + 1) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	f(i, n + 1, n * 2 + 1) a[i] = a[i - n], s[i] = s[i - 1] + a[i];
	f(i, 1, n) {
		f(l, 1, n * 2) {
			int r = l + i;
			dp[l][r][0] = 0x3fffffff;
			f(k, l, r) {
				dp[l][r][0] = std::min(dp[l][r][0], s[r] - s[l - 1] + dp[l][k][0] + dp[k + 1][r][0]);
				dp[l][r][1] = std::max(dp[l][r][1], s[r] - s[l - 1] + dp[l][k][1] + dp[k + 1][r][1]);
			}
		}
	}
	int ans[2] = {0x3fffffff, 0};
	f(i, 1, n + 1) {
		ans[0] = std::min(ans[0], dp[i][i + n - 1][0]);
		ans[1] = std::max(ans[1], dp[i][i + n - 1][1]);
	}
	printf("%d\n%d\n", ans[0], ans[1]);
}