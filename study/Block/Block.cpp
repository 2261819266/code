#include <cstdio>
#include <cmath>
#define ll long long

const int maxn = 1e5 + 8;
int map[maxn];
ll a[maxn], lazy[maxn], sum[maxn];

int n, m, len;

void modify(int i, ll x) {
	map[i] = (i - 1) / len + 1;
	sum[map[i]] += x;
}

void add(int l, int r, ll x) {
	int L = map[l], R = map[r];
	if (L == R) {
		for (int i = L; i <= R; i++) a[i] += x, sum[L] += x;
		return;
	}
	
	for (int i = l; map[i] == L; i++) a[i] += x, sum[L] += x;

	for (int i = L + 1; i < R; i++) lazy[i] += x, sum[i] += x * len;

	for (int i = r; map[i] == R; i--) a[i] += x, sum[R] += x;
}

ll query(int l, int r) {
	int L = map[l], R = map[r];
	ll ans = 0;
	if (L == R) {
		for (int i = l; i <= r; i++) ans += a[i] + lazy[L];
		return ans;
	}
	
	for (int i = l; map[i] == L; i++) ans += a[i] + lazy[L];

	for (int i = L + 1; i < R; i++) ans += sum[i];

	for (int i = r; map[i] == R; i--) ans += a[i] + lazy[R];

	return ans;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d", &n, &m);
	len = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		modify(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y, k;
		scanf("%d%d%d", &kk, &x, &y);
		if (kk == 1) 
			scanf("%d", &k), add(x, y, k);
		else 
			printf("%lld\n", query(x, y));
	}
	return 0;
}
