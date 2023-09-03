#include <cstdio>
#include <vector>
#include <algorithm>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define ll unsigned long long 

const int maxn = 3008;
using std::max;

ll mx[2][maxn][maxn], a[2][maxn], ans[maxn][maxn];
int n, q;

void init() {
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				mx[i][j][k] = std::max(mx[i][j][k - 1], a[i][k]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		ans[i][i] = mx[0][i][i] * ans[1][i][i];
//	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i + j <= n; i++) {
			ans[i][i + j] = ans[i][i + j - 1] + ans[i + 1][i + j] - ans[i + 1][i + j - 1] + mx[0][i][i + j] * mx[1][i][i + j];
		}
	}
}

void solve() {
	int t;
	scanf("%d%d",&t, &n);
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	init();
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", ans[l][r]);
	}
}

int main() {
	// fo(match)
	solve();
	return 0;
}

