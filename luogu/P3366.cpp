#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e3 + 8;
// const int maxm = 100;

int a[maxn][maxn], n, m, dis[maxn];
bool b[maxn];

void read() {
	scanf("%d%d", &n, &m);
	memset(dis, 0x7f, sizeof(dis));
	memset(a, 0x7f, sizeof(a));
	// init();
	for (int c = 1; c <= m; c++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = a[v][u] = std::min(w, a[u][v]);
	}
}

int solve() {
	int ans;
	ans = 0;
	dis[1] = 0;
	for (int c = 1; c <= n; c++) {
		int k = 0;
		for (int d = 1; d <= n; d++) {
			if (!b[d] && dis[d] < dis[k])
				k = d;
		}
		b[k] = true;
		ans += dis[k];
		for (int d = 1; d <= n; d++) {
			if (!b[d] && a[k][d] < dis[d])
				dis[d] = a[k][d];
		}
	}
	return ans;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	read();
	int x = solve();
	x > 0x70000000 || x < 0 ? printf("orz") : printf("%d", x);
	return 0;
}