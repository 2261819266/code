#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 3e5 + 7;
typedef unsigned long long ull;

int T, n, q, a[N], b[N];
#define _max(L, R) (L > R ? L : R)

int main () {
	freopen ("match.in", "r", stdin);
	freopen ("match.out", "w", stdout);
	scanf ("%d%d", &T, &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &b[i]);
	}
	scanf ("%d", &q);
	while (q --) {
		int l, r;
		scanf ("%d%d", &l, &r);
		ull ans = 0;
		for (int p = l; p <= r; p ++) {
			int mx1 = a[p], mx2 = b[p];
			for (int q = p; q <= r; q ++) {
				mx1 = _max (mx1, a[q]);
				mx2 = _max (mx2, b[q]);
				ans += mx1 * mx2;
			}
		}
		printf ("%llu\n", ans);
	}
	return 0;
}
