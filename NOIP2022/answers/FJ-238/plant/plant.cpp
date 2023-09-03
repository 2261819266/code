#include <bits/stdc++.h>
const int SZ = 1010, MOD = 998244353;
int T, id, n, m, C, F;
int nxtX[SZ][SZ], nxtY[SZ][SZ], preC[SZ][SZ], preF[SZ][SZ];
int cYMin[SZ], fYMin[SZ];
bool a[SZ][SZ];
bool readBool() {
	char ch;
	while (!isdigit(ch = getchar()));
	return ch == '1';
}
void solve() {
	memset(nxtX, 0x3f, sizeof nxtX);
	memset(nxtY, 0x3f, sizeof nxtY);
	memset(cYMin, 0x3f, sizeof cYMin);
	memset(fYMin, 0x3f, sizeof fYMin);
	memset(a, 1, sizeof a);
	std::cin >> n >> m >> C >> F;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = readBool();
			if (a[i][j] && !(C == 0 && F == 0)) {
				int x = i, y = j;
				while (!a[i][--y] && y > 0) {
					nxtX[i][y] = j;
				}
				while (!a[--x][j] && x > 0) {
					nxtY[x][j] = i;
				}
			}
		}
	}
	if (C == 0 && F == 0) {
		std::cout << "0 0" << std::endl;
		return;
	}
	int ansC = 0, ansF = 0;
	for (int i = n - 2; i > 0; --i) {
		for (int j = m - 1; j > 0; --j) {
			if (a[i][j] || nxtX[i][j] <= j + 1 || nxtY[i][j] <= i + 1) continue;
			int floor = std::min(n, nxtY[i][j] - 1), floor1 = floor;
			int cSum = 0, fSum = 0;
			if (cYMin[j] <= floor) {
				floor = cYMin[j] - 1;
				cSum = preC[cYMin[j]][j];
				fSum = preF[cYMin[j]][j];
			} 
			for (int x = floor; x >= i + 2; --x) {
				cSum += (std::min(m, nxtX[x][j] - 1) - j) % MOD;
				cSum %= MOD;
				preC[x][j] = cSum;
				fSum += (std::min(m, nxtX[x][j] - 1) - j) * (floor1 - x) % MOD;
				fSum %= MOD;
				preF[x][j] = fSum;
			}
			cYMin[j] = i + 2;
			int upSum = std::min(m, nxtX[i][j] - 1) - j;
			ansC += cSum * upSum % MOD;
			ansC %= MOD;
			ansF += fSum * upSum % MOD;
			ansF %= MOD;
		}
	}
	std::cout << C * ansC % MOD << ' ' << F * ansF % MOD << std::endl;
}
int main() {
//	freopen("qwq.out", "r", stdin);
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	std::cin >> T >> id;
	while (T-- > 0) solve();
	return 0;
}
