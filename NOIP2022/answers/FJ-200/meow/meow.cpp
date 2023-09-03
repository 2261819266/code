#include <cstdio>
#include <vector>

const int M = 2e6 + 5;

int a[M];

struct B {
	int op, x, y;
} b[M * 2];
int anstot;

const int N = 305;

int c[N * 2];
std::vector<int> d[N];

//bool flag;

//void dfs(int x, int m) {
//	if (flag) return;
//	if (x == m + 1) {
//		bool f = 0;
//		for (int i = 1; i <= 3; ++i) {
//			if (d[i].size()) {
//				f = 1;
//				std::vector<int>.swap(d[i]);
//			}
//		}
//		if (!f) {
//			flag = 1;
//			printf("%d\n", anstot);
//			for (int i = 1; i <= anstot; ++i) {
//				if (b[i].op == 1) printf("1 %d\n", b[i].x);
//				if (b[i].op == 2) printf("2 %d %d\n", b[i].x, b[i].y);
//			}
//		}
//		return;
//	}
//	for (int i = 1; i <= 3; ++i) {
//		b[++anstot] = (B){1, i, 0};
//		if (d[i].size() == 0 || d[i][d[i].size() - 1] != a[x]) d[i].push_back(a[x]);
//		else d[i].pop_back();
//		if (d[i].size()) {
//			for (int j = 1; j <= 3; ++j) {
//				if (i == j) continue;
//				if (!d[j].size()) continue;
//				if (d[i][0] == d[j][0]) {
//					d[i].pop_front();
//					d[j].pop_front();
//					b[++anstot] = (B){2, i, j};
//				}
//			}
//		}
//		dfs(x + 1, m);
//	}
//}
//
//void solve2(int n, int m, int k) {
//	for (int i = 1; i <= m; ++i) {
//		scanf("%d", &a[i]);
//	}
//	flag = 0;
//	dfs(1);
//}

void solve() {
	anstot = 0;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
//	if (n == 3 && m <= 3) solve2(n, m, k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		if (c[a[i]]) {
			if (d[c[a[i]]][0] == a[i]) {
				b[++anstot] = (B){1, n, 0};
				b[++anstot] = (B){2, c[a[i]], n};
				for (int j = 0; j < (int)d[c[a[i]]].size() - 1; ++j) {
					d[c[a[i]]][j] = d[c[a[i]]][j + 1];
				}
				d[c[a[i]]].pop_back();
				c[d[c[a[i]]][0]] = c[a[i]];
				c[a[i]] = 0;
			}
			else {
				b[++anstot] = (B){1, c[a[i]], 0};
				d[c[a[i]]].pop_back();
				c[d[c[a[i]]][d[c[a[i]]].size() - 1]] = c[a[i]];
				c[a[i]] = 0;
			}
		}
		else {
			for (int j = 1; j < n; ++j) {
				if (d[j].size() < 2) {
					b[++anstot] = (B){1, j, 0};
					d[j].push_back(a[i]);
					c[a[i]] = j;
					break;
				}
				if (j == n - 1) {
					b[++anstot] = (B){1, 1, 0};
					c[d[1][d[1].size() - 1]] = 0;
					d[1].push_back(a[i]);
					c[a[i]] = 1;
				}
			}
		}
	}
	printf("%d\n", anstot);
	for (int i = 1; i <= anstot; ++i) {
		if (b[i].op == 1) printf("1 %d\n", b[i].x);
		if (b[i].op == 2) printf("2 %d %d\n", b[i].x, b[i].y);
	}
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
