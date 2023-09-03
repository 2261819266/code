#include <bits/stdc++.h>
using namespace std;
bool ST;
const int mod = 998244353;
const int N = 1011;
inline int ADD (int a, int b) { if((a += b) >= mod) a -= mod; return a; }
inline int MNS (int a, int b) { if((a -= b) < 0) a += mod; return a; } 
inline int MUL (int a, int b) { return 1ll * a * b % mod; }
bool a[N][N];
int rt[N][N], dn[N][N], rtdn[N][N];
int srt[N][N], srtdn[N][N];
inline void init() {
	memset(a, 0, sizeof(a));
	memset(rt, 0, sizeof(rt));
	memset(dn, 0, sizeof(dn));
	memset(rtdn, 0, sizeof(rtdn));
	memset(srt, 0, sizeof(srt));
	memset(srtdn, 0, sizeof(srtdn));
}
inline void rdln (int x) {
	char c = getchar(); int i = 0;
	while(c < '0') c = getchar();
	while(c >= '0') a[x][++i] = c ^ '0', c = getchar();
}
int n, m;
inline void init_rt () {
	for(int i = 1; i <= n; i++) {
		a[i][m + 1] = 1;
		for(int j = m; j >= 1; j--) {
			if(a[i][j + 1] || a[i][j]) rt[i][j] = 0;
			else rt[i][j] = rt[i][j + 1] + 1;
		}
	}
}
inline void init_dn () {
	for(int j = 1; j <= m; j++) a[n + 1][j] = 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= m; j++) {
			if(a[i + 1][j] || a[i][j]) dn[i][j] = 0;
			else dn[i][j] = dn[i + 1][j] + 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			rtdn[i][j] = MUL(rt[i][j], dn[i][j]);
		}
	}
}
inline void init_sum () {
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= m; j++) {
			srt[i][j] = ADD(srt[i + 1][j], rt[i][j]);
			srtdn[i][j] = ADD(srtdn[i + 1][j], rtdn[i][j]);
		}
	}
}
inline void print () {
	printf("rtdn:\n");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", rtdn[i][j]);
		} printf("\n");
	} printf("\n");
}
int ansc, ansf;
inline void work (int c, int f) {
	ansc = ansf = 0;
	for(int i = 1; i <= n - 2; i++) {
		for(int j = 1; j <= m; j++) {
			int l = i + 2, r = i + dn[i][j];
			if(r < l) continue;
			ansc = ADD(ansc, MUL(rt[i][j], MNS(srt[l][j], srt[r + 1][j])));
			ansf = ADD(ansf, MUL(rt[i][j], MNS(srtdn[l][j], srtdn[r + 1][j])));
		}
	}
	printf("%d %d\n", ansc * c, ansf * f);
}
bool ED;
int main () {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
//	cerr << ((&ED) - (&ST)) / 1024.0 / 1024.0 << endl; // \le 512 MiB 
	int Tgb, id; scanf("%d%d", &Tgb, &id); while(Tgb--) {
		int c, f; scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i++) rdln(i);
		init_rt(); init_dn(); init_sum();
		work(c, f);
	}
	return 0;
}
		// n m ²»Ð´·´ 
