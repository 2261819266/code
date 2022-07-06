#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
long long n, k;
long long a[maxn], dp[maxn][maxn], ans[maxn];

int main() {
	freopen("bread.in", "r", stdin);
	freopen("bread.out", "w", stdout);

	memset(ans, -10000, sizeof(ans));
	memset(dp, -10000, sizeof(dp));

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= k; i++) {
		dp[1][i] = a[i];
	}

	for (int j = 2; j <= n; j++)
		for (int i = 1; i <= k; i++) {
			if (j < i) {
				dp[j][i] = dp[j][j];
			} else
				dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - 1]) + a[j] * i;
			ans[j] = max(dp[j][i], ans[j]);
		}
	cout << ans[n];
}