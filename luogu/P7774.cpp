#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 15;
int a[maxn], n, m;
bool vis[365];

void dfs(int r = 0) {
	r %= 360;
	if (vis[r])
		return;
	vis[r] = true;
	for (int i = 1; i <= n; i++) {
		dfs(r + a[i]);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	dfs();
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		printf(vis[x] ? "YES\n" : "NO\n");
	}
	return 0;
}
