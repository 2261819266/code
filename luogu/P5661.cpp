#include <cstdio>
#define ll long long

struct Node {
	ll t, p;
	bool k;
};

const int maxn = 1e5 + 8;
struct queue {
	Node a[maxn];
	ll f = 0, b = 0, sum = 0;
	void push(const Node &x) {
		a[b++] = x;
		sum += x.p;
	}

	void pop() { sum -= a[f++].p; } 

	Node front() { return a[f]; }

	Node back() { return a[b]; }

	bool size() { return b - f; }
} q;

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll k, p, t;
		scanf("%lld%lld%lld", &k, &p, &t);
		ans += p;
		if (k == 0) q.push((Node) {t, p, true});
		else {
			while (q.size() && q.front().t + 45 < t) {
				q.pop();
			}
			for (int i = q.f; i < q.b; i++) {
				if (q.a[i].k && q.a[i].p >= p) {
					q.a[i].k = false;
					ans -= p;
					break;
				}
			}
		}
	}
	printf("%lld\n", ans);
}
