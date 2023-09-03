#include <cstdio>
#include <cmath>
#define ll long long

const int maxn = 1e7 + 8;
ll a[maxn], b[maxn], c[maxn], s[maxn];
int map[maxn];

int n, m;
ll p = 0x7fffffffffffffff, len;

#define Def int L = map[l], R = map[r];
#define k1 (L == R)
#define for0 for (int i = l; i <= r; i++)
#define for1 for (int i = l; map[i] == L; i++)
#define for2 for (int i = L + 1; i < R; i++)
#define for3 for (int i = r; map[i] == R; i--)
#define mo(x, k, y) (x = ((x) k (y)) % p)
#define updataadd mo(a[i], +, x), mo(s[map[i]], +, x);

#define updatamul mo(s[map[i]], +, (x - 1) * a[i]), mo(b[map[i]], *, x),  mo(a[i], *, x);
#define updataans mo(ans, +, (a[i] * c[map[i]]) % p + b[map[i]]);
#define print printf("%d %d %d %d\n", kk, x, y, k); for (int i = 1; i <= n; i++) printf("a[%d] = %d\n", i, a[i] * c[map[i]] + b[map[i]]); printf("\n");

void pass(int x) {
	if (c[x] == 1)
		return;
	for (int i = (x - 1) * len + 1; map[i] == x ; i++) 
		a[i] *= c[x];
	c[x] = 1;
}

void add(int l, int r, ll x) {
	Def
	if k1 {
		for0
			pass(map[i]), updataadd
		return;
	}
	for1
		pass(map[i]), updataadd
	for2
		mo(b[i], +, x), mo(s[i], +, x * len);
	for3
		pass(map[i]), updataadd
}

void mul(int l, int r, ll x) {
	Def
	if k1 {
		for0
			updatamul
		return;
	}
	for1 
		updatamul
	for2
		mo(c[i], *, x), mo(b[i], *, x), mo(s[i], *, x);
	for3
		updatamul
}

ll query(int l, int r) {
	Def
	ll ans = 0;
	if k1 {
		for0
			updataans
		return ans;
	}
	for1
		updataans
	for2
		mo(ans, +, s[i]);
	for3
		updataans
	return ans % p;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d%lld", &n, &m, &p);
	len = sqrt(n);
	for (int i = 0; i <= n; i++)
		c[i] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		map[i] = (i - 1) / len + 1;
		s[map[i]] += a[i];
	}
	for (int i = 0; i < m; i++) {
		for (int i = 0; i < (maxn); i++)
			if (a[i] < 0) return printf("%lld", a[i]);
		int kk, x, y;ll k;
		scanf("%d%d%d", &kk, &x, &y);
		if (kk == 3)
			printf("%lld\n", query(x, y));
		else
			scanf("%lld", &k), kk == 2 ? add(x, y, k) : mul(x, y, k);
		// print
	}
	return 0;
}
