#include <cstdio>
#define ll long long

const int maxn = 1005;
ll dp[maxn][maxn];

int isZhi[maxn];
inline bool judgeZhi(int x) {
	if (!isZhi[x]) {
		isZhi[x] = -1;
		if (x >= 2) {
			isZhi[x] = 1;
			for (int c = 2; c * c <= x; c++) {
				if (x % c == 0) {
					isZhi[x] = -1;
					break;
				}
			}
		}
	}
	return isZhi[x] == -1 ? false : true;
}

ll dfs(int x, int y = 2) {
	if (!dp[x][y]) {
		ll data = 0;
		if (x < y)
			return 0;
		if (judgeZhi(x))
			data++;
		for (int c = y; c < x; c++) {
			if (judgeZhi(c))
				data += dfs(x - c, c);
		}
		dp[x][y] = data;
	}
	return dp[x][y];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	// freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	printf("%lld\n", dfs(n));
	return 0;
}
