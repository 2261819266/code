#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define ll long long

const int maxn = 1007, M = 998244353;
ll a[maxn][maxn], r[maxn][maxn], pre[maxn], d[maxn][maxn];
using std::cin;
using std::string;
using std::max;

void solve() {
	int n, m, c, f;
	scanf("%d%d%d%d", &n, &m, &c, &f);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
		}
		for (int j = m - 1; j; j--) {
			if (a[i][j] || a[i][j + 1]) r[i][j] = -a[i][j];
			else r[i][j] = r[i][j + 1] + 1;
		}
//		for (int j = 1; j <= m; j++) {
//			printf("%d\t", r[i][j]);
//		}
//		putchar( 10);
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n - 1; i; i--) {
			if (a[i][j] || a[i + 1][j]) d[i][j] = -a[i][j];
			else d[i][j] = d[i + 1][j] + 1;
		}
		
	}
//	for (int i = 1; i <= n; i++) {
//		
//		for (int j = 1; j <= m; j++) {
//			printf("%d\t", d[i][j]);
//		}
//		putchar(10);
//	}
	ll cans = 0, fans = 0;
	for (int y = 1; y < m; y++) {
		for (int i = n; i; i--) {
			if (r[i][y] < 0) pre[i] = 0;
			else pre[i] = pre[i + 1] + r[i][y];
		}
		for (int x = 1; x <= n; x++) {
			if (r[x][y] <= 0 || r[x + 1][y] < 0) continue;
			cans += r[x][y] * pre[x + 2];
			cans %= M;
		}
		for (int i = n; i; i--) {
			if (r[i][y] < 0) pre[i] = 0;
			else pre[i] = pre[i + 1] + r[i][y] * d[i][y];
		}
		for (int x = 1; x <= n; x++) {
			if (r[x][y] <= 0 || r[x + 1][y] < 0) continue;
			fans += r[x][y] * pre[x + 2];
			fans %= M;
		}
	}
	cans *= c;
	fans *= f;
	printf("%lld %lld\n", cans, fans);
}

#define init(x) memset(x, 0, sizeof(x));

void plant() {
	int t, id;
	scanf("%d%d", &t, &id);
	while (t--) {
		init(a);
		init(r);
		init(pre);
		init(d);
		solve();
	}
}

int main() {
	// fo(plant)
	plant();
	return 0;
}

