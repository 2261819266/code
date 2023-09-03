#include <cstdio>

const int mod = 998244353;

const int N = 1005;

char map[N][N];

int nxt[2][N][N];

void solve() {
 	int n, m, c, f;
 	scanf("%d%d%d%d", &n, &m, &c, &f);
 	for (int i = 1; i <= n; ++i) {
 		scanf("%s", map[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m - 1; j; --j) {
			nxt[0][i][j] = nxt[0][i][j + 1] + 1;
			if (map[i][j + 1] == '1' || map[i][j] == '1') nxt[0][i][j] = 0;  
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = n - 1; i; --i) {
			nxt[1][i][j] = nxt[1][i + 1][j] + 1;
			if (map[i + 1][j] == '1' || map[i][j] == '1') nxt[1][i][j] = 0;
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			printf("%d %d  ", nxt[0][i][j], nxt[1][i][j]);
//		}
//		printf("\n");
//	}
	int ansc = 0, ansf = 0;
	for (int j = 1; j <= m; ++j) {
		int sumc = 0, sumf = 0;
		for (int i = n; i > 1; --i) {
			if (map[i][j] == '1') {
				sumc = sumf = 0;
			}
			ansc = (ansc + (long long)sumc * nxt[0][i - 1][j]) % mod;
			ansf = (ansf + (long long)sumf * nxt[0][i - 1][j]) % mod;
			sumc = (sumc + nxt[0][i][j]) % mod;
			sumf = (sumf + (long long)nxt[0][i][j] * nxt[1][i][j]) % mod;
//			printf("%d %d %d %d %d %d\n", i, j, sumc, sumf, nxt[0][i][j], nxt[1][i][j]);
		}
	}
	printf("%lld %lld\n", (long long)ansc * c % mod, (long long)ansf * f % mod);
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int t, id;
	scanf("%d%d", &t, &id);
	while (t--) solve();
}
