#include <cstdio>

const int maxn = 1005, maxm = 1000005;
struct E {
	int u, v;
} e[maxm];
int fa[maxn], n, m;

void init(int n) {
	for (int c = 1; c <= n; c++) {
		fa[c] = c;
	}
}

bool read() {
	scanf("%d", &n);
	if (n == 0)
		return false;
	init(n);
	scanf("%d", &m);
	for (int c = 0; c < m; c++) {
		scanf("%d%d", &e[c].u, &e[c].v);
	}
	return true;
}

int findfa(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = findfa(fa[x]);
}

int solve() {
	for (int c = 0; c < m; c++) {
		if (findfa(e[c].u) != findfa(e[c].v)) {
			fa[fa[e[c].u]] = e[c].v;
		}
	}
	int k = -1;
	for (int c = 1; c <= n; c++) {
		if (findfa(c) == c)
			k++;
	}
	return k;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	while (read())
		printf("%d\n", solve());
	return 0;
}
