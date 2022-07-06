#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define STR1 "10"
#define STR2 ".in"
#define STR3 ".out"
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn = 105;
int a[maxn], dp[maxn];

int read() {
	freopen(STR1 STR2, "w", stdout);
	int n;
	srand(time(NULL));
	n = rand() % 3 + 18;
	int k = rand() % 30 + 10;
	printf("%d\n", n);
	for (int c = 1; c <= n; c++) {
		a[c] = a[c - 1] + rand() % k + 1;
		printf("%d ", a[c]);
	}
	memset(dp, -1, sizeof(dp));
	freopen(STR1 STR3, "w", stdout);
	return n;
}

int dfs(int k) {
	if (k == 0)
		return 0;
	if (k == 1)
		return a[1];
	int ans = a[k];
	if (dp[k] == -1)
		for (int c = 1; c < k; c++) {
			ans = max(ans, dfs(c) + dfs(k - c));
		}
	return ans;
}

int main() { printf("%d", dfs(read())); }
