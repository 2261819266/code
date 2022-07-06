#include <cstdio>
#include <cmath>
#define ll long long

const int maxn = 1e7 + 8;

// 每个节点所在的区块编号
int map[maxn];

// a为每个数的数据 实际每个数为(a[i] + lazy[map[i]])
// sum为这个区块的实际和
ll a[maxn], lazy[maxn], sum[maxn];

// len为每块的长度 (最后一块不一定为整块)
int n, m, len;

// 区间修改
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

// 区间求和
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

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d", &n, &m);
	len = sqrt(n);
	for (int i = 1; i <= n; i++) {
		// scanf("%lld", a + i);
		map[i] = (i - 1) / len + 1;
		// sum[map[i]] += a[i];
	}
	for (int i = 0; i < m; i++) {
		int k, l, r;
		scanf("%d%d", &k, &l);
		if (k == 0) scanf("%d", &r), add(l, r, 1);
		else printf("%lld\n", a[l] + lazy[map[l]]);
	}
	return 0;
}
