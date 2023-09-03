#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i(l);i<=int(r);++i)
#define per(i,l,r) for(int i(l); i >= int(r); i--)
int rd() {
	int x = 0, f = 0; char ch = getchar();
	while (ch < '0' || ch > '9') (ch == '-') && (f = 1), ch = getchar();
	while (ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	return f ? -x : x;
}
const int N = 3e5+10;
int n, a[N], b[N], st[N][20][2];
int query(int l, int r, int op) {
	int k = log2(r-l+1);
	return std::max(st[l][k][op], st[r-(1<<k)+1][k][op]);
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int _; _ = rd(), n = rd();
	rep(i, 1, n) a[i] = rd(), st[i][0][0] = a[i];
	rep(i, 1, n) b[i] = rd(), st[i][0][1] = b[i];
	rep(j, 1, 19) for (int i = 1; i+(1<<j)-1 <= n; ++i) {
		st[i][j][0] = std::max(st[i][j-1][0], st[i+(1<<(j-1))][j-1][0]);
		st[i][j][1] = std::max(st[i][j-1][1], st[i+(1<<(j-1))][j-1][1]);
	}
	int Q; scanf("%d", &Q);
	rep(i, 1, Q) {
		int l, r; l = rd(), r = rd();
		ll ans = 0;
		rep(p, l, r) rep(q, p, r) {
			int mx1, mx2;
//			if (p == q) mx1 = a[p], mx2 = a[q];
			mx1 = query(p, q, 0), mx2 = query(p, q, 1);
//			printf("%d %d\n", mx1, mx2);
			ans = (ans+1ll*mx1*mx2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
