#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e3 + 7;

int T, id, n, m, c, f, a[N][N];
int prei[N][N], prej[N][N];

int divi (int x, int y) {
	int l = y, r = m, ans = 0;
	int target = prej[x][y - 1];
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (prej[x][mid] - target == 0) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans - y;
}

int divj (int x, int y) {
	int l = x, r = n, ans = 0;
	int target = prei[y][x - 1];
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (prei[y][mid] - target == 0) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans - x;
}

struct Node {
	int di, dj, dij;
}d[N][N];
int predi[N][N], predj[N][N];
ll predij[N][N];

int main () {
	freopen ("plant.in", "r", stdin);
	freopen ("plant.out", "w", stdout);
	scanf ("%d%d", &T, &id);
	while (T --) {
		scanf ("%d%d%d%d", &n, &m, &c, &f);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				char c;
				cin >> c;
				a[i][j] = int(c - '0');
			}
		}
		memset (prei, 0, sizeof (prei));
		memset (prej, 0, sizeof (prej));
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				prej[i][j] += prej[i][j - 1] + a[i][j];
			}
		}
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= n; j ++) {
				prei[i][j] += prei[i][j - 1] + a[j][i];
			}
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				d[i][j].di = divi (i, j);
				d[i][j].dj = divj (i, j);
				d[i][j].dij = d[i][j].di * d[i][j].dj;
			}
		}
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= n; j ++) {
				predi[i][j] += predi[i][j - 1] + d[j][i].di;
			}
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				predj[i][j] += predj[i][j - 1] + d[i][j].dj;
			}
		}
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= n; j ++) {
				predij[i][j] += predij[i][j - 1] + d[j][i].dij;
			}
		}
		ll vc = 0, vf = 0;
		for (int i = 1; i <= n - 2; i ++) {
			for (int j = 1; j <= m - 1; j ++) {
				if (a[i + 1][j] == 1 || a[i][j] == 1 || a[i][j + 1] == 1) {
					continue;
				}
				int t1 = d[i][j].di;
				int P = predi[j][i + d[i][j].dj] - predi[j][i + 1];
				vc = (vc + P * t1) % mod;
			}
		}
		for (int i = 1; i <= n - 2; i ++) {
			for (int j = 1; j <= m - 1; j ++) {
				if (a[i + 1][j] == 1 || a[i][j] == 1 || a[i][j + 1] == 1) {
					continue;
				}
				int t1 = d[i][j].di;
				ll P = predij[j][i + d[i][j].dj] - predij[j][i + 1];
				vf = (vf + t1 * P) % mod;
			}
		}
		printf ("%lld %lld\n", (vc * c) % mod, (vf * f) % mod);
	}
	return 0;
}
