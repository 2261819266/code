#include <algorithm>
#include <cstdio>
using std::sort;
#define abs(X) ((X) < 0 ? -(X) : (X))

const int maxn = 1000000;
int a[maxn], add[maxn];

int *cope(int *_x, const int *_y, int n) {
	for (int c = 0; c < n; c++)
		_x[c] = _y[c];
	return _x;
}

int findMiddle(int x) {
	int *b = new int;
	cope(b, add, x);
	sort(b, b + x);
	int y = b[x / 2];
	// delete b;
	return x;
}

int swap(int *x, int *y, int z, int k) {
	if (*y <= k)
		if (*x < *y) {
		}
	return z;
}

int main() {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int c = 0; c < n; c++)
		scanf("%d", a + c), add[a[c]] = c;
	for (int c = 1; c <= n; c++) {
		if (c == 1) {
			printf("0 ");
			continue;
		}
		long long ans = 0;
		int x = findMiddle(c);
		for (int d = 1; d < x; d++) {
			ans += abs(add[d] - add[x]) - 1;
			if (add[d] > add[x])
				ans++;
		}
		for (int d = x + 1; d <= c; d++) {
			ans += abs(add[d] - add[x]) - 1;

			if (add[d] < add[x])
				ans++;
		}
		printf("%d ", ans);
	}
}