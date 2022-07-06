#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 105;
int a[maxn][maxn];
int to[maxn], w[maxn], next[maxn], cnt = 0, head[maxn];

void addEdge(int _u, int _v, int _w) {
	to[_u] = _v;
	w[_u] = _w;
	next[_u] = head[_u];
	head[_u] = _u;
}

int solve(int root, int num) {
	if (a[root][num]) return a[root][num];
	if (!~head[root]) return w[root];
	int d[maxn] = {}, j = 0, ans = 0;
	for (int i = head[root]; ~i; i = next[i], j++) {
		d[j] = solve(to[i], 0);
	}
	std::sort(d, d + j, [](int x, int y) { return w[x] > w[y]; });
	for (int i = 0; i < num; i++) {
		ans += d[i];
	}
	return a[root][num] = ans;
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	for (int i = 1; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addEdge(x, y, z), addEdge(y, x, z);
	}
	// for (int i = 0; ~i; i = next[i]) {
		// printf("%d\n", w[i]);
	// }
}
