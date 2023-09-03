//Checkmate, I couldn't lose.
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

inline void read(int &x) {
	x = 0;int f = 1;char c = getchar();
	while (!isdigit(c)) {if (c == '-') {f = -1;}c = getchar();}
	while (isdigit(c)) {x = x * 10 + c - 48;c = getchar();}
	x *= f;
}
const ll mod = 1e9 + 7;
const int N = 3e5 + 10;
int n,m;
int to[N<<1],hd[N],tot = -1,nxt[N<<1],bridge[N<<1];
int dfn[N],low[N],cnt,viss[N];
bool vis[N];
pii edg[N];
vector <pii> bri;
ll ans;
void add(int x,int y) {
	to[++tot] = y;nxt[tot] = hd[x];hd[x] = tot;
}

void addedge(int x,int y) {
	add(x,y);add(y,x);
}

void dfs(int x,int ex,int ey) {
	viss[x] = 1;
	for (int i = hd[x];i != -1;i = nxt[i]) {
		int y = to[i];
		if (!viss[y] && (!(x == ex && y == ey)) && (!(x == ey && y == ex))) {
			dfs(y,ex,ey);
		}
	}
}

void querybridge() {
	for (int i = 1;i <= m;++i) {
		//if (!vis[edg[i].first] || !vis[edg[i].second]) continue;
		for (int j = 1;j <= n;++j) viss[j] = 0;
		for (int j = 1;j <= n;++j) {
			if (vis[j]) {
				dfs(j,edg[i].first,edg[i].second);
				break;
			}
		}
		bool flag = 0;
		for (int j = 1;j <= n;++j) if (!viss[j] && vis[j]) flag = 1;
		if (flag) {
			bri.push_back(edg[i]);
		}
	}
}

ll ffpow(ll a,ll b) {
	ll ans = 1;
	for (;b;b >>= 1) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}

void solve(int s) {
	for (int i = 0;i < n;++i) {
		if (s & (1 << i)) vis[i + 1] = 1;
		else vis[i + 1] = 0;
	}
	bri.clear();
	querybridge();
	ll tmp = m - bri.size();
	ans = (ans + ffpow(2,tmp)) % mod;
}

signed main() {
	FO(barrack)
	read(n);read(m);
	for (int i = 1;i <= n;++i) hd[i] = -1;
	for (int i = 1;i <= m;++i) {
		int x,y;read(x);read(y);
		edg[i] = mp(x,y);
		addedge(x,y);
	}
	for (int S = 1;S < (1 << n);++S) {
		solve(S);
	}
	printf("%lld\n",ans);
	return 0;
}
