#include <cstdio>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

int L, n, maxx, minx;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &L, &n);
	for (int c = 0; c < n; c++) {
		int x;
		scanf("%d", &x);
		minx = max(minx, min(x, L + 1 - x));
		maxx = max(maxx, max(x, L + 1 - x));
	}
	printf("%d %d", minx, maxx);
}