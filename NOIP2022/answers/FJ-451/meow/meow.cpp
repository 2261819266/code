#include <bits/stdc++.h>
using namespace std;
const int N = 310, M = 2e6 + 10;
deque<int> q[N];

int T;
int n, m, k;
int a[N];
bool flag;

struct A {
	int op;
	int S_1, S_2;
} ans[M << 1];
int abc = 0;
int wz[N], tot = 0;	//可用位置 
int qwerty[N], idx = 0;	//正在用的位置 

void dfs(int x) {
	if (x == n + 1) {
		bool f = 0;
		for (int i = 1; i <= n; i++) if (q[i].size()) f = 1;
		if (!f) {
			flag = 1;
			for (int i = 1; i <= abc; i++) {
				printf("%d ", ans[i].op);
				if (ans[i].op == 1) printf("%d\n", ans[i].S_1);
				else printf("%d %d\n", ans[i].S_1, ans[i].S_2);
			}
		}
		return;
	}
	if (flag) return;
	if (tot != 0) {
		for (int i = 1; i <= idx; i++) if (q[qwerty[i]].front() == a[x]) {
			q[qwerty[i]].pop_front(); ans[++abc] = {1, wz[tot--], 0}; ans[++abc] = {2, qwerty[i], wz[tot+1]};
			dfs(x + 1);
			abc -= 2; tot++;
			if (flag) return;
			q[qwerty[i]].push_front(a[x]);
		}
		q[wz[tot--]].push_back(a[x]);
		ans[++abc] = {1, wz[tot + 1]};
		dfs(x + 1);
		abc--; tot++;
	}
	for (int i = 1; i <= n; i++) {
		if (q[i].back() == a[x]) {
			q[i].pop_back(); ans[++abc] = {1, i};
			dfs(x + 1);
			q[i].push_back(a[x]); abc--;
		}
	}
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i =1 ; i <= n;i++)scanf("%d", &a[i]);
		flag = 0; for (int i = 1; i <= n; i++) wz[++tot] = n - i + 1;
		dfs(1);
	}
}
