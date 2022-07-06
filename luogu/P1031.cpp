#include <cstdio>
#define abs(X) ((X) < 0 ? -(X) : (X))

const int maxn = 105;
int a[maxn], n, sum, time;

int f(int x, int y) { return x > y; }

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", a + c);
		sum += a[c];
	}
	sum /= n;
	for (int c = 1; c <= n; c++) {
		a[c] -= sum;
	}
	for (int c = 1; c < n; c++) {
		if (a[c]) {
			a[c + 1] += a[c];
			time++;
		}
	}
	printf("%d", time);
}