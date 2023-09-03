#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long

const int maxn = 6e3 + 10;

std::vector<int> a[maxn];

int n, m, w[maxn];

void read() {
	scanf("%d%d", &n, &m);
	for (int c = 2; c <= n; c++) {
		int x;
		scanf("%d", &x);
		a[x].push_back(c);
	}
	for (int c = 1; c <= n; c++) {
		scanf("%d", w + c);
	}
}

int dfs(int x, int now) {
	now += w[x];
	int y = 0;
	if (now < 0)
		return 0;
	for (int c = 0; c < a[x].size(); c++) {
		y += std::max(dfs(a[x][c], now) - now, 0);
	}
	return now + y;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	read();
	printf("%d", dfs(1, m));
	return 0;
}
