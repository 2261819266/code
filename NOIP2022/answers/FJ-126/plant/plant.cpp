#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10;
const ll MOD = 998244353;
int T, id;
int n, m;
ll c, f;
char mp[N][N];
int nxt[N][N], las[N][N], cgz[N][N], cnt[N];
ll ansc = 0, ansf = 0;

inline void init() {
	for (int j = 1; j <= m; ++ j)
		for (int i = 1; i <= n; ++ i) {
			if (mp[i][j] == '1') las[i][j] = -1;
			else if (i == 1)  las[i][j] = 1;
			else {
				las[i][j] = ((las[i - 1][j] == -1) ? i : las[i - 1][j]);
			}
		}
	for (int i = 1; i <= n; ++ i) {
		for (int j = m; j >= 1; -- j) {
			if (mp[i][j] == '1') nxt[i][j] = -1;
			else if (j == m) nxt[i][j] = m;
			else {
				nxt[i][j] = ((nxt[i][j + 1] == -1) ? j : nxt[i][j + 1]);
			}
		}
	}
	for (int j = 1; j <= m; ++ j)
		for (int i = n; i >= 1; -- i) {
			if (mp[i][j] == '1') cgz[i][j] = -1;
			else if (i == n) cgz[i][j] = n;
			else {
				cgz[i][j] = ((cgz[i + 1][j] == -1) ? i : cgz[i + 1][j]);
			}
		}
//	for (int i = 1; i <= n; ++ i)
//		for (int j = 1; j <= m; ++ j) {
//			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + mp[i][j];
//		}
	return ;
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d%d", &T, &id);
	while (T --) {
		ansc = ansf = 0ll;
		scanf("%d%d%lld%lld", &n, &m, &c, &f);
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", mp[i] + 1);
		}
		init();
		
		if (c != 0) {
			for (int j = 1; j <= m; ++ j) {
				cnt[0] = 0;
				for (int i = 1; i <= n; ++ i) {
					int posj = nxt[i][j], posi = las[i][j];
					if (posj - j >= 1 && i - posi >= 2) {
						ansc += 1ll * (cnt[i - 2] - cnt[posi - 1]) * 1ll * (posj - j) % MOD;
						ansc %= MOD;
					}
					cnt[i] = (cnt[i - 1] + posj - j) % MOD;
				}
			}	
		}
		
		if (f != 0) {
			for (int j = 1; j <= m; ++ j) {
				cnt[0] = 0;
				for (int i = 1; i <= n; ++ i) {
					int posj = nxt[i][j], posi = las[i][j], dow = cgz[i][j];
					if (posj - j >= 1 && i - posi >= 2 && dow - i >= 1) {
						ansf += (1ll * (cnt[i - 2] - cnt[posi - 1]) * 1ll * (posj - j) % MOD) * 1ll * (dow - i) % MOD;
						ansf %= MOD;
					}
					cnt[i] = (cnt[i - 1] + posj - j) % MOD;
				}
			}	
		}
		
		printf("%lld %lld\n", (ansc * c) % MOD, (ansf * f) % MOD);
	}
	
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
