#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 500005
#define M 2000005
#define P 1000000007
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,tot=1,num=0,head[N],nxt[M],ver[M],dfn[N],low[N],bri[M];
void add(int u,int v){
	nxt[++tot]=head[u];ver[tot]=v;head[u]=tot;
}
void tarjan(int u,int in_edge){
	dfn[u]=low[u]=++num;
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])bri[i^1]=bri[i]=1;
		}
		else if(i!=(in_edge^1))low[u]=min(low[u],dfn[v]);
	}
}
int dcc=0,tc=1,cb=0,c[N],a[N],hc[N],nc[M],vc[M];
void dfs(int u){
	c[u]=dcc;a[dcc]++;
	for(int i=head[u];i;i=nxt[i])if(!c[ver[i]]&&!bri[i])dfs(ver[i]);
}
void add_c(int u,int v){
	nc[++tc]=hc[u];vc[tc]=v;hc[u]=tc;
}
ll ans=0,p[M],sz[N],f[N];
void dp(int u,int fa){
	sz[u]=1;f[u]=p[a[u]]-1;
	ll res=1,sum=0;
	for(int i=hc[u];i;i=nc[i])if(vc[i]!=fa){
		int v=vc[i];
		dp(v,u);
		sz[u]+=sz[v];
		f[u]=f[u]*(f[v]+p[sz[v]])%P;
	}
	ans=(ans+f[u]*p[cb+dcc-sz[u]]%P)%P;
	//wrong here
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++)if(!c[i])++dcc,dfs(i);
	for(int i=2;i<=tot;i+=2){
		if(c[ver[i^1]]==c[ver[i]])cb++;
		else{
			add_c(c[ver[i^1]],c[ver[i]]);
			add_c(c[ver[i]],c[ver[i^1]]);
		}
	}
	p[0]=1;for(int i=1;i<=2000000;i++)p[i]=p[i-1]*2%P;
	dp(1,0);
	printf("%lld\n",ans);
	return 0;
}
