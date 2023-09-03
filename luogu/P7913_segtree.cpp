#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 8;

struct Node {
	int a, b;
	bool operator<(const Node &x) { return a < x.a; }
};

Node data[2][maxn];
int n, m[2];

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
	int a[maxn << 2], b[maxn << 2];
	void pushup(int K, int k) { a[k] = data[K][a[ls]].b < data[K][a[rs]].b ? a[ls] : a[rs]; }

	int modify(int K, int k, int l, int r, int x) {
		int res;
		if (l == r) {
			res = a[k];
			a[k] = x;
			b[k]++;
			return res;
		}
		Def
		if (data[K][x].a > data[K][a[ls]].b)
			res = modify(K, Ls, x);
		else
			res = modify(K, Rs, x);
		pushup(K, k);
		b[k] = b[ls] + b[rs];
		return res;
	}

	int query(int K, int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) {
			return b[k];
		}
		if (l > R || L > r) return 0;
		Def
		return query(K, Ls, L, R) + query(K, Rs, L, R);
	}
} sgt[2];

void solve() {
	int ans = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= m[k]; i++) {
			sgt[k].modify(k, 1, 1, m[k], i);
		}
        for (int i = 1; i <= n; i++) {
            printf("%d ", sgt[k].query(k, 1, 1, m[k], 1, i));
        }
        putchar(10);
	}
	for (int i = 0; i <= n; i++) {
		ans = std::max(ans, sgt[0].query(0, 1, 1, m[0], 1, i) + sgt[1].query(1, 1, 1, m[1], 1, n - i));
	}
	printf("%d", ans);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    TEMPLATEfo
#endif
	scanf("%d%d%d", &n, m, m + 1);
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= m[i]; j++) {
			scanf("%d%d", &data[i][j].a, &data[i][j].b);
		}
		std::sort(data[i] + 1, data[i] + m[i] + 1);
	}
	if (n >= m[0] + m[1]) {
		printf("%d\n", m[0] + m[1]);
		return 0;
	}
	solve();
	return 0;
}