#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e6 + 5;

int a[M], f[3][N], wh[N];

signed main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &a[i]);
		}
		queue<int> Q;
		for (int i = 1; i <= n; ++i) {
			f[0][i] = f[1][i] = f[2][i] = 0;
			if (i != n) {
				Q.push(i);
			}
		}
		for (int i = 1; i <= k; ++i) {
			wh[i] = 0;
		}
		int now = 1;
		vector< pair<int, pair<int, int> > > tp;
		while (now <= m) {
			if (wh[a[now]]) {
				int x = wh[a[now]];
				if (f[0][x] == a[now] && !f[0][n]) {
					tp.push_back(make_pair(1, make_pair(n, 0)));
					tp.push_back(make_pair(2, make_pair(x, n)));
					if (f[1][x] && !f[2][x]) {
						Q.push(x);
					}
					f[0][x] = f[1][x];
					f[1][x] = f[2][x];
					f[2][x] = 0;
					wh[a[now]] = 0;
					++now;
					continue;
				}
				if (f[0][x] == a[now] && !f[1][x]) {
					tp.push_back(make_pair(1, make_pair(x, 0)));
					f[0][x] = 0;
					wh[a[now]] = 0;
					++now;
					continue;
				}
				if (f[1][x] == a[now] && !f[2][x]) {
					tp.push_back(make_pair(1, make_pair(x, 0)));
					f[1][x] = 0;
					wh[a[now]] = 0;
					Q.push(x);
					++now;
					continue;
				}
				if (f[2][x] == a[now]) {
					tp.push_back(make_pair(1, make_pair(x, 0)));
					f[2][x] = 0;
					wh[a[now]] = 0;
					++now;
					continue;
				}
			}
			if (!Q.empty()) {
				tp.push_back(make_pair(1, make_pair(Q.front(), 0)));
				wh[a[now]] = Q.front();
				if (!f[0][Q.front()]) {
					f[0][Q.front()] = a[now];
				} else {
					f[1][Q.front()] = a[now];
					Q.pop();
				}
				++now;
				continue;
			}
			int flag = rand() % (n - 1) + 1;
			wh[a[now]] = flag;
			if (!f[0][flag]) {
				f[0][flag] = a[now];
			} else if (!f[1][flag]) {
				f[1][flag] = a[now];
			} else {
				f[2][flag] = a[now];
			}
			tp.push_back(make_pair(1, make_pair(flag, 0)));
			++now;
		}
		printf("%d\n", tp.size());
		for (int i = 0; i < tp.size(); ++i) {
			if (tp[i].first == 1) {
				printf("1 %d\n", tp[i].second.first);
			} else {
				printf("2 %d %d\n", tp[i].second.first, tp[i].second.second);
			}
		}
	}
	return 0;
}
