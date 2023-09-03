#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N = 1005;
int T, id, n, m, p, q;
int ansc, ansf;
int a[N][N];
int f[N][3];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	cin >> T >> id;
	while (T--){
		ansc = ansf = 0;
		cin >> n >> m >> p >> q;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				char c; cin >> c;
				a[i][j] = c - '0';
			}
		for (int i = 1; i <= m; i++)
			f[i][0] = f[i][1] = f[i][2] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = m, k = 0; j >= 1; j--){
				if (a[i][j]){
					k = 0;
					f[j][1] = f[j][2] = 0;
				}else{
					ansf = (ansf + f[j][2]) % mod;
					f[j][2] = (f[j][2] + 1ll * f[j][1] * k) % mod;
					ansc = (ansc + 1ll * f[j][1] * k) % mod;
					f[j][1] = (f[j][1] + f[j][0]) % mod;
					k++;
				}
				f[j][0] = k - (a[i][j] ^ 1);
			}
		cout << ansc * p << ' ' << ansf * q << endl;
	}
	return 0;
}
