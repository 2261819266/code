#include <cstdio>
#include <algorithm>

const int maxn = 1e4 + 9;

long long ans;
struct node {
	int y, x, z;
	bool operator<(const node &b) { return y < b.y; }
} a[maxn];

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
	int a[maxn << 2], b[maxn << 2];
	void pushup(int k) {
		b[ls] = std::max(b[ls], b[k]);
		b[rs] = std::max(b[rs], b[k]);
	}

	int find(int k, int l, int r, int i) {
		if (l == r) return std::max(a[k], b[k]);
		Def
		pushup(k);
		return i <= mid ? find(Ls, i) : find(Rs, i);
	}

	int modify(int k, int l, int r, int L, int R, int x) {
		if (l >= L && r <= R) return b[k] = x;
		if (l > R || L > r) return 0;
		Def
		pushup(k);
		modify(Ls, L, R, x);
		modify(Rs, L, R, x);
		return updata
	}
} sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].y, &a[i].x, &a[i].z);
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int l = sgt.find(1, 1, maxn, a[i].x), r = sgt.find(1, 1, maxn, a[i].z - 1);
		ans += a[i].y * 2 - l - r;
		sgt.modify(1, 1, maxn, a[i].x, a[i].z - 1, a[i].y);
	}
	printf("%lld", ans);
	return 0;
}
