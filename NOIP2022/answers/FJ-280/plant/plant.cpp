#include <bits/stdc++.h>
using namespace std;
const int N = 1007, Mod = 998244353;
inline void Inc(int &x, int y) { if((x += y) >= Mod) x -= Mod; }
inline int Mul(int x, int y) { return (long long)x * y % Mod; }
inline int Mul(int x, int y, int z) { return Mul(Mul(x, y), z); }
int n, m, c, f, a[N][N], r[N][N], d[N][N], C, F;
void Solve() {
	scanf("%d %d %d %d", &n, &m, &c, &f), C = F = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%1d", &a[i][j]);
	for(int i = 1; i <= n; ++i) r[i][m + 1] = -1;
	for(int i = 1; i <= m; ++i) d[n + 1][i] = -1;
	for(int i = n; i >= 1; --i)
		for(int j = m; j >= 1; --j)
			d[i][j] = a[i][j] ? -1 : d[i + 1][j] + 1,
			r[i][j] = a[i][j] ? -1 : r[i][j + 1] + 1;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 2; k <= d[j][i]; ++k)
				Inc(C, Mul(r[j][i], r[j + k][i])),
				Inc(F, Mul(r[j][i], r[j + k][i], d[j][i] - k));
	printf("%d %d\n", Mul(c, C), Mul(f, F));
}
int main() {
	freopen("plant.in", "r", stdin), freopen("plant.out", "w", stdout);
	int T = 1, id;
	scanf("%d %d", &T, &id);
	while(T--) Solve();
	return 0;
}
