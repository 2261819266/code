#include <algorithm>
#include <cstdio>
#define abs(X) ((X) < 0 ? -(X) : (X))

const int maxn(10);
int a[maxn], b[maxn];

int find(int l, int r, int k) {
	if (l >= r)
		return -1;
	if (r - l == 1)
		return abs(k - a[l]);
	int next = (r + l) / 2;
	int x = k - a[next - 1], y = k - a[next];
	return abs(x - y) > 0 ? find(next, r, k) : find(l, next, k);
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m, num = 0;
	scanf("%d%d", &n, &m);
	for (int c = 0; c < n; c++) {
		scanf("%d", &a[c]);
	}
	std::sort(a, a + n);
	for (int c = 0; c < m; c++) {
		scanf("%d", &b[c]);
		num += find(0, n, b[c]);
	}
	printf("%d", num);
}
