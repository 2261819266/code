#include <cstdio>
#include <iostream>
using namespace std;
int read() {
	int res = 0, w = 1; char chr = getchar();
	while(chr < '0' | chr > '9') { if(chr == '-') w = -1; chr = getchar(); }
	while(chr >= '0' & chr <= '9') res = res * 10 + chr - 48, chr = getchar();
	return res * w;
}
int tra[1000010], trb[1000010], a[250010], b[250010];
void build_a(int x, int l, int r) {
	if(l == r) {
		tra[x] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build_a(x << 1, l, mid);
	build_a(x << 1 | 1, mid + 1, r);
	tra[x] = max(tra[x << 1], tra[x << 1 | 1]);	
}
void build_b(int x, int l, int r) {
	if(l == r) {
		trb[x] = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build_b(x << 1, l, mid);
	build_b(x << 1 | 1, mid + 1, r);
	trb[x] = max(trb[x << 1], trb[x << 1 | 1]);	
}
int query_a(int x, int l, int r, int L, int R) {
	if(L <= l & r <= R) {
		return tra[x];
	}
	int ret = 0, mid = (l + r) >> 1;
	if(L <= mid) ret = max(ret, query_a(x << 1, l, mid, L, R));
	if(R > mid) ret = max(ret, query_a(x << 1 | 1, mid + 1, r, L, R));
	return ret;
}
int query_b(int x, int l, int r, int L, int R) {
	if(L <= l & r <= R) {
		return trb[x];
	}
	int ret = 0, mid = (l + r) >> 1;
	if(L <= mid) ret = max(ret, query_b(x << 1, l, mid, L, R));
	if(R > mid) ret = max(ret, query_b(x << 1 | 1, mid + 1, r, L, R));
	return ret;
}
unsigned long long ans;
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T = read(), n = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	for(int i = 1; i <= n; i ++) b[i] = read();
	int Q = read();
	build_a(1, 1, n);
	build_b(1, 1, n);
	while(Q --) {
		int l = read(), r = read();
		ans = 0;
		for(int q = l; q <= r; q ++)
			for(int p = q; p <= r; p ++) {
				ans += query_a(1, 1, n, q, p) * query_b(1, 1, n, q, p);
			}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

