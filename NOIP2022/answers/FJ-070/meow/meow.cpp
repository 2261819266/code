#include <bits/stdc++.h>

using namespace std;

const int M = 5e5 + 5;

int T, n, m, k;
int a[M];

deque<int> tmp[300 + 5];

int ans[M][5];

bool check() {
	for (int i = 1; i <= n; i++) {
		if (!tmp[i].empty()) {
			return false;
		}
	}
	return true;
}

bool dfs(int op, int st) {
	if (st == m + 1) {
		if (check()) {
			
		for (int i = 1; i <= op; i++) {
			if (ans[i][0] == 1) {
				printf("1 %d\n", ans[i][1]);
			} else {
				printf("2 %d %d\n", ans[i][1], ans[i][2]);
			}
		}
		return true;
		}
		return false;
	}
	for (int i = 1; i <= n; i++) {
		int tag = 0;
		if (!tmp[i].empty() && tmp[i].front() == a[st]) {
			tmp[i].pop_front();
			tag = 1;
		} else {
			tmp[i].push_front(a[st]);
			tag = 2;
		}
		ans[op][0] = 1;
		ans[op][1] = i;
		bool flag = dfs(op + 1, st + 1);
		ans[op][0] = 0;
		ans[op][1] = 0;
		if (tag == 1) {
			tmp[i].push_front(a[st]);
		} else {
			tmp[i].pop_front();
		}
		if (flag) return true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!tmp[i].empty() && !tmp[j].empty() && tmp[i].back() == tmp[j].back()) {
				int t = tmp[i].back();
				tmp[i].pop_back();
				tmp[j].pop_back();
				ans[op][0] = 2;
				ans[op][1] = i;
				ans[op][2] = j;
				bool tag = dfs(op + 1, st);
				ans[op][0] = 0;
				tmp[i].push_back(t);
				tmp[j].push_back(t);
				if (tag) return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &a[i]);
		}
		dfs(1, 1);
	}
	return 0;
}
