#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

int n, q;
int a[250001], b[250001];

signed main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> n >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		int s = 0;
		for (int i = l; i <= r; i++)
			for (int j = i; j <= r; j++) {
				int maxa = 0, maxb = 0;
				for (int k = i; k <= j; k++)
					maxa = max(maxa, a[k]), maxb = max(maxb, b[k]);
				s += maxa * maxb;
			}
		cout << s << endl;
	}
	return 0;
}

