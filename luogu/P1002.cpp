#include <cstdio>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

const int maxn = 30;
long long a[maxn][maxn];
int n, m, ans;

void addHorse(int horse_x, int horse_y) {
	int x[9] = {-2, -2, -1, -1, 1, 1, 2, 2, 0}, y[9] = {1, -1, 2, -2, 2, -2, 1, -1, 0};
	for (int c = 0; c < 9; c++) {
		a[max(horse_x + x[c], 0)][max(horse_y + y[c], 0)] = -1;
	}
}

long long dfs(int x, int y) {
	if (a[x][y] == -1 || x > n || y > m)
		return 0;
	if (a[x][y] == -2)
		return 1;
	if (a[x][y] == 0)
		a[x][y] = dfs(x, y + 1) + dfs(x + 1, y);
	return a[x][y];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	n++, m++;
	int x, y;
	a[n][m] = -2;
	scanf("%d%d", &x, &y);
	addHorse(x + 1, y + 1);
	printf("%lld", dfs(1, 1));
}