#include <cstdio>
#define ll long long

const int maxn = 1e0 + 8;

ll a[maxn << 2], b[maxn << 2];
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
#define updata a[k] = a[ls] + a[rs];
#define pushd pushdown(k, l, r);

ll modify(int k, int l, int r, int i, ll x) {
	if (l == r) return a[k] = x;
	Def
	i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
	return updata
}

void pushdown(int k, int l, int r) {
	Def
	a[ls] += b[k] * lm;
	a[rs] += b[k] * rm;
	b[ls] += b[k];
	b[rs] += b[k];
	b[k] = 0;
}

ll query(int k, int l, int r, int L, int R) {
	if (l >= L && r <= R) return a[k];
	if (l > R || L > r) return 0;
	Def pushd
	return query(Ls, L, R) + query(Rs, L, R);
}

ll add(int k, int l, int r, int L, int R, ll x) {
	if (l >= L && r <= R) return a[k] += x * num, b[k] += x;
	if (l > R || L > r) return 0;
	Def pushd
	add(Ls, L, R, x), add(Rs, L, R, x);
	return updata
}

int main() {
	// LOCALfo
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		modify(1, 1, n, i, x);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y;
		ll k;
		scanf("%d%d%d", &kk, &x, &y);
		kk == 1 ? (scanf("%lld", &k), add(1, 1, n, x, y, k)) : printf("%lld\n", query(1, 1, n, x, y));
	}
}