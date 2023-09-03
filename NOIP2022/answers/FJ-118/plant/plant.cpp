#include <bits/stdc++.h>
const int N = 1e3, Mod = 998244353;
void inc(int &x, int y) { (x += y) >= Mod and (x -= Mod); }
int n, m, c, f, nxty[N + 10][N + 10], nxtx[N + 10][N + 10];
char a[N + 10][N + 10];
void clr() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		a[i][j] = 0, nxtx[i][j] = nxty[i][j] = 0;
}
void work() {
	scanf("%d%d%d%d", &n, &m, &c, &f);
	for (int i = 1; i <= n; i++) scanf(" %s", a[i] + 1);
	for (int i = 1; i <= n; i++) for (int j = m; j; j--) {
		if (a[i][j] == '1') nxty[i][j] = j;
		else nxty[i][j] = j == m ? m + 1 : nxty[i][j + 1];
	}
	for (int i = n; i; i--) for (int j = 1; j <= m; j++) {
		if (a[i][j] == '1') nxtx[i][j] = i;
		else nxtx[i][j] = i == n ? n + 1 : nxtx[i + 1][j];
	}
	int ansc = 0, ansf = 0;
	for (int j = 1; j <= m; j++)
		for (int i = 1, cnt = 0; i <= n; i++) {
			if (a[i][j] == '1') { cnt = 0; continue; }
			inc(ansc, 1ll * cnt * (nxty[i][j] - j - 1) % Mod);
			inc(ansf, 1ll * cnt * (nxty[i][j] - j - 1) % Mod * (nxtx[i][j] - i - 1) % Mod);
			if (i > 1 and a[i - 1][j] != '1') inc(cnt, nxty[i - 1][j] - j - 1);
		}
	printf("%d %d\n", c * ansc, f * ansf);
	clr();
}
int main(int _, char **ch) {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	for (scanf("%d%*d", &_); _--;) work();
	return 0;
}

