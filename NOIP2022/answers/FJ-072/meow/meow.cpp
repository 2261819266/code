#include <bits/stdc++.h>
const int N = 2e6 + 10;
int T, n, m, k;
int a[N], b[610];
int now, cur;
int st[310][310], h[310], t[310];
int tot;
int op[N << 1], s1[N << 1], s2[N << 1];
int main() {
  freopen("meow1.in", "r", stdin);
  freopen("meow.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> T;
  while (T--) {
  	std::cin >> n >> m >> k;
  	memset(b, 0, sizeof(b));
  	memset(st, 0, sizeof(st));
  	for (int i = 1; i <= n; i++) h[i] = 1, t[i] = 0;
  	now = 0, cur = 1;
  	tot = 0;
  	if (k == 2 * n - 2) {
  		for (int i = 1; i <= m; i++) {
  			std::cin >> a[i];
  			if (!b[a[i]]) {
  				b[a[i]] = cur;
  				st[cur][++t[cur]] = a[i];
  				now++;
  				if (now >= 2) now = 0;
  				op[++tot] = 1;
  				s1[tot] = cur;
				}
				else {
					int id = b[a[i]];
					if (st[id][t[id]] == a[i]) {
						t[id]--;
						op[++tot] = 1;
						s1[tot] = id;
					}
					else {
						op[++tot] = 1;
						s1[tot] = n;
						op[++tot] = 2;
						s1[tot] = n, s2[tot] = id;
						h[id]++;
					}
				}
			}
			std::cout << tot << "\n";
			for (int i = 1; i <= tot; i++) {
				std::cout << op[i] << " " << s1[i];
				if (op[i] == 2) std::cout << " " << s2[i] << "\n";
				else std::cout << "\n";
			}
		}
		else {
			
		}
	}
  return 0;
}

