#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
const ll mod = 998244353;
int T, n, m, a[N][N], id, sum[N][N];
ll c, f, ansc, ansf, cnt[N][N], msum[N];
char s[N][N];
void work() {
	int lef, rig; ansc = ansf = 0;
	scanf("%d%d%lld%lld", &n, &m, &c, &f);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j ++)
			a[i][j] = s[i][j] - 48, 
			sum[i][j] = sum[i][j - 1] + a[i][j];
	}
	for(int i = 1; i <= m; i ++) a[n + 1][i] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) {
			int l = 0, r = m - j + 1;
			while(l < r) {
				int mid = (l + r + 1) / 2;
				if(sum[i][j + mid - 1] - sum[i][j - 1] == 0)
					l = mid;
				else r = mid - 1;
			}
			cnt[i][j] = l;
		}
	for(int i = 1; i <= m; i ++) {
		lef = rig = 0;
		for(int j = 1; j <= n + 1; j ++)
			if(!a[j][i]) {
				if(!lef) lef = rig = j;
				else ++ rig;
			} else {
				if(rig - lef + 1 < 3) {
					lef = rig = 0;
					continue;
				}
				msum[lef - 1] = 0;
				for(int k = lef; k <= rig; k ++)
					msum[k] = msum[k - 1] + cnt[k][i] - 1;
				for(int k = lef; k < rig; k ++)
					ansc += (cnt[k][i] - 1) * (((msum[rig] - msum[k + 1]) % mod + mod) % mod),
					ansc %= mod;
				lef = rig = 0;
			}
	}
	cout << ansc * c << ' ';
	for(int i = 1; i <= m; i ++) {
		lef = rig = 0;
		for(int j = 1; j <= n + 1; j ++)
			if(!a[j][i]) {
				if(!lef) lef = rig = j;
				else ++ rig;
			} else {
				if(rig - lef + 1 < 3) {
					lef = rig = 0;
					continue;
				}
				msum[lef - 1] = 0;
				for(int k = lef; k <= rig; k ++)
					msum[k] = msum[k - 1] + (cnt[k][i] - 1) * (rig - k);
				for(int k = lef; k < rig; k ++)
					ansf += (cnt[k][i] - 1) * (((msum[rig] - msum[k + 1]) % mod + mod) % mod),
					ansf %= mod;
				lef = rig = 0;
			}
	}
	cout << ansf * f << '\n';
	return;
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while(T --) work();
	return 0;
}
