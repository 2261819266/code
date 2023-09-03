#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
const int N = 1100;
ll T, n, m, c, f, a[N][N], ansc, ansf, id;
ll dl[N][N], dh[N][N], dc[N][N];

int main() {
  freopen("plant.in", "r", stdin);
  freopen("plant.out", "w", stdout);
	scanf("%lld %lld", &T, &id);
	while(T--) {
		scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
//		cout << n << m << c << f;
		memset(dl, 0, sizeof(dl));
		memset(dh, 0, sizeof(dh));
		memset(dc, 0, sizeof(dc));
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%1lld", &a[i][j]);
		for(int i = n; i; --i) {
			for(int j = m; j; --j) {
				if(a[i][j]) continue;
				dl[i][j] = 1 + dl[i][j + 1];
			}
		}
		for(int i = n; i; --i) {
			for(int j = m; j; --j) {
				if(a[i][j]) continue;
				dh[i][j] = 1 + dh[i + 1][j];
				dc[i][j] = dl[i][j] + dc[i + 1][j];
				dc[i][j] %= Mod;
			}
		}
//		for(int i = 1; i <= n; ++i) {
//			for(int j = 1; j <= m; ++j) {
//				cout << a[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		for(int i = 1; i <= n; ++i) {
//			for(int j = 1; j <= m; ++j) {
//				cout << dl[i][j] << ' ';
//			}
//			cout << endl;
//		}
		for(int j = 1; j < m; ++j) {
			for(int i = n - 2; i > 0; --i) {
				if(dh[i][j] < 3) continue;
				ansc += dl[i][j + 1] * (dc[i + 2][j] - dh[i + 2][j]) % Mod;
				ansc %= Mod;
			}
			ll sum = 0;
			for(int i = n - 3; i > 0; --i) {
				if(a[i][j]) {
					sum = 0;
					continue;
				}
				if(dh[i][j] < 4) continue;
				sum += (dl[i + 2][j] - 1) * (dh[i + 2][j] - 1) % Mod;
				sum %= Mod;
				ansf += (dl[i][j] - 1) * sum % Mod;
				ansf %= Mod;
			}
		}
	  printf("%lld %lld", ansc * c, ansf * f);
	}

	return 0;
}

