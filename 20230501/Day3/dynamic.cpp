#include <cstdio>

const int maxn = 5e3 + 8;
int a[maxn];

int find(int x) {
	if (x == a[x])
		return x;
	return a[x] = find(a[x]);
}

int main() {
#ifndef LOCAL
#define fo(x)                      \
	freopen(#x ".in", "r", stdin); \
	freopen(#x ".out", "w", stdout);
	fo(dynamic)
#endif
	int n,
	m;
	char s[2] = {'N', 'Y'};
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int k, x, y;
		scanf("%d%d%d", &k, &x, &y);
		if (k == 0)
			a[x] = y;
		if (k == 2) {
			printf("%c\n", s[find(x) == find(x)]);
		}
	}
}