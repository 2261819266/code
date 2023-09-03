#include <bits/stdc++.h>

#define Register_int using
#define AK namespace
#define NOIP std

Register_int AK NOIP;

// Register_int AK NOIP !!!!!!
// qian pai dou shou xiao main() bao

typedef unsigned long long ll;

const int MAXN = 2.5e5 + 10;
const int mod = 1e9 + 7;

int t, n, q, l, r;

int a[MAXN], b[MAXN];

int prea[MAXN], preb[MAXN], nxta[MAXN], nxtb[MAXN];

ll d1, d2, ans;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		prea[i] = preb[i] = 1;
		for (int j = i - 1; j; j--) if (a[j] > a[i]) { prea[i] = j + 1; break; }
		for (int j = i - 1; j; j--) if (b[j] > b[i]) { preb[i] = j + 1; break; }
		nxta[i] = nxtb[i] = n;
		for (int j = i + 1; j <= n; j++) if (a[j] > a[i]) { nxta[i] = j - 1; break; }
		for (int j = i + 1; j <= n; j++) if (b[j] > b[i]) { nxtb[i] = j - 1; break; }
	}
	for (scanf("%d", &q); q--;) {
		scanf("%d%d", &l, &r), ans = 0;
		for (int i = l; i <= r; i++) {
			for (int j = max(l, prea[i]); j <= min(r, nxta[i]); j++) {
				if (i > nxtb[j] || i < preb[j]) continue;
				d1 = min(i, j) - max({ l, prea[i], preb[j] }) + 1;
				d2 = min({ r, nxta[i], nxtb[j] }) - max(i, j) + 1;
				ans = (ans + d1 * d2 % mod * a[i] % mod * b[j] % mod) % mod;
			}
		}
		printf("%lld\n", ans);
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
