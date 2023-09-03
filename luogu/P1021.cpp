#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 18, maxm = 1e4 + 8;

int n, k, a[maxn], ans[maxn], ansx;

int get(int t) {
	int f[maxm];
	for (int i = 1; i < a[t] * n; i++) {
		f[i] = maxm;
	}
	f[0] = 0;
	for (int i = 1; i <= t; i++) {
		for (int j = a[i]; j <= a[i] * n; j++) {
			f[j] = std::min(f[j], f[j - a[i]] + 1);
		}
	}
	for (int i = 1; i <= a[t] * n + 1; i++) {
		if (f[i] > n)
			return i - 1;
	}
	return a[t] * n;
}

void dfs(int *p, int t, int max) {
	if (t > k) {
		int x = get(k);
		if (x > ansx) {
			ansx = x;
			std::copy(a, a + k + 1, ans);
		}
		return;
	}
	for (int i = p[-1]; i <= max + 1; i++) {
		*p = i;
		int x = get(t);
		dfs(p + 1, t + 1, x);
	}
}

void P1021() {
	scanf("%d%d", &n, &k);
	// for (int i = 1; i <= k; i++) {
	// 	scanf("%d", a + i);
	// }
	// printf("%d", get(k));
	// memset(a, -1, sizeof(a));
	a[1] = 1;
	dfs(a + 2, 2, n);
	for (int i = 1; i <= k; i++) {
		printf("%d ", ans[i]);
	}
	printf("\nMAX=%d\n", ansx);
}

int main() {
	// LOCALfo
	P1021();
	// int n, k;
	// scanf("%d%d", &n, &k);

	// for (int i = 1; i <= n; i++) {
	//	 scanf("%d", a + i);
	// }
	// a[n + 1] = -1;
	// for (int i = 0; i < 1e3; i++)
	//	 check(a, k, d);
	// for (int i = 0; ; i++) {
	//	 if (!d[i + 1]) {
	//		 printf("%d", i);
	//		 return 0;
	//	 }
	// }
}