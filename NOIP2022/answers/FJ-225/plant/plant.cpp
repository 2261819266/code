#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i(l);i<=int(r);++i)
#define per(i,l,r) for(int i(l); i >= int(r); i--)
const int N=1010;
const int mod = 998244353;
int n, m, a[N][N], b[N][N];
std::vector<int> one[N];
void solve() {
	int C, F; scanf("%d%d%d%d", &n, &m, &C, &F);
	rep(i, 1, n) rep(j, 1, m) scanf("%01d", &a[i][j]);
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (a[i][j] == 1) b[i][j] = b[i][j-1], one[i].push_back(j);
			else b[i][j] = b[i][j-1]+1;
		}
	}
	ll ansc = 0;
	std::vector<std::pair<int, int> > c;
	if (C == 1) {
		rep(p, 1, m-1) {
			int l = 1;
			rep(i, 1, n) {
				if (a[i][p] == 1 && i-l < 3) l = i+1;
				if (a[i][p] == 1 && i-l >= 3) {
					c.push_back(std::make_pair(l, i-1)), l = i+1;
				}
			}
			bool fl = 0;
			rep(i, 1, n) if (a[i][p] == 1) {
				fl = 1;
				break;
			} 
			if (!fl) {
				c.push_back(std::make_pair(1, n));
				goto nyans;
			}
			if (n-l+1 >= 3 && a[n][p] == 0) c.push_back(std::make_pair(l, n));
			nyans:;
			for (auto v : c){
				int l = v.first, r = v.second;
				rep(i, 3, r-l+1) {
					rep(j, 0, i) {
						if (l+j > r || l+j+i-1 > r) break;
						auto it = std::upper_bound(one[l+j].begin(), one[l+j].end(), p);
						auto itt = std::upper_bound(one[l+j+i-1].begin(), one[l+j+i-1].end(), p);
						int t1 = 0, t2 = 0;
						if (it == one[l+j].end()) t1 = m;
						else t1 = *it;
						if (itt == one[l+j+i-1].end()) t2 = m;
						else t2 = *itt;
						if (b[l+j][t1]-b[l+j][p-1] >= 2 && b[l+j+i-1][t2]-b[l+j+i-1][p-1] >= 2) {
	//						printf("id : %d %d %d %d %d %d %d\n", p, l, r, l+j, l+j+i-1, t1, t2);
	//						printf("val: %d %d\n", b[l+j][t1]-b[l+j][p-1], b[l+j+i-1][t2]-b[l+j+i-1][p-1]);
							ansc = (ansc + 1ll*(b[l+j][t1]-b[l+j][p-1]-1)*(b[l+j+i-1][t2]-b[l+j+i-1][p-1]-1)%mod)%mod;
						}
					}
				}
			}
			c.clear();
		}
	}
//	printf("%lld\n", ansc);
	ll ansf = 0; c.clear();
	if (F == 1) {
		rep(p, 1, m-1) {
			int l = 1;
			rep(i, 1, n) {
				if (a[i][p] == 1 && i-l < 4) l = i+1;
				if (a[i][p] == 1 && i-l >= 4) {
					c.push_back(std::make_pair(l, i-1)), l = i+1;
				}
			}
			bool fl = 0;
			rep(i, 1, n) if (a[i][p] == 1) {
				fl = 1;
				break;
			} 
			if (!fl) {
				c.push_back(std::make_pair(1, n));
				goto nylch;
			}
			if (n-l+1 >= 4 && a[n][p] == 0) c.push_back(std::make_pair(l, n));
			nylch:;
			for (auto v : c){
				int l = v.first, r = v.second;
				rep(i, 4, r-l+1) {
					rep(j, 0, i) {
						if (l+j > r) break;
						rep(k, l+j+2, l+j+i-2) {
							if (k > r-1) break;
							auto it = std::upper_bound(one[l+j].begin(), one[l+j].end(), p);
							auto itt = std::upper_bound(one[k].begin(), one[k].end(), p);
							int t1 = 0, t2 = 0;
							if (it == one[l+j].end()) t1 = m;
							else t1 = *it;
							if (itt == one[k].end()) t2 = m;
							else t2 = *itt;
							if (b[l+j][t1]-b[l+j][p-1] >= 2 && b[k][t2]-b[k][p-1] >= 2) {
	//							printf("id : %d %d %d %d %d %d %d %d\n", p, l, r, l+j, l+j+i-2, k, t1, t2);
	//							printf("val: %d %d\n", b[l+j][t1]-b[l+j][p-1], b[k][t2]-b[k][p-1]);
								ansf = (ansf + 1ll*(b[l+j][t1]-b[l+j][p-1]-1)*(b[k][t2]-b[k][p-1]-1)%mod)%mod;
							}
						}
					}
				}
			}
			c.clear();
		}
	}
	printf("%lld %lld\n", 1ll*C*ansc%mod, 1ll*F*ansf%mod);
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int _, id; scanf("%d%d", &_, &id);
	while (_--) {
		solve();
	}
	return 0;
}
