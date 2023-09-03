#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const int mxn = 2.5e5 + 10;

int n, a[mxn], b[mxn], q;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", b + i);
	scanf("%d", &q);
	for (int l, r; q--;) {
		ULL ans = 0;
		scanf("%d%d", &l, &r);
		for (int al = l; al <= r; ++al) {
			int mxa = a[al], mxb = b[al];
			for (int ar = al; ar <= r; ++ar) {
				mxa = max(mxa, a[ar]);
				mxb = max(mxb, b[ar]);
				ans += mxa * mxb;
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
