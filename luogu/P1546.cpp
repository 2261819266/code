#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 105;
int a[maxn][maxn], dis[maxn];
bool b[maxn];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	memset(b, true, sizeof(b));
	memset(dis, 0x10, sizeof(dis));
	for (int c = 1; c <= n; c++) {
		for (int d = 1; d <= n; d++) {
			scanf("%d", &a[c][d]);
			// a[c][d] == 0 ? a[c][d] = 0x10000000 : 0;
		}
	}
	int ans = 0;
	dis[1] = 0;
	for (int c = 1; c <= n; c++) {
		int k = 0;
		for (int d = 1; d <= n; d++) {
			if (b[d] && dis[d] < dis[k])
				k = d;
		}
		ans += dis[k];
		b[c] = false;
		for (int d = 1; d <= n; d++) {
			dis[d] = std::min(dis[d], a[k][d]);
		}
	}
	printf("%d", ans);
	return 0;
}
