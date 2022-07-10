#include <cstdio>
#include <cstring>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 105;
struct E {
	int to, w, next;
} edge[maxn << 2];
int head[maxn], cnt, dp[maxn][maxn];
int n, m;

void addEdge(int u, int v, int w) {
	if (!cnt) memset(head, -1, sizeof(head));
	edge[cnt] = {v, w, head[u]};
	head[u] = cnt++;
}

struct Node { int s[2], w[2]; } node[maxn];

void dfs(int r = 1, int fa = 1) {
	for (int i = head[r], j = 0; ~i; i = edge[i].next) {
		int to = edge[i].to;
		if (to - fa) 
			node[r].s[j] = to, node[r].w[j++] = edge[i].w, dfs(to, r);
	}
	if (!node[r].s[0]) return;
	int ls = node[r].s[0], rs = node[r].s[1];
	f(i, 1, n) {
		f(j, 0, i + 1) {
			int k = i - j;
			dp[r][i] = std::max(dp[r][i], dp[ls][j - (j > 0)] + dp[rs][k - (k > 0)] + (j > 0) * node[r].w[0] + (k > 0) * node[r].w[1]);
		}
	}
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addEdge(x, y, z), addEdge(y, x, z);
	}
	dfs();
	// f(i, 1, n + 1) {
	// 	f(j, 1, n) printf("%d ", dp[i][j]);
	// 	printf("\n");
	// }
	printf("%d", dp[1][m]);
}
