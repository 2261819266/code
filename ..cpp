#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
typedef long long ll;

class SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (r - mid)
	vector<ll> a, b;
public:
	void assign(int n) {
		a.assign(n + 1, 0);
		b.assign(n + 1, 0);
	}

	ll modify(int k, int l, int r, int i, ll x) {
		if (l == r) return a[i] = x;
		i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	void push_down(int k, int l, int r) {
		a[ls] += lm * b[k];
		a[rs] += rm * b[k];
		b[ls] += b[k];
		b[rs] += b[k];
		b[k] = 0;
	}

	ll add(int k, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R) return a[k] += num * x, b[k] += x;
		if (l > R || L > r) return 0;
		push_down(k, l, r);
		add(Ls, L, R, x);
		add(Rs, L, R, x);
		return updata
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) return a[k];
		if (l > R || L > r) return 0;
		push_down(k, l, r);
		return query(Ls, L, R) + query(Rs, L, R);
	}
} a;

void solve() {
	int n, m;
	cin >> n >> m;
	a.assign(n);

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		a.modify(1, 1, n, i, x);
	}
	while (m--) {
		ll k, x, y, z;
		cin >> k >> x >> y;
		if (k == 1) {
			cin >> z;
			a.add(1, 1, n, x, y, z);
		} else {
			cout << a.query(1, 1, n, x, y) << "\n";
		}
	}
}

int main() {
	solve();
	return 0;
}