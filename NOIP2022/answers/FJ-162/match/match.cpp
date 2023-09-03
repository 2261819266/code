#include <bits/stdc++.h>
#define ul unsigned long long
using namespace std;
const int N = 3e5 + 11;
int n, nxa[N], nxb[N];
ul a[N], b[N];
int stk[N], tp;
inline void init() {
	tp = 0, stk[++tp] = n + 1;
	for(int i = n; i >= 1; i--) {
		while(tp && a[stk[tp]] < a[i]) tp--;
		nxa[i] = stk[tp];
		stk[++tp] = i;
	}
	tp = 0, stk[++tp] = n + 1;
	for(int i = n; i >= 1; i--) {
		while(tp && b[stk[tp]] < b[i]) tp--;
		nxb[i] = stk[tp];
		stk[++tp] = i;
	} 
}
int main () {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T, x, y; scanf("%d%d", &T, &n);
	for(int i = 1; i <= n; i++) scanf("%llu", a + i);
	for(int i = 1; i <= n; i++) scanf("%llu", b + i);
	a[n + 1] = n + 1, b[n + 1] = n + 1;
	init();
	int Qaz; scanf("%d", &Qaz); while(Qaz--) {
		ul ans = 0;
		scanf("%d%d", &x, &y);
		for(int s = x; s <= y; s++) {
			ul mxa = 0, mxb = 0;
			for(int l = s, r; l <= y; l = r) {
				r = min(nxa[l], nxb[l]);
				r = min(r, y + 1);
				mxa = max(mxa, a[l]), mxb = max(mxb, b[l]);
				ans += mxa * mxb * (r - l);
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
//	for(int i = 1; i <= n; i++) printf("%d ", nxa[i]); printf("\n");
//	for(int i = 1; i <= n; i++) printf("%d ", nxb[i]); printf("\n");
//				if(Qaz == 30 - 18) printf("%llu %llu %d %d\n", mxa, mxb, l, r - 1);
