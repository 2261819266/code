#include <bits/stdc++.h>

#define Register_int using
#define AK namespace
#define NOIP std

Register_int AK NOIP;

// Register_int AK NOIP !!!!!!

/*

NOIP 2022 

I'm cjld, aka Register_int

I use 30min to AC T1!!! 

*/

typedef long long ll;

const int MAXN = 1e3 + 10;
const int mod = 998244353;

int t, n, m, c, f;

char s[MAXN][MAXN];

int r[MAXN][MAXN], d[MAXN][MAXN];

ll a[MAXN], sum[MAXN]; int tot;

ll ansc, ansf;

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	for (scanf("%d%*d", &t); t--;) {
		scanf("%d%d%d%d", &n, &m, &c, &f), ansc = ansf = 0;
		for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		for (int i = 1, pre; i <= n; i++) {
			pre = m + 1;
			for (int j = m; j; j--) s[i][j] == '1' && (pre = j), r[i][j] = pre;
		}
		for (int j = 1, pre; j <= m; j++) {
			pre = n + 1;
			for (int i = n; i; i--) s[i][j] == '1' && (pre = i), d[i][j] = pre;
		}
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i = d[i][j] + 1) {
				while (d[i][j] - i < 3 && d[i][j] + 1 <= n) i = d[i][j] + 1;
				tot = 0;
				for (int k = i; k < d[i][j]; k++) a[++tot] = r[k][j] - j - 1;
				for (int k = 1; k <= tot; k++) sum[k] = (sum[k - 1] + a[k]) % mod;
				for (int k = 1; k < tot - 1; k++) ansc = (ansc + a[k] * (sum[tot] - sum[k + 1] + mod) % mod) % mod;
				for (int k = 1; k <= tot; k++) sum[k] = (sum[k - 1] + a[k] * (tot - k) % mod) % mod;
				for (int k = 1; k < tot - 1; k++) ansf = (ansf + a[k] * (sum[tot] - sum[k + 1] + mod) % mod) % mod;
			}
		}
		printf("%lld %lld\n", ansc * c, ansf * f);
	}
}

/*

stCCCCCO %%% zzp hhx cyz wzh %%% CCCCCOrz

hhx AK NOIP!!!!!
zzp can't AK NOIP XD
cyz AK NOIP!!!!!
wzh AK NOIP!!!!!

The god of OIer, hhx
The girl who AKed IOI 24 times
please v me 50pts in NOIP
bless me can get FJ1=
stCCCCCCO %%%% hhx %%%% CCCCCCOrz

*/
