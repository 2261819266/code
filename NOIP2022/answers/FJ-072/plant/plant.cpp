#include <bits/stdc++.h>
const int mod = 998244353;
int T, id;
int n, m, c, f;
char ch[1010][1010];
int nxt[1010][1010], nnxt[1010][1010];
long long s1[1010][1010], s2[1010][1010];
long long inv2;
long long qpow(int a, int b) {
	long long res = 1, x = a;
	while (b) {
		if (b & 1) res = res * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return res;
}
int main() {
  freopen("plant.in", "r", stdin);
  freopen("plant.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> T >> id;
  inv2 = qpow(2, mod - 2);
  while (T--) {
  	std::cin >> n >> m >> c >> f;
  	for (int i = 1; i <= n; i++)
  	  for (int j = 1; j <= m; j++)
  	    std::cin >> ch[i][j];
    for (int i = 1; i <= n; i++) {
    	nxt[i][m] = (ch[i][m] == '1' ? 0 : m);
    	for (int j = m - 1; j >= 1; j--) {
    		if (ch[i][j] == '0') nxt[i][j] = std::max(j, nxt[i][j + 1]);
    		else nxt[i][j] = 0;
			}
		}
		for (int j = 1; j <= m; j++) {
			nnxt[n][j] = (ch[n][j] == '1' ? 0 : n);
			for (int i = n - 1; i >= 1; i--) {
				if (ch[i][j] == '0') nnxt[i][j] = std::max(i, nnxt[i + 1][j]);
				else nnxt[i][j] = 0;
			}
		}
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				if (ch[i][j] == '1') continue;
				s1[i][j] = s1[i - 1][j] + (nxt[i][j] - j);
				s2[i][j] = s2[i - 1][j] + (nxt[i][j] - j) * (nnxt[i][j] - i);
			}
		}
		// Calculate C:
		if (c == 0) std::cout << "0 ";
		else {
			long long res = 0;
			for (int i = 1; i <= n - 2; i++) {
				for (int j = 1; j < m; j++) {
					if (ch[i][j] == '1') continue;
					int l = i + 2, r = nnxt[i][j];
					if (l > r) continue;
//					std::cout << i << " " << j << " " << (nxt[i][j] - j) * (s1[r][j] - s1[l - 1][j]) << "\n";
					res += 1ll * (nxt[i][j] - j) * (s1[r][j] - s1[l - 1][j]) % mod;
					res %= mod;
				}
			}
			std::cout << res << " ";
		}
		
		// Calculate F:
		if (f == 0) std::cout << "0\n";
		else {
			long long res = 0;
			for (int i = 1; i <= n - 3; i++) {
				for (int j = 1; j < m; j++) {
					if (ch[i][j] == '1') continue;
					int l = i + 2, r = nnxt[i][j];
					if (l > r) continue;
//					std::cout << i << " " << j << " " << 1ll * (nxt[i][j] - j) * ((s1[r][j] - s1[l - 1][j]) % mod * (s1[r][j] - s1[l - 1][j]) % mod - (s2[r][j] - s2[l - 1][j]) + mod) % mod * inv2 % mod << "\n";
					res += 1ll * (nxt[i][j] - j) * (s2[r][j] - s2[l - 1][j]) % mod;
					res %= mod;
				}
			}
			std::cout << res << "\n";
		}
	}
  return 0;
}

