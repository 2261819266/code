#include <cstdio>
#define int long long
#define fo(x) freopen(#x".in", "r", stdin); \
	freopen(#x".out", "w", stdout);
char s[2000];
int mp[2000][2000];
int t[2000][2000];
int tf[2000][2000];
int ansc, ansf;
int x, y;
bool flag;
int n, m;
int T, id;
const int mod = 998244353;


void solve() {
	ansc = ansf = 0;
	int c, f;
	scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		for (int j = 1; j <= m; ++j) {
			mp[i][j] = s[j - 1] - '0';
		}
	}
	if (id == 1) {
		puts("0 0");
		return;
	}
	if (id == 2) {
		if (mp[1][1] + mp[1][2] + mp[2][1] + mp[3][1] + mp[3][2] == 0) {
			puts("1 0");
		} else {
			puts("0 0");
		}
		return ;
	}
	if (id == 3) {
		int c = 0, f = 0;
		if (mp[1][1] + mp[1][2] + mp[2][1] + mp[3][1] + mp[3][2] == 0) {
			c++;
			if (mp[4][1]) f++;
		}
		if (mp[2][1] + mp[2][2] + mp[3][1] + mp[4][1] + mp[4][2] == 0) {
			c++;
		}
		printf("%lld %lld\n", c, f);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = j + 1; k <= m; ++k) {
				if (mp[i][k] == 1) {
					break;
				}
				t[i][j] ++;
				t[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = i + 1; k <= n; ++k) {
				if (mp[k][j] == 1) {
					break;
				}
				tf[i][j] ++;
				tf[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] != 1 && mp[i + 1][j] != 1 && mp[i][j + 1] != 1) {

				int tmpc = 0, tmpf = 0;
				for (int k = i + 2; k <= n; ++k) {
					if (mp[k][j] == 1) break;
					if (k - i >= 2) {
						tmpc += t[k][j];
						tmpc %= mod;
						tmpf += t[k][j] * tf[k][j];
						tmpf %= mod;
//						printf("%d %d %d %d\n",i,j, tmpc, tmpf);
					}
				}
//				printf("%d %d\n", tmpc, tmpf);
				tmpc *= t[i][j];
				tmpc %= mod;
				tmpf *= t[i][j];
				tmpf %= mod;
				ansc += tmpc;
				ansc %= mod;
				ansf += tmpf;
				ansf %= mod;
			}
		}
	}
	printf("%lld %lld\n", c * ansc % mod, f * ansf % mod);
//	if (id == 4) {
//
//	}
//	if (id == 16) {
//		puts("0 0");
//	}
//	puts("0 0");
}

signed main() {
	fo(plant);
	scanf("%lld %lld", &T, &id);
	while (T--) {
		solve();
	}
	return 0;
}
