#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
const int M = 1e6 + 10;
const ll MOD = 1e9 + 7;
int x[M], y[M];

int n, m;
ll ans = 0;
bool b1[N], b2[M];
int fa[N];

inline int find(int x) {
	return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
}

inline bool check() {
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	for (int i = 1; i <= m; ++ i) {
		if (!b1[n + i]) continue;
		int fx = find(x[i]), fy = find(y[i]);
		fa[fx] = fy;
	}
	int tmp = -1; bool flag = false;
	for (int i = 1; i <= n; ++ i) {
		if (!b1[i]) continue;
//		flag = true;
		if (tmp == -1) tmp = find(i);
		else {
			if (tmp != find(i)) 
				return false;
		}
	}
//	if (!flag) return false;
	return true;
}

inline void dfs1(int now) {
	if (now == n + m + 1) {
		if (check()) 
			ans = (ans + 1ll) % MOD;
		return ; 
	}
	b1[now] = true;
	dfs1(now + 1);
	b1[now] = false;
	dfs1(now + 1);
	
	return ;
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	if (n <= 9 && m <= 11) {
		dfs1(1);
		ans -= (1ll << m);
		while (ans < 0) ans += MOD;
		printf("%lld\n", ans);
	}
	
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4
*/

