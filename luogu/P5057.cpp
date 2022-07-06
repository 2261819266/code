#include <cstdio>

const int maxn = 1e5 + 8;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define push pushdown(k, l, r);
	int a[maxn << 2];
	void pushdown(int k, int l, int r) {
		a[ls] ^= a[k];
		a[rs] ^= a[k];
		a[k] = 0;
	}

	int add(int k, int l, int r, int L, int R) {
		if (l > R || L > r) return 0;
		if (l >= L && r <= R) return a[k] ^= 1;
		Def push
		add(Ls, L, R), add(Rs, L, R);
		return 0;
	}

	int ask(int k, int l, int r, int i) {
		if (l == r) return a[k];
		Def push
		return i <= mid ? ask(Ls, i) : ask(Rs, i);
	}
} s;

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int op, l, r;
		scanf("%d%d", &op, &l);
		if (op == 1) {
			scanf("%d", &r);
			s.add(1, 1, n, l, r);
		} else printf("%d\n", s.ask(1, 1, n, l));
	}
}
