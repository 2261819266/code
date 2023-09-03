#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e3 + 10;
const int mod = 998244353;

int t, id;
int n, m, c, f;
int a[maxn][maxn];
int pre[maxn][maxn];
int dwn[maxn][maxn];  
int sum1[maxn][maxn]; 
int sum2[maxn][maxn];
int ans1 = 0, ans2 = 0;

signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	cin >> t >> id; 
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(pre, 0, sizeof(pre));
		memset(dwn, 0, sizeof(dwn));
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		ans1 = ans2 = 0;
		cin >> n >> m >> c >> f;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char ch;
				cin >> ch;
				a[i][j] = ch - '0';
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				if (a[i][j] == 0) {
					pre[i][j] = pre[i][j + 1] + 1;
				} else {
					pre[i][j] = 0;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 0) {
					dwn[i][j] = dwn[i + 1][j] + 1;
				} else {
					dwn[i][j] = 0;
				}
			}
		}
		for (int i = n - 2; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 1 || a[i + 1][j] == 1 || a[i + 2][j] == 1) {
					sum1[i][j] = 0;
				} else {
					sum1[i][j] = (sum1[i + 1][j] + pre[i + 2][j] - 1) % mod;
				}
			}
		}
		for (int i = n - 3; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 1 || a[i + 1][j] == 1 || a[i + 2][j] == 1) {
					sum2[i][j] = 0;
				} else {
					sum2[i][j] = (sum2[i + 1][j] + (dwn[i + 2][j] - 1) * (pre[i + 2][j] - 1) % mod) % mod;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (pre[i][j] > 0)
					ans1 += (pre[i][j] - 1) * sum1[i][j] % mod, ans2 += (pre[i][j] - 1) * sum2[i][j] % mod;
				ans1 %= mod, ans2 %= mod;
			}
		}
		cout << ans1 * c % mod << " " << ans2 * f % mod << endl;
	}
	return 0;
}
