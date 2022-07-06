#include <algorithm>
#include <cstdio>
#include <cstring>
#define White 'w'
#define Red 'r'
#define Blue 'b'
#define max(a) ans = std::max(ans, a);
#define f(i, j) (a[i] == a[j] || a[j] == White)

const int maxn = 1e4;
char a[maxn], *p = a;
int n, ans;

void fk(int &x, int k) {
	if (a[x] == White)
		x += k, fk(x, k);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", a);
	sprintf(a + n, "%s", a);
	n *= 2;
	for (int i = 0, j, k; i < n; i++) {
		int kk = i;
		fk(kk, -1);
		for (j = kk; j >= 0 && f(kk, j); j--)
			;
		kk = i + 1;
		fk(kk, -1);
		for (k = kk; k < n && f(kk, k); k++)
			;
		max(k - j - 1);
	}
	printf("%d", std::min(ans, n / 2));
	return 0;
}
