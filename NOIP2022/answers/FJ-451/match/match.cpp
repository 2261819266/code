#include <bits/stdc++.h>
using namespace std;
const int N = 250000;
int n, q, a[N][2];
const long long mod = pow(2, 64);
long long ans = 0;

struct Tree {
	int l, r;
	int Min;
} tr[N << 2][2];

void build(int x, int u, int l, int r) {
	tr[u][x].l = l, tr[u][x].r = r;
	if (l == r) {
		tr[u][x].Min = a[l][x];
		return;
	}
	int mid = l + r >> 1;
	build(x, u << 1, l, mid);
	build(x, u << 1 | 1, mid + 1, r);
	tr[u][x].Min = max(tr[u << 1][x].Min, tr[u << 1 | 1][x].Min);
}

int query(int x, int u, int l, int r) {
//	cout << u << ' ' << tr[u][x].l << ' ' << tr[u][x].r << endl;
	if (tr[u][x].l >= l && tr[u][x].r <= r) {
		return tr[u][x].Min;
	}
	int mid = tr[u][x].l + tr[u][x].r >> 1;
	int res = 0;
	if (l <= mid) res = max(res, query(x, u << 1, l, r));
	if (r > mid) res = max(res, query(x, u << 1 | 1, l, r));
	return res;
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T;scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i][0]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i][1]);
	build(0, 1, 1, n); build(1, 1, 1, n);
	scanf("%d", &q);
	while (q--) {
		ans = 0;
		int L, R; scanf("%d%d", &L, &R);
		for (int l = L; l <= R; l++)
			for (int r = L; r <= R; r++) {
				int Maxa, Maxb;
//				cout << l << ' ' << r << endl;
				if (n > 30) Maxa = query(0, 1, l, r), Maxb = query(1, 1, l, r);
				else {
					Maxa = 0, Maxb = 0;
					for (int i = l; i <= r; i++) Maxa = max(Maxa, a[i][0]),  Maxb = max(Maxb, a[i][1]);
				}
				ans = (ans + ((long long)(Maxa * Maxb)) % mod);
//				cout << l << ' ' << r << ' ' << Maxa << ' ' << Maxb << endl;
			}
		printf("%lld\n", ans);
	}
	return 0;
}
