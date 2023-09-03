#include <cstdio>

const int maxn = 5e5 + 8;

int n, a[maxn];
int lowbit(int x) { return x & -x; }

int query(int x) {
	int res = 0;
	for (; x; x -= lowbit(x)) res += a[x];
	return res;
}

int modify(int x, int d) {
	for (; x <= n; x += lowbit(x)) a[x] += d;
	return d;
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		modify(i, x);
	}
	for (int i = 0; i < m; i++) {
		int k, x, y;
		scanf("%d%d%d", &k, &x, &y);
		k == 1 ? modify(x, y) : printf("%d\n", query(y) - query(x - 1));
	}
}