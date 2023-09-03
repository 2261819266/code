#include <cstdio>
#include <algorithm>

const int N = 3005;

unsigned long long a[N], b[N], sum[N][N];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int t, n;
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%llu", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%llu", &b[i]);
	}
	for (int i = n; i; --i) {
		unsigned long long ma = a[i], mb = b[i];
		sum[i][i] = ma * mb;
		for (int j = i + 1; j <= n; ++j) {
			ma = std::max(ma, a[j]);
			mb = std::max(mb, b[j]);
			sum[i][j] = sum[i][j - 1] + ma * mb;
		}
	}
	for (int i = n; i; --i) {
		for (int j = i + 1; j <= n; ++j) {
			sum[i][j] += sum[i + 1][j];
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%llu\n", sum[l][r]);
	}
}
