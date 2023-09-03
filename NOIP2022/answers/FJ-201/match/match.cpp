#include <bits/stdc++.h>
#define TIME clock() / CLOCKS_PER_SEC
#define pb emplace_back
#define int long long
using namespace std;
const int N = 3e3 + 5;
int n, q, a[N], b[N], f[N][N], g[N][N];
signed main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t >> n;
	for (int i = 1; i <= n; i++)	
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int l = 1; l <= n; l++) {
		int mA = a[l], mB = b[l];
		for (int r = l; r <= n; r++) {
			mA = max(mA, a[r]);
			mB = max(mB, b[r]);
			f[l][r] = 1ll * mA * mB; 
		}
	}
	for (int i = 1; i <= n; i++)
		g[i][i] = f[i][i];
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			g[i][j] = f[i][j] + g[i + 1][j] + g[i][j - 1] - g[i + 1][j - 1]; 
			if (g[i][j] < 0) {
				g[i][j] = -g[i][j];
			}
		}
	}
	cin >> q;
	while (q--) {
		int l, r; 
		cin >> l >> r;
		cout << g[l][r] << "\n";
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
