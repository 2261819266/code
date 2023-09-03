#include <bits/stdc++.h>
#define TIME clock() / CLOCKS_PER_SEC
using namespace std;
const int N = 1e3 + 5, mod = 998244353;
int n, m, c, f, C, F; 
bool a[N][N];
int r[N][N], d[N][N], s[N];
void solve() {
	cin >> n >> m >> c >> f;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j - 1] == '0') {
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (a[i][j] == 0) {
				r[i][j] = r[i][j + 1] + 1;
			} else {
				r[i][j] = 0;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			if (a[i][j] == 0) {
				d[i][j] = d[i + 1][j] + 1;  
			} else {
				d[i][j] = 0;
			}
		} 
	}
//	cout << "\n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << r[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << d[i][j] << " ";
//		}
//		cout << "\n";
// 	}
//	cout << "\n";
	C = F = 0;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (r[i][j] > 1) {
				s[i] = s[i - 1] + (r[i][j] - 1);
			} else if (r[i][j] == 1) {
				s[i] = s[i - 1];
			} else {
				s[i] = 0;
			}
			int val = 0;
			if (i >= 3) {
				if (a[i][j] == 0 && a[i - 1][j] == 0) {
					val = (val + 1ll * (r[i][j] - 1) * s[i - 2] % mod) % mod;
				}
				C = (C + val) % mod;
				if (d[i][j] > 1) {
					F = (F + 1ll * val * (d[i][j] - 1) % mod) % mod;
				}  
			}
		}
	} 
	cout << c * C << " " << f * F << "\n";
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	int t, id; cin >> t >> id;
	while (t--) solve();
//	cerr << TIME << "ms\n";
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
