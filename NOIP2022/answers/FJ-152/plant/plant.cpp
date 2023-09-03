
#include <bits/stdc++.h>

using namespace std; const int maxn = 1e3 + 5, mod = 998244353; typedef long long ll;

int n, m, c, f;

char a[maxn][maxn];

int dn[maxn][maxn], rt[maxn][maxn];

int A[maxn][maxn], B[maxn][maxn];

inline void solve()
{
	scanf("%d%d%d%d", &n, &m, &c, &f);
//	cerr << n << ' ' << m << ' ' << c << ' ' << f << endl;
	for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		rt[i][m + 1] = 0;
		for (int j = m; j; j--) rt[i][j] = (a[i][j] == '0' ? rt[i][j + 1] + 1 : 0);
	}
	for (int j = 1; j <= m; j++)
	{
		dn[n + 1][j] = 0;
		for (int i = n; i; i--) dn[i][j] = (a[i][j] == '0' ? dn[i + 1][j] + 1 : 0);
	}
//	for (int i = 1; i <= n; i++, cerr << endl) for (int j = 1; j <= m; j++) cerr << rt[i][j] << ' '; cerr << endl;
//	for (int i = 1; i <= n; i++, cerr << endl) for (int j = 1; j <= m; j++) cerr << dn[i][j] << ' '; cerr << endl;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (rt[i][j] >= 2) A[i][j] = rt[i][j] - 1; else A[i][j] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) B[i][j] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		if (i > 1) if ((B[i][j] = B[i - 1][j] + (a[i - 1][j] == '0') * A[i - 2][j]) >= mod) B[i][j] -= mod;
		if (a[i][j] == '1') B[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		if (rt[i][j] >= 2) B[i][j] = (ll)B[i][j] * (rt[i][j] - 1) % mod; else B[i][j] = 0;
	}
//	for (int i = 1; i <= n; i++, cerr << endl) for (int j = 1; j <= m; j++) cerr << A[i][j] << ' '; cerr << endl;
//	for (int i = 1; i <= n; i++, cerr << endl) for (int j = 1; j <= m; j++) cerr << B[i][j] << ' '; cerr << endl;
	int C = 0, D = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if ((C += B[i][j]) >= mod) C -= mod;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (dn[i][j] >= 2) D = (D + (ll)B[i][j] * (dn[i][j] - 1)) % mod;
	printf("%d %d\n", C * c, D * f);
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T, id; scanf("%d%d", &T, &id); while (T--) solve();
}
