#include <cstdio>
#include <algorithm>
#define forx(x, l, r) for (int x = l; x < r; x++)
#define forn(x) forx (x, 1, n + 1)

using std::max;

const int maxn = 15;
int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	int x, y, k = 1;
	while (x != 0 || y != 0 | k != 0) {
		scanf("%d%d%d", &x, &y, &k);
		a[x][y] = k;
	}
	forn(i) {
		forn(j) {
			forn(k) {
				forn(l) {
					dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]), max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) + a[i][j] + a[k][l];
					if (i == k && j == l) dp[i][j][k][l] -= a[i][j];
				}
			}
		}
	}
	printf("%d", dp[n][n][n][n]);
	return 0;
}
