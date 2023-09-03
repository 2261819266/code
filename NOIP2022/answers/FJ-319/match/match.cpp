#include <bits/stdc++.h>

using namespace std;

const int N = 2.5e5 + 5;

int a[2][N], nxt[2][N];
unsigned long long f[3005][3005];
map< pair<int, int>, unsigned long long> M;

signed main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int n;
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[0][i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[1][i]);
	}
	stack<int> S;
	for (int i = n; i; --i) {
		while (!S.empty() && a[0][i] > a[0][S.top()]) {
			S.pop();
		}
		if (!S.empty()) {
			nxt[0][i] = S.top();
		} else {
			nxt[0][i] = n + 1;
		}
		S.push(i);
	}
	while (!S.empty()) {
		S.pop();
	}
	for (int i = n; i; --i) {
		while (!S.empty() && a[1][i] > a[1][S.top()]) {
			S.pop();
		}
		if (!S.empty()) {
			nxt[1][i] = S.top();
		} else {
			nxt[1][i] = n + 1;
		}
		S.push(i);
	}
	if (n <= 3000) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i, now1 = 0, now2 = 0; j >= 1; --j) {
				now1 = max(now1, a[0][j]);
				now2 = max(now2, a[1][j]);
				f[j][i] = f[j + 1][i] + now1 * now2;
			}
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			unsigned long long A = 0;
			for (int i = l; i <= r; ++i) {
				A += f[l][i];
			}
			printf("%llu\n", A);
		}
		return 0;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (M.count(make_pair(l, r))) {
			printf("%llu\n", M[make_pair(l, r)]);
			continue;
		}
		unsigned int long long A = 0;
		for (int i = l; i <= r; ++i) {
			int now = i, mx1 = 0, mx2 = 0;
			while (now <= r) {
				(a[0][now] > mx1) && (mx1 = a[0][now]);
				(a[1][now] > mx2) && (mx2 = a[1][now]);
				int t = min(min(nxt[0][now], nxt[1][now]), r + 1);
				A += (t - now) * mx1 * mx2;
				now = t;
			}
		}
		printf("%llu\n", M[make_pair(l, r)] = A);
	}
	return 0;
}
