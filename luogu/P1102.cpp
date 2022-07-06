#include <cstdio>
#include <map>

const int maxn = 10000000;
long long a[maxn], n, x, num;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	std::map<int, int> m;
	scanf("%d%d", &n, &x);
	for (int c = 0; c < n; c++) {
		scanf("%d", &a[c]);
		m[a[c]]++;
	}
	for (int c = 0; c < n; c++) {
		if (m[a[c] + x] > 0)
			num += 1ll * m[a[c] + x];
	}
	printf("%lld", num);
}