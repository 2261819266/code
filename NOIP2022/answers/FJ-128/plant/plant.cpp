#include <bits/stdc++.h>

const int N = 1e3 + 5, mod = 998244353;

char a[N][N];

int suf[N][N], Next[N][N];	

int T, n, m, c, f, id;

int ansc, ansf, sumc, sumf;

void add(int &x, const int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void dec(int &x, const int y) {
	x -= y;
	if (x < 0) x += mod;
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	scanf("%d%d", &T, &id);
	while (T --) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for (int i = 1; i <= n; ++ i)
			scanf("%s", a[i] + 1);
		
		for (int i = 1; i <= n; ++ i) {
			suf[i][m + 1] = 0;
			for (int j = m; j >= 1; -- j) {
				if (a[i][j] == '0') suf[i][j] = suf[i][j + 1] + 1;
				else suf[i][j] = 0;
			}
		}
	
		for (int j = 1; j <= m; ++ j) {
			Next[n + 1][j] = n + 1;
			for (int i = n; i >= 1; -- i) {
				if (a[i][j] == '1') Next[i][j] = i;
				else Next[i][j] = Next[i + 1][j];
			}
		}
		
		ansc = ansf = 0;
		for (int j = 1; j < m; ++ j) {
			int i0 = 1, i1 = Next[1][j];
			
			while (i0 <= n) {
				sumc = sumf = 0;
				if (i1 - i0 > 2) {
					for (int i = i0 + 2; i < i1; ++ i)
						add(sumc, suf[i][j + 1]);
					
					add(ansc, 1ll * sumc * suf[i0][j + 1] % mod);
					
					for (int i = i0 + 1; i + 1 < i1; ++ i) {
						dec(sumc, suf[i + 1][j + 1]);
						add(ansc, 1ll * sumc * suf[i][j + 1] % mod);
					}
				}
				if (i1 - i0 > 3) {
					for (int i = i0 + 2; i + 1 < i1; ++ i)
						add(sumf, 1ll * suf[i][j + 1] * (i1 - i - 1) % mod);
						
					add(ansf, 1ll * sumf * suf[i0][j + 1] % mod);
					
					for (int i = i0 + 1; i + 3 < i1; ++ i) {
						dec(sumf, 1ll * suf[i + 1][j + 1] * (i1 - i - 2) % mod);
						add(ansf, 1ll * sumf * suf[i][j + 1] % mod);
					}
				}
				
				i0 = i1 + 1;
				i1 = Next[i0][j];
			}
		}
		printf("%d %d\n", ansc * c, ansf * f);
	}
	return 0;
}


