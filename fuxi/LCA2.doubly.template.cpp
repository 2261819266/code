#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10000005;
struct TREE {
	int pre;
	int to;
} tree[maxn];
int edge_sum, head[maxn];
int N, M, S, U, V, parent[maxn][20], depth[maxn];
void add_edge(int from, int to) {
	edge_sum++;
	tree[edge_sum].pre = head[from];
	tree[edge_sum].to = to;
	head[from] = edge_sum;
}
void dfs(int dep, int cur, int fa) {
	depth[cur] = dep;
	parent[cur][0] = fa;
	for (int i = head[cur]; i != 0; i = tree[i].pre) {
		int u = tree[i].to;
		if (u != fa)
			dfs(dep + 1, u, cur);
	}
}
int query_LCA(int u, int v) {
	if (u == S || v == S)
		return S;
	if (depth[u] < depth[v])
		swap(u, v);
	int num = depth[u] - depth[v];
	for (int k = log(N) / log(2) - 1; k >= 0; k--) {
		if (parent[u][k] != parent[v][k])
			u = parent[u][k], v = parent[v][k];
	}
	return parent[u][0];
}
int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &U, &V);
		add_edge(U, V);
		add_edge(V, U);
	}
	dfs(1, S, S);
	for (int k = 1; (1 << k) <= N; k++)
		for (int v = 1; v <= N; v++)
			parent[v][k] = parent[parent[v][k - 1]][k - 1];
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &U, &V);
		printf("%d\n", query_LCA(U, V));
	}
	return 0;
}