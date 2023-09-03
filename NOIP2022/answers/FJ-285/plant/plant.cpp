#include <bits/stdc++.h>
using namespace std;
bool ST;
const int M = 1100;
typedef long long ll;
const ll P = 998244353;
int T, id, n, m, c, f;
ll ansC, ansF;
bool a[M][M];
ll R[M][M], D[M][M], S[M][M];
char tmp[M];
bool ED;
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &c, &f), ansC = ansF = 0;
		memset(a, 0, sizeof(a)), memset(R, 0, sizeof(R)), memset(D, 0, sizeof(D)), memset(S, 0, sizeof(S));
		for (int i = 1; i <= n; i++) {
			scanf("%s", tmp + 1);
			for (int j = 1; j <= m; j++) a[i][j] = tmp[j] == '0';
		}
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--) R[i][j] = a[i][j] ? R[i][j + 1] + 1 : 0;
		for (int j = 1; j <= m; j++)
			for (int i = n; i >= 1; i--) D[i][j] = a[i][j] ? D[i + 1][j] + 1 : 0;
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i++)
				if (a[i][j]) S[i][j] = S[i - 1][j] + (R[i][j] ? R[i][j] - 1 : 0);
				else S[i][j] = 0;
		for (int i = 3; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				if (a[i - 1][j]) {
					ll tansC = S[i - 2][j] * (R[i][j] ? R[i][j] - 1 : 0) % P;
					ll tansF = tansC * (D[i][j] ? D[i][j] - 1 : 0) % P;
					ansC = (ansC + tansC) % P, ansF = (ansF + tansF) % P;
				}
		printf("%lld %lld\n", ansC * c, ansF * f);
	}
	return 0;
}
