#include <cstdio>

int a[1000005];

int find(int l, int r, int k) {
	if (l >= r)
		return -1;
	if (r - l == 1)
		return a[l] == k ? l + 1 : -1;
	int next = (r + l) / 2 - 1;
	if (a[next] >= k)
		return find(l, next + 1, k);
	else
		return find(next + 1, r, k);
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int n, m, x;
	scanf("%d%d", &n, &m);
	for (int c = 0; c < n; c++)
		scanf("%d", &a[c]);
	for (int c = 0; c < m; c++) {
		scanf("%d", &x);
		printf("%d ", find(0, n, x));
	}
}