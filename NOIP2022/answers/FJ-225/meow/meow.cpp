#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i(l);i<=int(r);++i)
#define per(i,l,r) for(int i(l); i >= int(r); i--)
const int N = 1010;
int n, m, k, a[N];
std::deque<int> q[2];
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m) scanf("%d", &a[i]);
	q[0].push_back(a[1]);
	rep(i, 2, m) {
		if ((int) q[0].size() == 0) {
			q[0].push_back(a[i]);
			continue;
		}
		if ((int) q[0].size() <= k) {
			int it = q[0].back();
			if (it == a[i]) {
				q[0].pop_back();
				printf("%d %d\n", 1, 1);
			} else {
				q[0].push_back(a[i]);
			}
		} else {
			if ((int) q[1].size() == 0) {
					q[1].push_back(a[i]);
					continue;
				}
			if (a[i] == q[0].front()) {
				q[0].pop_front();
				printf("%d %d %d\n", 1, 1, 2);
			} else {
				int it = q[1].back();
				if (it == a[i]) {
					q[1].pop_back();
					printf("%d %d\n", 1, 1);
				} else {
					q[1].push_back(a[i]);
				}
			}
		}
	}
}
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int _; scanf("%d", &_);
	while (_--) {
		solve();
	}
	return 0;
}
