//expect /hs /bs expect
#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=(j),_i=(k);i<=_i;++i)
#define drp(i,j,k) for(int i=(j),_i=(k);i>=_i;--i)
using namespace std;
inline int read() {
	int x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//-----------------------------------------------//
const int N=5e5+5,M=2e6+5,mod=1e9+7;
int ans;
int ksm(int x,int k) {
	int s=1;
	while(k) {
		if(k&1) s=s*x%mod;
		x=x*x%mod;k>>=1;
	}
	return s;
}

class graph {
	public:
	int n,m;
	
	int fir[N],nex[M],to[M],pos;
	void add_edge(int x,int y) {
		to[++pos]=y;nex[pos]=fir[x];fir[x]=pos;
		swap(x,y);
		to[++pos]=y;nex[pos]=fir[x];fir[x]=pos;
	}

	int sta[N],top;
	int scc[N],scc_num;
	int dfn[N],low[N],tim;
	void tarjan(int u,int f) {
		sta[++top]=u;
		dfn[u]=low[u]=++tim;
		for(int i=fir[u];i;i=nex[i]) {
			int v=to[i];
			if(v==f) continue;
			if(!dfn[v]) {
				tarjan(v,u);
				low[u]=min(low[u],low[v]);
			}
			else if(!scc[v]) low[u]=min(low[u],low[v]);
		}
		if(dfn[u]==low[u]) {
			scc[u]=++scc_num;
			while(sta[top]!=u) scc[sta[top--]]=scc_num;
			top--;
		}
	}
	
	void work1() {
		n=read(),m=read();ans=mod-ksm(2,m);
		rep(i,1,m) add_edge(read(),read());
		rep(u,1,n) if(!dfn[u]) tarjan(u,0);
	}
}og;



int n,f[N],g[N],h[N];

int fir[N],nex[M],to[M],pos;
void add_edge(int x,int y) {
	if(x==y) {g[x]++;return ;}
	to[++pos]=y;nex[pos]=fir[x];fir[x]=pos;
	swap(x,y);
	to[++pos]=y;nex[pos]=fir[x];fir[x]=pos;
}

void expect_init() {
	n=og.scc_num;
	rep(u,1,og.n) f[og.scc[u]]++;
	rep(u,1,og.n) 
	  for(int i=og.fir[u];i;i=og.nex[i]) {
	  	int v=og.to[i];
	  	add_edge(og.scc[u],og.scc[v]);
	  }
	rep(u,1,n) {
		int x=f[u],y=g[u]/2;
		g[u]=ksm(2,y);
		f[u]=(ksm(2,x+y)+mod-g[u])%mod;
	}
}

int vis[N];
void dfs(int u,int fa) {
	vis[u]=1;
	for(int i=fir[u];i;i=nex[i]) {
		int v=to[i];
		if(v==fa||vis[v]) continue;
		dfs(v,u);
		int x=f[u],y=g[u],z=h[u];
		f[u]=(x*f[v]+x*g[v]*2ll+y*f[v])%mod;
		g[u]=y*g[v]*2ll%mod;
		h[u]=(z*g[v]*2ll+y*f[v]+y*h[v]*2ll)%mod;
	}
}

signed main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	og.work1();
	expect_init();
	dfs(1,0);
	printf("%lld\n",(f[1]+h[1])%mod);
	return 0;
}
