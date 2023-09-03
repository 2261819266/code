#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

typedef long long ll;
const int N = 1010;
const ll MOD = 998244353;
int n, m, cv, fv, nxt[N][N], a[N][N];
ll f[N][N], s[N][N], g[N][N], ans1, ans2, h[N][N];
char str[N];
// dont forget % MOD	

void init() {
	memset(nxt, 0, sizeof(nxt));
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	memset(s, 0, sizeof(s));
	ans1 = ans2 = 0;
}

void solve() {
	init();
	scanf("%d%d%d%d", &n, &m, &cv, &fv);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j ++) a[i][j] = str[j] - '0';
		a[i][m + 1] = 1;
		for (int j = m; j >= 1; j --) nxt[i][j] = a[i][j + 1] ? j + 1 : nxt[i][j + 1];
		for (int j = 1; j <= m; j ++) f[i][j] = std::max(0, nxt[i][j] - j - 1);
	} 		
	for (int j = 1; j <= m; j ++) for (int i = 1; i <= n; i ++) s[i][j] = (s[i - 1][j] + f[i][j]) % MOD;
	for (int j = 1; j <= m; j ++) {
		for (int i = 1, lst = 0; i <= n; i ++) {
			if (a[i][j]) { lst = i; continue; }
			if (i - 2 > lst) g[i][j] = (s[i - 2][j] - s[lst][j] + MOD) % MOD * f[i][j] % MOD;
		}
	}
	for (int j = 1; j <= m; j ++) {
		for (int i = n, lst = n + 1; i >= 1; i --) {
			if (a[i][j]) { lst = i; continue; }
			h[i][j] = g[i][j] * (lst - (i + 1)) % MOD;
		}
	}
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) ans1 = (ans1 + g[i][j]) % MOD, ans2 = (ans2 + h[i][j]) % MOD;
	printf("%lld %lld\n", ans1 * cv % MOD, ans2 * fv % MOD);
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T; scanf("%d%*d", &T);
	while (T --) solve();
	return 0;
}
