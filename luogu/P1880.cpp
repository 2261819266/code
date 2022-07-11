#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 105;
int n, a[maxn], dp[maxn][maxn];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d", &n);
	f(i, 1, n + 1) scanf("%d", a + i);
	
}