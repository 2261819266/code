#include <algorithm>
#include <cstdio>
#include <vector>

int n;
long long s;
using std::vector;
vector<long long> st, sf, dp;


void P2365() {
	scanf("%d%lld", &n, &s);
	st.push_back(0);
	sf.push_back(0);
	dp.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		st.push_back(st.back() + x);
		sf.push_back(sf.back() + y);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 0x7fffffffffffffff;
		for (int j = 0; j < i; j++) {
			dp[i] = std::min(dp[i], dp[j] + st[i] * (sf[i] - sf[j]) + s * (sf[n] - sf[j]));
		}
	}
	printf("%lld", dp[n]);
}

int main() {
	P2365();
	return 0;
}
