#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int N = 25e4 + 10;
int n, a[N], b[N], q;
vector<pair<int, ull>> ans[N];
vector<ull> suf[N];
struct SegTree { ull sum, tag; SegTree() { sum = tag = 0; } } t[N * 4];

void apply(int x, ull val) { t[x].sum += val, t[x].tag += val; }
void pushdown(int x) { if (t[x].tag) apply(x * 2, t[x].tag), apply(x * 2 + 1, t[x].tag), t[x].tag = 0; }
void modify(int x, int l, int r, int ql, int qr, ull val) {
	if (ql > qr) return;
	if (ql <= l && r <= qr) return apply(x, val), void();
	int mid = (l + r) >> 1;
	pushdown(x);
	if (ql <= mid) modify(x * 2, l, mid, ql, qr, val);
	if (mid < qr) modify(x * 2 + 1, mid + 1, r, ql, qr, val);
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
} 
ull query(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[x].sum;
	int mid = (l + r) >> 1;
	ull ret = 0;
	if (ql <= mid) ret += query(x * 2, l, mid, ql, qr);
	if (mid < qr) ret += query(x * 2 + 1, mid + 1, r, ql, qr);
	return ret;
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) {
		ans[i].emplace_back(0, 0), suf[i].push_back(0);
		for (int j = i, maxa = 0, maxb = 0; j <= n; j ++) {
			maxa = max(maxa, a[j]), maxb = max(maxb, b[j]);
			ull val = 1ull * maxa * maxb;
			ans[i].emplace_back(j, val), suf[i].push_back(suf[i][suf[i].size() - 1] + val);
		}
	}
	scanf("%d", &q);
	while (q --) {
		int l, r; scanf("%d%d", &l, &r);
		ull res = 0;
		for (int i = l; i <= r; i ++) {
			int k = lower_bound(ans[i].begin(), ans[i].end(), make_pair(r, 0ull)) - ans[i].begin();
			res += suf[i][k];
		}
		printf("%llu\n", res);
	} 
}
