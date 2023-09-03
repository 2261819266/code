#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int mod=1e9+7;
int fir[500010],ne[2000010],cnt,to[2000010],to_[2000010],ne_[2000010],fir_[5000010],cnt_;
int blo[500010],tot1,siz[500010],sizd[500010];
int tot,dfn[500010],low[500010],st[500010],top,d;
long long ans,two[1000010],g[500010];
void add(int u,int v)
{
    to[++cnt]=v;
    ne[cnt]=fir[u];
    fir[u]=cnt;
}
void add_(int u,int v)
{
	to_[++cnt_]=v;
	ne_[cnt_]=fir_[u];
	fir_[u]=cnt_;
}
int tarjan(int o,int last)
{
	dfn[o]=low[o]=++tot;
	st[++top]=o;
	for(int i=fir[o];i;i=ne[i])
	{
		int v=to[i];
		if(v==last) continue;
		if(!dfn[v]) 
		{
			tarjan(v,o);
			low[o]=min(low[o],low[v]);
		}
		else low[o]=min(low[o],dfn[v]);
	}
	if(low[o]==dfn[o])
	{
		++tot1;
		while(low[st[top]]==dfn[o]) 
		{
			blo[st[top]]=tot1;
			top--;
			siz[tot1]++;
		}
	}
}
void dfs(int o,int last)
{
	for(int i=fir_[o];i;i=ne_[i])
	{
		int v=to_[i];
		if(v==last) continue;
		g[o]=g[o]*g[v]%mod;
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	two[0]=1;
	for(int i=1;i<=1000000;++i) two[i]=two[i-1]*2%mod;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i) 
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(n==2) 
	{
		printf("5\n");
		return 0;
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i)
	    for(int j=fir[i];j;j=ne[j]) 
	    {
	    	int v=to[j];
	    	if(blo[v]!=blo[i]) add_(blo[i],blo[v]);
	    	else sizd[blo[i]]++;
		}
	for(int i=1;i<=tot1;++i) 
	{
		sizd[i]/=2;
		g[i]=two[siz[i]]*two[sizd[i]]%mod;
	//	ans=(ans+g[tot1])%mod;
	}
	dfs(1,0);
	for(int i=1;i<=tot1;++i) 
	{
		ans=(ans+g[i])%mod;
		d+=sizd[i];
	}
	ans=((ans-two[d])%mod+mod)%mod;
	printf("%d %lld",d,ans);
	return 0;
}
/*
4 4 
1 2
2 3
3 1
4 1
*/
