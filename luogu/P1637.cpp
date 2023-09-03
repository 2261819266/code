#include <cstdio>
#include <algorithm>
#define ll long long

const int maxn = 1e5 + 5;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) >> 1;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
	int a[maxn << 2];

	int query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) return a[k];
		if (l > R || L > r) return 0;
		Def
		return query(Ls, L, R) + query(Rs, L, R);
	}

	int add(int k, int l, int r, int i, int x) {
		if (l == r) return a[k] += x;
		Def
		i <= mid ? add(Ls, i, x) : add(Rs, i, x);
		return updata
	}
} s[2];

int a[maxn];
int d[maxn][2];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i]++;
		m = std::max(m, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int j = n - i + 1;
		s[0].add(1, 1, m, a[i], 1);
		s[1].add(1, 1, m, a[j], 1);
		d[i][0] = s[0].query(1, 1, m, 1, a[i] - 1);
		d[j][1] = s[1].query(1, 1, m, a[j] + 1, m);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += d[i][0] * d[i][1];
	}
	printf("%lld", ans);
}
