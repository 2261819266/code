#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 7, M = 1e6 + 7, K = 6e2 + 7;

struct Answer {
	int op, x, y;
};

vector<Answer> ans;
set<int> s;
deque<int> q[N];

int a[M];
int la[M], lb[M], value[M];
int StackPosition[M], disappeare[M];
int mp[M];
int tmp[K];
bool flag[M];

int T, n, m, k;
int cnta, cntb, tot;

signed main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	
	for (; T; --T) {
		scanf("%d%d%d", &n, &m, &k);
		cnta = 0, cntb = 0, tot = 1;
		ans.clear(), s.clear();
		
		for (int i = 1; i <= m; ++i) {
			scanf("%d", a + i);
			
			if (tmp[a[i]])
				lb[++cntb] = a[i], value[cntb] = tmp[a[i]], tmp[a[i]] = 0;
			else
				q[1].push_back(a[i]), tmp[a[i]] = ++cnta, flag[i] = true;
		}
		
		for (int i = 1; i <= cntb; ++i)
			if (s.lower_bound(value[i]) == s.begin()) {
				q[++tot].clear();
				q[tot].push_back(lb[i]);
				StackPosition[i] = tot, disappeare[value[i]] = tot;
				mp[value[i]] = tot;
				s.insert(value[i]);
			} else {
				int c = *(--s.lower_bound(value[i]));
				s.erase(c);
				q[mp[c]].push_back(lb[i]);
				StackPosition[i] = mp[c], disappeare[value[i]] = mp[c];
				mp[value[i]] = mp[c];
				s.insert(value[i]);
			}
		
		for (int i = 1, j = 0; i <= m; ++i)
			if (flag[i])
				ans.push_back((Answer) {1, 1, 0});
			else
				ans.push_back((Answer) {1, StackPosition[++j], 0});
		
		for (int i = 1; i <= cnta; ++i)
			ans.push_back((Answer) {2, 1, disappeare[i]});
		
		printf("%d\n", ans.size());
		
		for (int i = 0; i < ans.size(); ++i)
			if (ans[i].op == 1)
				printf("1 %d\n", ans[i].x);
			else
				printf("2 %d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}
