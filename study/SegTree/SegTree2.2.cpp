#include <cstdio>
#define ll long long

const int maxn = 1e5 + 8;
ll a[maxn];
int n, m, p;

void add(int l, int r, int k) {
	for(int i = l; i <= r; i++) {
		a[i] += k;
		a[i] %= p;
	}
}

void mul(int l, int r, int k) {
	for(int i = l; i <= r; i++) {
		a[i] *= k;
		a[i] %= p;
	}
}

ll query(int l, int r) {
	ll x = 0;
	for(int i = l; i <= r; i++) {
		x += a[i];
		x %= p;
	}
	return x;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out1.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a+i);
	}
	for (int i = 1; i <= m; i++) {
		for (int i = 1; i <= n; i++) 
			printf("%d\t", a[i]);
		printf("\n");
		int kk, x, y, k;
		scanf("%d%d%d", &kk, &x, &y);
		if (kk == 3) {
			printf("%lld\n", query(x, y));
			continue;
		}
		scanf("%d", &k);
		kk == 1 ? mul(x, y, k) : add(x, y, k);
	}
	return 0;
}