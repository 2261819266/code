#include <cstdio>

const int maxn = 5e5 + 8;

int n, a[maxn];
int lowbit(int x) { return x & -x; }

int find(int x) { return a[x] - a[x - 1];}

int modify(int l, int r, int x) { return a[l] += x, a[r + 1] -= x; }

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		modify(i, i, x);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y, k;
		scanf("%d%d", &kk, &x);
		kk == 1 ? scanf("%d%d", &y, &k), modify(x, y, k) : printf("%d\n", find(x));
	}
}