#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int t, id, n, m, c, f, d[1002][1002], s[1002][1002], ansc, ansf, ks[1002][1002];
bool a[1002][1002];
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	while (t -- ) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		ansc = ansf = 0;
		memset(ks, 0, sizeof ks);
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= m; j ++ ) scanf("%1d", &a[i][j]), s[i][j] = s[i - 1][j] + a[i][j];
			d[i][m + 1] = - 1;
			for (int j = m; j >= 1; j -- ) d[i][j] = (a[i][j] ? -1 : d[i][j + 1] + 1);
		}
		if (c) for (int x = 1; x <= m; x ++ ) for (int y = 1; y <= n; y ++ ) for (int z = y + 2; z <= n && ! (s[z][x] - s[y - 1][x]); z ++ ) 
			if (d[y][x] && d[z][x]) ansc = (ansc + (ks[z][x] = d[y][x] * d[z][x])) % mod;
		if (f) for (int x = 1; x <= m; x ++ ) for (int y = 1; y <= n; y ++ ) for (int z = y + 1; z <= n && ! (s[z][x] - s[y - 1][x]); z ++ ) 
			ansf = (ansf + ks[y][x]) % mod;
		printf("%d %d\n", ansc, ansf);
	} 
	return 0;
}



