#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define ll long long

inline int rand(int start, int last) { return rand() % (last - start) + start; }

const int maxn = 1005;
int n, m, a[maxn][maxn], times = 0;
int dp[maxn][maxn];

int dfs(int x, int y) {
	times++;
	if (x > n || y > m)
		return 0x7fffffff;
	if (x == n && y == m)
		return a[x][y];
	if (dp[x][y] == 0)
		dp[x][y] = min(dfs(x + 1, y), dfs(x, y + 1)) + a[x][y];
	return dp[x][y];
}

void make(int x, int y, int z) {
	int k = x > 3 ? 1 : 0;
	char x1 = x % 10 + 48, x2 = x / 10 + 48;
	char str1[30] = {x2, x1, 0};
	char str2[30] = {x2, x1, 0};
	freopen(strcat(str1, ".in"), "w", stdout);
	n = rand(y, z), m = rand(y, z);
	printf("%d %d\n", n, m);
	for (int c = 1; c <= n; c++) {
		for (int d = 1; d <= m; d++) {
			a[c][d] = rand(1, k ? 10000 : 10);
			printf("%d ", a[c][d]);
		}
		printf("\n");
	}
	freopen(strcat(str2, ".out"), "w", stdout);
	memset(dp, 0, sizeof(dp));
	printf("%d\n", dfs(1, 1));
}

void read() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int c = 1; c <= n; c++) {
		for (int d = 1; d <= m; d++) {
			scanf("%d", &a[c][d]);
		}
	}
}

int main() {
	srand(time(NULL));
	FILE *fin = fopen("E:\\code\\in.in", "r");
	for (int c = 1; c <= 10; c++) {
		int y, z;
		fscanf(fin, "%d%d", &y, &z);
		make(c, y, z);
	}
	// printf("%d\n%lf", times, (double)clock());
}
