#include <cstdarg>
#include <cstdio>

const int maxn = 10005, M = 1e9 + 7;
int a[maxn];

int f(int n, ...) {
	va_list args;
	va_start(args, n);
	int *arg = new int[n];
}

int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n, ans = 1;
	scanf("%d", &n);
	for (int c = 0; c < n; c++)
		scanf("%d", a + c);
	if (n == 1 || (n == 2 && a[0] != a[1]))
		ans = 1;
	if (n == 2 && a[0] == a[1])
		ans = 2;
	if (n == 3) {
		if ((a[0] ^ a[1]) == a[2])
			ans = 3;
	}
	printf("%d", ans);
}