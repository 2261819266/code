#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;

int t, n, Q;
int a[maxn];
int b[maxn];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		unsigned long long ans = 0;
		for (int p = l; p <= r; p++) {
			for (int q = p; q <= r; q++) {
				int amax = 0, bmax = 0;
				for (int i = p; i <= q; i++) {
					amax = max(a[i], amax);
					bmax = max(b[i], bmax);
				}
				ans += (unsigned long long) bmax * amax;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

