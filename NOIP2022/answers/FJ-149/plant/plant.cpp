#include <bits/stdc++.h>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

using namespace std; typedef long long ll; typedef unsigned long long ull;
bool St;

const int maxn = 1e3 + 10;
const int mod = 998244353;

void norm(int &x) {
	if (x >= mod) x -= mod;
	else if (x < 0) x += mod;
}

int typ, n, m, C, F, a[maxn][maxn], R[maxn][maxn], D[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
int Ac, Af;
char s[maxn][maxn];

void solve() {
	scanf("%d%d%d%d", &n, &m, &C, &F);
	rep (i, 1, n) scanf("%s", s[i] + 1);
	rep (i, 1, n) rep (j, 1, m) {
		a[i][j] = s[i][j] - '0';
	}
	rep (i, 1, n + 3) {
		a[i][m + 1] = 1;
		fill(R[i], R[i] + m + 2, 0);
		fill(D[i], D[i] + m + 2, 0);
		fill(f[i], f[i] + m + 2, 0);
		fill(g[i], g[i] + m + 2, 0);
	}
	rep (i, n + 1, n + 3) fill(a[i], a[i] + m + 1, 1);
	Ac = Af = 0;

	per (j, m, 1) {
		per (i, n, 1) if (!a[i][j]) {
			R[i][j] = R[i][j + 1] + 1;
			D[i][j] = D[i + 1][j] + 1;
		}
		per (i, n, 1) if (!a[i][j]) {
			if (R[i][j] > 1) {
				norm(f[i][j] += R[i][j] - 1);
				if (D[i][j] > 1) {
					norm(g[i][j] += (ll)(R[i][j] - 1) * (D[i][j] - 1) % mod);
				}
				if (!a[i + 1][j]) {
					norm(Ac += (ll)f[i + 2][j] * (R[i][j] - 1) % mod);
					norm(Af += (ll)g[i + 2][j] * (R[i][j] - 1) % mod);
				}
			}
			norm(f[i][j] += f[i + 1][j]);
			norm(g[i][j] += g[i + 1][j]);
		}
	}
	Ac = (ll)Ac * C % mod, Af = (ll)Af * F % mod;
	printf("%d %d\n", Ac, Af);
}

bool Ed;

int main() {
	fo(plant)
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	int t; scanf("%d%d", &t, &typ);
	while (t--) solve();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

