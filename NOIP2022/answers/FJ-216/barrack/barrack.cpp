#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')f=(c!='-'),c=getchar();
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	if(f)return x;return -x;
}
const int maxn=5e6+10,mod=1e9+7;
int n,m,qp[maxn];
//int qpow(int a,int x){int ans=1;while(x){if(x&1)ans=ans*a%mod;a=a*a%mod,x>>=1;}return ans;}
int cut[maxn],c[maxn],ans=1,sum=0,siz[maxn],cnt;
namespace TREE{
	int head[maxn],ver[maxn],nxt[maxn],tot;
	void add(int a,int b){ver[++tot]=b,nxt[tot]=head[a],head[a]=tot;}
	#define fore(u,i) for(int i=head[u];i;i=nxt[i])
	int f[maxn],g[maxn],son[maxn];
	void dfs(int u,int fa){
		f[u]=qp[siz[u]],g[u]=qp[siz[u]],son[u]=1;
		fore(u,i)if(ver[i]!=fa){
			dfs(ver[i],u);son[u]+=son[ver[i]];
			f[u]=(__int128)f[u]*(g[ver[i]]+qp[son[ver[i]]])%mod;
			g[u]=((__int128)g[u]*(g[ver[i]]+qp[son[ver[i]]])%mod)%mod;
		}
		fore(u,i)if(ver[i]!=fa)f[u]=(f[u]-(__int128)g[ver[i]]*qp[son[u]-son[ver[i]]-1]%mod+mod)%mod;f[u]=(f[u]-qp[son[u]-1]+mod)%mod;
		g[u]=(g[u]-qp[son[u]-1]+mod)%mod;
		sum=(sum+(__int128)f[u]*qp[cnt-son[u]]%mod)%mod;
	}
	void work(){dfs(1,1);ans=(__int128)ans*sum%mod;}
}
namespace GRA{
	int head[maxn],ver[maxn],nxt[maxn],tot=1;
	void add(int a,int b){ver[++tot]=b,nxt[tot]=head[a],head[a]=tot;}
	void link(int a,int b){add(a,b);add(b,a);}
	#define fore(u,i) for(int i=head[u];i;i=nxt[i])
	int dfn[maxn],low[maxn],idx;
	void tarjan(int u,int edge){
		dfn[u]=low[u]=++idx;
		fore(u,i)if(i!=edge)if(!dfn[ver[i]]){
			tarjan(ver[i],i^1);low[u]=min(low[u],low[ver[i]]);
			if(low[ver[i]]>dfn[u])cut[i]=cut[i^1]=1;
		}else low[u]=min(low[u],dfn[ver[i]]);
	}
	int vis[maxn];
	void dfs(int u,int cc){c[u]=cc;vis[u]=1;fore(u,i)if(!cut[i]&&!vis[ver[i]])dfs(ver[i],cc);}
	void build(){
		for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,0);
		for(int i=1;i<=n;i++)if(!vis[i])dfs(i,++cnt);
		for(int u=1;u<=n;u++){siz[c[u]]++;fore(u,i)if(cut[i])TREE::add(c[u],c[ver[i]]);}
		for(int i=2;i<=tot;i+=2)if(!cut[i])ans=ans*2%mod;
	}
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();for(int i=1;i<=m;i++)GRA::link(read(),read());
	qp[0]=1;for(int i=1;i<=m;i++)qp[i]=qp[i-1]*2%mod;
	GRA::build();TREE::work();
	return printf("%lld",(long long)ans),0;
}

