#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const long long P = 998244353LL;

int T, id;
int n, m, c, f;
char mp[N][N];
long long dwn[N][N], rgt[N][N];
long long sum[N];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for (int i = 1; i <= n; i++) {
			scanf("%s", mp[i] + 1);
		}
		memset(dwn, 0, sizeof(dwn));
		memset(rgt, 0, sizeof(rgt));
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (mp[i][j] == '0') {
					rgt[i][j] = rgt[i][j + 1] + 1LL;
					dwn[i][j] = dwn[i + 1][j] + 1LL;
				}
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				cerr << rgt[i][j] << " ";
//			}
//			cerr << endl;
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				cerr << dwn[i][j] << " ";
//			}
//			cerr << endl;
//		}
		long long vc = 0, vf = 0;
		if (n <= 300) {
			for (int y = 1; y <= m; y++) {
				for (int x = 1; x <= n; x++) {
					if (rgt[x][y] >= 2 && dwn[x][y] >= 3) {
						for (int i = x + 2; i <= x + dwn[x][y]; i++) {
							if (rgt[i][y] >= 2) {
								vc = (vc + 1LL * (rgt[x][y] - 1) % P * (rgt[i][y] - 1) % P) % P;
								vf = (vf + 1LL * (rgt[x][y] - 1) % P * (rgt[i][y] - 1) % P * (dwn[i][y] - 1) % P) % P;
							}
						}
					}
				}
			}
		} else {
			for (int y = 1; y <= m; y++) {
				for (int x = 1; x <= n; x = x + (dwn[x][y] == 0 ? 1 : dwn[x][y])) {
					memset(sum, 0, sizeof(sum));
					if (dwn[x][y] >= 3LL && rgt[x][y] >= 2LL) {
//						cerr << x << " " << y << endl;
						for (int i = x; i <= x + dwn[x][y] - 1; i++) {
							sum[i] = (sum[i - 1] + (rgt[i][y] - 1) % P) % P;
						}
						for (int i = x + 2; i <= x + dwn[x][y] - 1; i++) {
							if (rgt[i][y] >= 2) {
								vc = (vc + 1LL * sum[i - 2] % P * (rgt[i][y] - 1) % P) % P;
								vf = (vf + 1LL * sum[i - 2] % P * (rgt[i][y] - 1) % P * (dwn[i][y] - 1) % P) % P;
							}
						}
//						cerr << "sum:" << endl;
//						for (int i = 1; i <= n; i++) {
//							cerr << sum[i] << endl;
//						}
					}
				}
			}
		}
		printf("%lld %lld\n", (c * vc) % P, (f * vf) % P);
	}
	return 0;
}

