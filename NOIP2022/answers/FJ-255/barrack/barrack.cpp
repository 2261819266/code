#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define fin freopen("in.in","r",stdin);
inline int read() {
	int x=0,v=1,ch=getchar();
	while('0'>ch||ch>'9') {
		if(ch=='-')v = 0;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') {
		x = x * 10 + (ch^'0');
		ch=getchar();
	}
	return v ? x : -x;
}
const int MAX = 1e6+5;
int n,m;

struct E{
	int e,nxt;
}e[MAX << 1];
int cnt = 2,head[MAX];

void add(int u,int v) {
	e[cnt] = (E) {v,head[u]};
	head[u] =cnt ++;
}

int is[MAX << 1];
int low[MAX], dfn[MAX], idx, tim = 0;
void dfs1(int x,int in) {
	dfn[x] = low[x] = ++ tim;
	for(int i=head[x];i;i=e[i].nxt) {
		int y=e[i].e;
		if(!dfn[y]) {
			dfs1(y, i);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x]) {
				is[i] = is[i ^ 1] = 1;
			}
		}else if((in ^ 1) != i) {
			low[x] = min(low[x], dfn[y]);
		}
	}
}
int vis[MAX];
vector<int> G[MAX];
int col[MAX], v[MAX];
void find(int x, int c) {
	vis[x] = 1;
	col[x] = c;
	v[c] ++;
	for(int i=head[x];i;i=e[i].nxt) {
		if(is[i] || is[i ^ 1]) continue;
		int y = e[i].e;
		if(vis[y]) continue;
		find(y, c);
	}
}
const int P = 1e9+7;
int pw[MAX];

void init() {
	pw[0] = 1;
	for(int i=1;i<=1000000;++i) pw[i] = 2ll * pw[i-1] % P;
}
void inc(int &x,int y) {
	x += y;
	if(x >= P) x -= P;
}


int used[MAX];
void dfs2(int x, int fat) {
	used[x] = 1;
	for(int y:G[x]) {
		if(used[y] || !vis[y]) continue;
		if(fat != y) dfs2(y, x);
	}
}
bool check() {
	for(int i=1;i<=idx;++i) used[i] = 0;
	int tot = 0;
	for(int i=1;i<=idx;++i) 
		if(!used[i] && vis[i]) {
			dfs2(i, 0);
			++ tot;
		}
	
	return tot == 1;
}

const int M = 3005;

int f[M][M], siz[M], g[M];

void dfs3(int x, int fat) {
	f[x][0] = 1; siz[x] = 1;
	for(int y:G[x]) {
		if(y == fat) continue; 
		dfs3(y, x); 
		for(int i=0;i<=siz[x]+siz[y];++i) g[i] = 0;
		for(int i=0;i<=siz[x];++i) {
			for(int j=0;j<=siz[y];++j) {
				inc(g[i+j], 1ll * f[x][i] * f[y][j] % P);
			}
		}
		siz[x] += siz[y];
		for(int i=0;i<=siz[x];++i) f[x][i] = g[i];
	}
	int t = ( pw[v[x]] - 1 + P ) % P;
	for(int i=siz[x];i>=0;--i) {
		if(i) f[x][i] = 1ll * f[x][i-1] * t % P;
	}
}

signed main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	init();
	n=read(),m=read();
	
	int lian = 1; if(m != n-1) lian = 0; 
	for(int i=1;i<=m;++i) {
		int u,vv;
		u=read(),vv=read();
		add(u,vv),add(vv,u);
		if(!(u == i && vv == i + 1) && !(vv == i && u == i + 1)) {
			lian = 0;
		}
	}
	for(int i=1;i<=n;++i) {
		if(!dfn[i]) dfs1(i,0);
	}
	for(int i=1;i<=n;++i) {
		if(!vis[i]) {
			++idx;
			find(i, idx);
		}
	}
	
	cnt = 0;
	for(int x=1;x<=n;++x) {
		for(int i=head[x];i;i=e[i].nxt) {
			int y = e[i].e;
			if(col[x] != col[y]) {
				G[col[x]].ep(col[y]);
				++ cnt;
			}
		}
	}
	if(lian) {
		int ans = 0;
		for(int i=1;i<=idx;++i) {
			inc(ans, 1ll * (idx - i + 1) * pw[m - i + 1] % P);
		}
		printf("%d\n", ans);
		return 0;
	}
	
	if(n <= 16) {
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(int S=1;S<(1<<idx);++S) {
			int sumv = 1, tot = 0;
			for(int i=1;i<=idx;++i) {
				if(S >> (i-1) & 1) {
					sumv = 1ll * sumv * ( pw[v[i]] - 1 + P ) % P ;
					tot ++;
					vis[i] = 1;
				}
			}
			int val = 0;
			if(check()) val = 1ll * sumv * pw[m - (tot - 1)] % P;
			inc(ans, val);
			for(int i=1;i<=idx;++i) vis[i] = 0;
		}
		printf("%d\n", ans);		
	}else {
		dfs3(col[1], 0);
		int res = 0;
		for(int i=1;i<=idx;++i) {
			int ret = 0;
			for(int j=1;j<=idx;++j) {
				inc(ret , f[j][i]);
			}
			inc(res, 1ll * ret * pw[m - i + 1] % P);
		}
		printf("%d\n", res);
	}

	return 0;
}

