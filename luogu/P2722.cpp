#include <algorithm>
#include <cstdio>

using std::max;

const int maxn = 10005;
int p[maxn], t[maxn], dp[maxn * maxn];

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, time;
	scanf("%d%d", &time, &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d%d", p + c, t + c);
	}
	for (int c = 1; c <= n; c++) {
		for (int d = t[c]; d <= time; d++) {
			dp[d] = max(dp[d], dp[d - t[c]] + p[c]);
		}
	}
	printf("%d", dp[time]);
}
