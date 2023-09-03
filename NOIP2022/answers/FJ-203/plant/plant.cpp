//Checkmate, I couldn't lose.
//Farewell, OI. 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define pii pair<int,int>
#define mp make_pair

const ll mod = 998244353;
const int N = 1e3 + 10;

int n,m,c,f;
ll r[N][N],d[N][N];
char s[N][N];

struct BIT {
	int t[N];
	void clear() {
		for (int i = 1;i <= n;++i) t[i] = 0;
	}
	int lowbit(int x) {
		return x & (-x);
	}
	void modify(int x,int v) {
		for (;x <= n;x += lowbit(x)) {
			t[x] += v;
		}
	}
	ll query(int x) {
		ll ans = 0;
		for (;x;x -= lowbit(x)) {
			ans = (ans + t[x]) % mod;
		}
		return ans;
	}
}T1[N],T2[N];

void solve() {
	scanf("%d %d %d %d\n",&n,&m,&c,&f);
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			r[i][j] = d[i][j] = 0;
		}
	}
	for (int i = 1;i <= m;++i) {
		T1[i].clear();T2[i].clear();
	}
	for (int i = 1;i <= n;++i) {
		scanf("%s\n",s[i] + 1);
	}
	for (int j = 1;j <= m;++j) {
		int lst = 1;
		for (int i = 1;i <= n;++i) {
			if (s[i][j] == '1') {
				for (int k = lst;k < i;++k) {
					d[k][j] = i - k - 1;
				}
				lst = i + 1;
			} else {
				continue;
			}
		}
		for (int k = lst;k <= n;++k) {
			d[k][j] = n - k;
		}
	}
	for (int i = 1;i <= n;++i) {
		int lst = 1;
		for (int j = 1;j <= m;++j) {
			if (s[i][j] == '1') {
				//cerr << i << "," << j << " "<< lst << endl;
				for (int k = lst;k < j;++k) {
					r[i][k] = j - k - 1;
					T1[k].modify(i,r[i][k]);
					T2[k].modify(i,r[i][k] * d[i][k] % mod);
				}
				lst = j + 1;
			} else {
				continue;
			}
		}
		for (int k = lst;k <= m;++k) {
			r[i][k] = m - k;
			T1[k].modify(i,r[i][k]);
			T2[k].modify(i,r[i][k] * d[i][k] % mod);
		}
	}
	if (c) {
		ll ans1 = 0;
		for (int x = 1;x <= n;++x) {
			for (int y = 1;y <= m;++y) {
				if (s[x][y] == '0' && d[x][y] >= 2) {
					//cerr << "(" << x << "," << y << "):" << (r[x][y]) << " " << T1[y].query(n) -  T1[y].query(x+1) << endl;
					ans1 = (ans1 + (r[x][y] ) * (T1[y].query(x + d[x][y]) -  T1[y].query(x+1)) % mod) % mod;
				}
			}
		}
		printf("%lld ",ans1);
	} else {
		printf("0 ");
	}
	if (f) {
		ll ans2 = 0;
		for (int x = 1;x <= n;++x) {
			for (int y = 1;y <= m;++y) {
				if (s[x][y] == '0' && d[x][y] >= 3) {
					ans2 = (ans2 + r[x][y] * (T2[y].query(x + d[x][y]) -  T2[y].query(x+1)) % mod) % mod;
				}
			}
		}
		printf("%lld\n",ans2);
	} else {
		printf("0\n");
	}
}

signed main() {
	FO(plant)
	int T,id;scanf("%d %d\n",&T,&id);
	while (T--) solve();
	return 0;
}
