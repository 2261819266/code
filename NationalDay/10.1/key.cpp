#include <cstdio>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(X) ((X) < 0 ? -(X) : (X))

const int maxn = 10000;
struct node {
	int x, y;
} a[maxn];

int n, m, k, l, nx = 1, ny = 1, ans;

int main() {
	freopen("key.in", "r", stdin);
	freopen("key.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &k, &l);
	for (int c = 1; c <= l; c++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans += max(abs(x - nx), abs(y - ny)) + 1;
		nx = x;
		ny = y;
		a[c] = (node){x, y};
	}
	printf("%d\n", ans);
	nx = ny = 0;
	for (int c = 1; c <= n; c++) {
		int x = a[c].x, y = a[c].y;
		int kx = nx - x, ky = ny - y;
		
	}
	return 0;
}