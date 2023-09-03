#include <bits/stdc++.h>
using namespace std;

#define N 1005
int n, m, T, id, c, f;
char mmap[N][N];
int rights[N][N], down[N][N], lastans[N][N], now[N], p[N], sum[N][N];
long long ansc, ansf;
#define mod 998244353

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d %d", &T, &id);
	while(T --) {
		memset(rights, 0, sizeof(rights));
		memset(down, 0, sizeof(down));
		memset(lastans, 0, sizeof(lastans));
		memset(mmap, 0, sizeof(mmap));
		memset(now, 0, sizeof(now));
		memset(sum, 0, sizeof(sum));
		memset(p, 0, sizeof(p));
		ansc = 0, ansf = 0;
		scanf("%d %d %d %d", &n, &m, &c, &f);
		if(!c && !f) {puts("0"); continue;}
		for (int i = 1; i <= n; ++ i) cin >> mmap[i] + 1;
//		for (int i = n; i >= 1; -- i)
//			for (int j = m; j >= 1; -- j) {
//				rights[i][j] = (mmap[i][j] == '1' ? 0 : rights[i][j + 1] + 1);
//				down[i][j] = (mmap[i][j] == '1' ? 0 : down[i + 1][j] + 1);
//			}
//		for (int i = 1; i < n - 1; ++ i) {
//			for (int j = 1; j < m; ++ j) {
//				if(rights[i][j] <= 1) continue;
//				for (int k = i + 2; k <= min(n, down[i][j] + i - 1); ++ k) {
////					if(!C[k - i].first) C[k - i].first = C[k - i].second = 1;
//					int l = C[k - i].first, r = C[k - i].second;
//					int L = rights[i][j] - 1, R = rights[k][j] - 1;
//					if(L <= 1 || R <= 1) continue;
//					if(!l) {
//						ansc += L * R;
//						C[k - i].first = max(l, L);
//						C[k - i].second = max(r, R);
//						ansc %= mod;
//						cout << i << " " << j << " " << k << " " << ansc << endl;
//						continue;
//					}
//					if(L > l && R <= r) ansc += (L - l) * R;
//					else if(R > r && L <= l) ansc += (R - r) * L;
//					else if(L > l && R > r) ansc += (L - l) * R + (R - r) * L - (L - l) * (R - r);
//					ansc %= mod;
//					C[k - i].first = max(l, L);
//					C[k - i].second = max(r, R);
//					cout << i << " " << j << " " << k << " " << ansc << endl;
//				}
//			}
//		}
//		for (int i = 1; i <= m; ++ i) now[i] = 1;
		for (int i = n; i >= 1; -- i)
			for (int j = m; j >= 1; -- j) {
				rights[i][j] = (mmap[i][j] == '1' ? 0 : rights[i][j + 1] + 1);
				down[i][j] = (mmap[i][j] == '1' ? 0 : down[i + 1][j] + 1);
			}
		for (int i = n; i >= 1; -- i) {
			for (int j = 1; j <= m; ++ j) {
				if(!rights[i][j]) now[j] = 0, lastans[i][j] = 0, p[j] = 0, sum[i][j] = 0;
				else {
					lastans[i][j] = now[j];
					now[j] += rights[i][j] - 1;
					if(p[j] > 1)sum[i][j] = (p[j] - 1) * (rights[i + 1][j] - 1) + sum[i + 1][j];
					p[j] ++;
				}
//				cout << i << " " << j << " " << rights[i][j] << " " << sum[i][j] << " " << p[j] << endl;
			}
		}
//		return 0;
//			puts("");
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				if(rights[i][j] <= 1) continue;
				if(down[i][j] <= 2) continue;
				ansc += lastans[i + 1][j] * (rights[i][j] - 1);
				ansc %= mod;
//				cout << i << " " << j << " " << lastans[i + 1][j] << " " << ansc << endl;
				if(down[i][j] <= 3) continue;
				ansf += sum[i][j] * (rights[i][j] - 1);
				ansf %= mod;
			}
		}
		printf("%lld %lld\n", (ansc * c) % mod, (ansf * f) % mod);
	}
}
/*
3 0
4 3 1 1
001
010
000
000

6 6 1 1
000010
011000
000110
010000
011000
000000

16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111

*/
