#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int mod = 998244353, mxn = 1e3 + 10;

int _, f[mxn][mxn], n, m, enc, enf, mp[mxn][mxn], c[mxn][mxn];
LL cc, cf;

void solve() {
	scanf("%d%d%d%d", &n, &m, &enc, &enf);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char ch;
			scanf(" %c", &ch);
			mp[i][j] = ch ^ 48;
		}
	function<int(int, int)> walk_r = [&](int x, int y) {
		if (y > m || mp[x][y] == 1) return y;
		return f[x][y] = walk_r(x, y + 1) - y - 1, f[x][y] + y + 1;
	};
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m;) j = walk_r(i, j) + 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!mp[i][j]) f[i][j] += f[i - 1][j];
	cc = cf = 0;
	for (int i = 3; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			if (!mp[i][j]) {
				c[i][j] = (LL)(!mp[i - 1][j]) * (!mp[i - 2][j]) * f[i - 2][j] * (f[i][j] - f[i - 1][j]) % mod;
				cf += c[i - 1][j];
				cc += c[i][j];
				(c[i][j] += c[i - 1][j]) %= mod;
			}
	cc %= mod, cf %= mod;
	(cc *= enc) %= mod, (cf *= enf) %= mod;
	printf("%lld %lld\n", cc, cf);
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	for(scanf("%d%*d", &_); _--; memset(f, 0, sizeof f), memset(c, 0, sizeof c)) solve();
	return 0;
}
