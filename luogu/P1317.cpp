#include <cstdio>

const int maxn = 10500;
int a[maxn], n, ans;
bool k;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", &a[0]);
	for (int c = 1; c < n; c++) {
		scanf("%d", &a[c]);
		if (a[c] < a[c - 1])
			k = true;
		if (a[c] > a[c - 1] && k)
			ans++, k = false;
	}
	printf("%d", ans);
}