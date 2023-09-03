#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 100005, maxm = 200005;

struct E {
	int to, next;
} edge[maxm];
int head[maxn], top, dp[maxn], n, m;
bool k[maxn];

inline void init() { memset(head, -1, sizeof(head)); }

inline void addedge(int u, int v) {
	edge[top] = E{v, head[u]};
	head[u] = top++;
}

int dfs(int x = 1) {
	if (!~head[x] && k[x])
		return 1;
	if (!dp[x])
		for (int i = head[x]; ~i; i = edge[i].next) {
			E *p = edge + i;
			dp[x] += dfs(p->to);
		}
	return dp[x];
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    #define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
    fo(chain)
#endif
	init();
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		k[v] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!k[i])
			ans += dfs(i);
	}
	printf("%d", ans);
	return 0;
}
