#include <cstdio>

typedef long long ll;
const ll MOD = 1e9 + 7;
int head[N], nxt[N * 2]

int main() {
	int n, m; scanf("%d%d", &n, &m);
	printf("%lld\n", (1ll * n * (n + 1) / 2) % MOD);
	return 0;
}
