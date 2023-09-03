#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll Mod = 998244353;
const int N = 1e3 + 7;

ll tmp[N][N];
ll sumc[N][N];
ll resf[N][N], sumf[N][N];
bool a[N][N];

ll c, f, AnsC, AnsF;
int T, id, n, m;

inline bool Read() {
	char c = getchar();
	
	while (c != '0' && c != '1')
		c = getchar();
	
	return c == '1';
}

signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	
	for (; T; --T) {
		scanf("%d%d%lld%lld", &n, &m, &c, &f);
		AnsC = 0, AnsF = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				a[i][j] = Read();
		
		for (int i = 1; i <= n; ++i) {
			ll lst = 0;
			
			for (int j = m; j; --j) {
				if (!a[i][j])
					++lst;
				else
					lst = 0;
				
				tmp[i][j] = lst;
			}
		}
		
		for (int j = 1; j <= m; ++j) {
			ll lst = 0, now = 0;
			
			for (int i = n; i; --i) {
				sumc[i][j] = lst, lst = now;
				
				if (!a[i][j])
					now += tmp[i][j] - 1;
				else
					now = 0;
			}
		}
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (!a[i][j] && !a[i + 1][j])
					AnsC = (AnsC + (tmp[i][j] - 1) * sumc[i][j] % Mod) % Mod;
		
		for (int j = 1; j <= m; ++j) {
			ll lst = 0;
			
			for (int i = n; i; --i)
				if (!a[i][j])
					resf[i][j] = (tmp[i][j] - 1) * lst, ++lst;
				else
					lst = 0;
		}
		
		for (int j = 1; j <= m; ++j) {
			ll lst = 0, now = 0;
			
			for (int i = n; i; --i) {
				sumf[i][j] = lst, lst = now;
				
				if (!a[i][j])
					now += resf[i][j];
				else
					now = 0;
			}
		}
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (!a[i][j] && !a[i + 1][j])
					AnsF = (AnsF + (tmp[i][j] - 1) * sumf[i][j] % Mod) % Mod;
		
		printf("%lld %lld", AnsC * c % Mod, AnsF * f % Mod);
	}
	return 0;
}
