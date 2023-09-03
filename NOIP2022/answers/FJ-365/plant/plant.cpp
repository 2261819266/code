#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;
const ll mod = 998244353;
int T, id, n, m, nxt[N][N], dwn[N][N];
ll ansc, ansf, cc, f; char a[N][N];
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while(T --) {
		scanf("%d%d%lld%lld", &n, &m, &cc, &f);
		ansc = ansf = 0;
		memset(nxt, 0, sizeof nxt);
		memset(dwn, 0, sizeof dwn);
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", a[i] + 1);
			for (int j = m; j; -- j) {
				nxt[i][j] = (a[i][j] - '0' ? 0 : nxt[i][j + 1] + 1);
			}
		}
		for (int i = n; i; -- i) {
			for (int j = 1; j <= m; ++ j) {
				dwn[i][j] = (a[i][j] - '0' ? 0 : dwn[i + 1][j] + 1);
			}
		}
		for (int j = 1; j <= m; ++ j) {
			ll pres = 0, t[2];
			t[0] = t[1] = 0;
			for (int i = 1; i <= n; ++ i) {
				if (a[i][j] == '1') pres = 0, t[0] = t[1] = 0;
				ll nowc = 0;
				pres = (pres + t[i & 1]) % mod;
				t[i & 1] = 0;
				if (nxt[i][j] > 1) {
					nowc = pres * (nxt[i][j] - 1) % mod;
					ansc = (ansc + nowc) % mod;
					ansf = (ansf + nowc * (dwn[i][j] - 1)) % mod;
//					printf("%d %d %lld %lld %lld %lld %lld\n", i, j, ansc, ansf, pres, t[0], t[1]);
//					pres = (pres + t) % mod;
					t[i & 1] = nxt[i][j] - 1;
				}
			}
		}
		printf("%lld %lld\n", (cc * ansc + mod) % mod, (f * ansf + mod) % mod);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
rsy ak ioi
*/
