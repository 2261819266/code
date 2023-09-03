#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int mod = 1e9 + 7;

int n, m;

int qpow(int x, int y) {
	int res = 1;
	for (; y; y >>= 1, x = (LL)x * x % mod)
		if (y & 1) res = (LL)res * x % mod;
	return res;
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (m == n - 1) {
		LL ans = (LL)n * qpow(2, n - 1) % mod;
		for (int len = 2; len <= n; ++len) ans += (LL)(n - len + 1) * qpow(2, n - 2) % mod;
		printf("%lld\n", ans % mod);
	}
	return 0;
}
