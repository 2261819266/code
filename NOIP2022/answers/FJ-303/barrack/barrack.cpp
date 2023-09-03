#include<bits/stdc++.h>
#define IL inline
#define reg register
#define mod 1000000007
#define N 500500
#define M 1000100
IL int read()
{
	reg int x=0; reg char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

IL int Add(reg int x,reg int y){return x+y<mod?x+y:x+y-mod;}
IL int Sub(reg int x,reg int y){return x<y?x-y+mod:x-y;}
IL void Pls(reg int &x,reg int y){x=Add(x,y);}
IL int Mul(reg int x,reg int y){reg long long r=1ll*x*y; return r<mod?r:r%mod;}

const int inv2=mod+1>>1;
int n,m,first[N],nxt[M+M],to[M+M],num=1;

IL void add(reg int u,reg int v){nxt[++num]=first[u],to[first[u]=num]=v;}
IL void adde(reg int u,reg int v){add(u,v),add(v,u);}

int tot,dfn[N],low[N],s[N],col[N],w[N],top,dfc;

IL void cmin(reg int &x,reg int y){x>y?x=y:0;}

void tarjan(reg int u,reg int fa)
{
	dfn[u]=low[u]=++dfc,s[++top]=u;
	for(reg int i=first[u],v;i;i=nxt[i])if(i!=fa)
	{
		if(!dfn[v=to[i]])tarjan(v,i^1),cmin(low[u],low[v]);
		else cmin(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		++tot;
		do col[s[top]]=tot,++w[tot]; while(s[top--]!=u);
	}	
}

std::vector<int>G[N];

IL void link(reg int x,reg int y){G[x].push_back(y),G[y].push_back(x);}

int f[N],g[N],pw[M],ans; // is lca / have point.

void dfs(reg int u,reg int fa)
{
	f[u]=Sub(pw[w[u]],1);
	for(reg auto v:G[u])if(v!=fa)dfs(v,u),Pls(f[u],Mul(f[u],Mul(g[v],inv2)));
	// choose itself
	reg int c0=1,c1=0;
	for(reg auto v:G[u])if(v!=fa)Pls(c0,Mul(c0,Mul(g[v],inv2))),Pls(c1,Mul(g[v],inv2));
	Pls(f[u],Sub(c0,Add(c1,1)));
	// did not choose it self
	g[u]=pw[w[u]];
	for(reg auto v:G[u])if(v!=fa)Pls(g[u],Mul(g[u],Mul(g[v],inv2)));
	g[u]=Sub(g[u],1);
}

main()
{
	freopen("barrack.in","r",stdin),freopen("barrack.out","w",stdout);
	n=read(),m=read();
	pw[0]=1; for(reg int i=1;i<=m;++i)pw[i]=Add(pw[i-1],pw[i-1]);
	for(reg int i=m;i--;)adde(read(),read());
	tarjan(1,0);
	for(reg int u=1,i,v;u<=n;++u)for(i=first[u];i;i=nxt[i])if(col[u]!=col[v=to[i]]&&v>u)link(col[u],col[v]);
	dfs(col[1],0);
	for(reg int i=1;i<=tot;++i)Pls(ans,Mul(f[i],pw[m]));
	printf("%d",ans);
}
