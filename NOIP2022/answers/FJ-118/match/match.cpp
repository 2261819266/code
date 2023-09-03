#include <bits/stdc++.h>
typedef unsigned long long ull;
const int N = 3e3;
int n, a[N + 10], b[N + 10], q;
ull val[N + 10][N + 10];
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int l = 1; l <= n; l++) for (int r = l, mxa = 0, mxb = 0; r <= n; r++) {
		mxa = std::max(mxa, a[r]), mxb = std::max(mxb, b[r]);
		val[l][r] = 1ull * mxa * mxb;
	}
	for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) val[l][r] += val[l][r - 1];
	for (int l = n; l >= 1; l--) for (int r = l; r <= n; r++) val[l][r] += val[l + 1][r];
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%llu\n", val[l][r]);
	}
	return 0;
}

