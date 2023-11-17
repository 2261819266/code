#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::max;

class SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = min(a[ls], a[rs]), b[k] = max(a[ls], a[rs]);
	vector<int> a, b;
	const int inf = 0x7fffffff;
	int modify(int k, int l, int r, int i, int x) {
		if (l == r) return a[k] = b[k] = x;
		i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	int geta(int k, int l, int r, int L, int R) {
		if (l > R || L > r) return inf;
		if (l >= L && r <= R) return a[k];
		return min(geta(Ls, L, R), geta(Rs, L, R));
	}

	int getb(int k, int l, int r, int L, int R) {
		if (l > R || L > r) return 0;
		if (l >= L && r <= R) return a[k];
		return min(getb(Ls, L, R), getb(Rs, L, R));
	}
} a;

int main() {
	
}