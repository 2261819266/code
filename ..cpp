#include <iostream>
#include <vector>

typedef long long ll;

using std::cin;
using std::cout;
using std::vector;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata return a[k] = a[ls] + a[rs];
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (r - mid)
	vector<ll> a, b;
	void assign(int n) {
		a.assign(n << 2, 0);
		b.assign(n << 2, 0);
		// a.reserve(n + 1);
		// b.reserve(n + 1);
	}

	ll modify(int k, int l, int r, int i, ll x) {
		if (l == r) return a[k] = x;
		i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		updata
	}

	void push_down(int k, int l, int r) {
		a[ls] += b[k] * lm;
		a[rs] += b[k] * rm;
		b[ls] += b[k];
		b[rs] += b[k];
		b[k] = 0;
	}

	ll add(int k, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R) return a[k] += x * num, b[k] += x;
		if (l > R || L > r) return 0;
		push_down(k, l, r);
		add(Ls, L, R, x);
		add(Rs, L, R, x);
		updata
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) return a[k];
		if (l > R || L > r) return 0;
		push_down(k, l, r);
		return query(Ls, L, R) + query(Rs, L, R);
	}
};

SegTree a;

int main() {
	int n, m;
	cin >> n >> m;
	a.assign(n + 1);
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		a.modify(1, 1, n, i, x);
	}
	while (m--) {
		ll k, x, y, z;
		cin >> k >> x >> y;
		if (k == 2) {
			cout << a.query(1, 1, n, x, y) << "\n";
		} else {
			cin >> z;
			a.add(1, 1, n, x, y, z);
		}
	}
}