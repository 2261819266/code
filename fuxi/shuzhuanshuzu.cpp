// C++ Version
#define MAXN 1000
int t1[MAXN], t2[MAXN], n;

inline int lowbit(int x) { return x & (-x); }

void add(int k, int v) {
	int v1 = k * v;
	while (k <= n) {
		t1[k] += v, t2[k] += v1;
		k += lowbit(k);
	}
}

int getsum(int *t, int k) {
	int ret = 0;
	while (k) {
		ret += t[k];
		k -= lowbit(k);
	}
	return ret;
}

void add1(int l, int r, int v) {
	add(l, v), add(r + 1, -v); // 将区间加差分为两个前缀加
}

long long getsum1(int l, int r) {
	return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) -
		   (getsum(t2, r) - getsum(t2, l - 1));
}
#include <cstdio>
int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d", t1 + c);
	}
	printf("%d", getsum1(1, 5));
}