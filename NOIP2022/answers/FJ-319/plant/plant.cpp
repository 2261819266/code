#include <bits/stdc++.h>

using namespace std;

const int N = 1005, P = 998244353;

int a[N][N], f[N][N], g[N][N], g2[N][N], h[N][N];

signed main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T;
	scanf("%d%*d", &T);
	while (T--) {
		int n, m, _c, _f;
		scanf("%d%d%d%d", &n, &m, &_c, &_f);
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			for (int j = 1; j <= m; ++j) {
				a[i][j] = !(s[j - 1] - '0');
			}
		}
		for (int i = 1; i <= n; ++i) {
			f[i][m + 1] = 0;
			for (int j = m; j >= 1; --j) {
				if (a[i][j]) {
					f[i][j] = f[i][j + 1] + 1;
				} else {
					f[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= m; ++i) {
			g[n + 1][i] = g2[n + 1][i] = h[n + 1][i] = 0;
			for (int j = n; j >= 1; --j) {
				if (a[j][i]) {
					((g[j][i] = g[j + 1][i] + f[j][i] - 1) >= P) && (g[j][i] -= P);
					g2[j][i] = g2[j + 1][i] + 1;
					h[j][i] = (h[j + 1][i] + 1ll * (f[j][i] - 1) * (g2[j][i] - 1)) % P;
				} else {
					g[j][i] = 0;
					g2[j][i] = 0;
					h[j][i] = 0;
				}
			}
		}
		int Ac = 0, Af = 0;
		for (int i = 1; i <= n - 2; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] && a[i + 1][j] && a[i + 2][j]) {
					Ac = (Ac + 1ll * (f[i][j] - 1) * g[i + 2][j]) % P;
					Af = (Af + 1ll * (f[i][j] - 1) * h[i + 2][j]) % P;
				}
			}
		}
		printf("%lld %lld\n", 1ll * Ac * _c % P, 1ll * Af * _f % P);
	}
	return 0;
}
