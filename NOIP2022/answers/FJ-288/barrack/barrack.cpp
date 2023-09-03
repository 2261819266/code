#include<bits/stdc++.h>
using namespace std;
int rd(){char c;bool f(1);while(!isdigit(c=getchar()))f=c!='-';int x(c-48);while(isdigit(c=getchar()))x=x*10+(c-48);return f?x:-x;}
const int N(5e5),M(1e6),P(1e9+7);
int n,m,_m,ans;
int pw[M+5]{1},sz[N+5];
int low[N+5],dfn[N+5],dC,ecc[N+5],eC,esz[N+5];
int hd[N+5],nx[M*2+5],to[M*2+5],tE(1);
int _hd[N+5],_nx[M*2+5],_to[M*2+5],_tE;
bool bri[M*2+5],vis[N+5],rt[N+5];
array<int,2> edge[M+5];
void add(int u,int v)
{
	nx[++tE]=hd[u],hd[u]=tE,to[tE]=v;
}
void _add(int u,int v)
{
	_nx[++_tE]=_hd[u],_hd[u]=_tE,_to[_tE]=v;
}
void tarjan(int u,int pr)
{
	low[u]=dfn[u]=++dC;
	for(int i(hd[u]);i;i=nx[i])
		if(!dfn[to[i]])
		{
			tarjan(to[i],i),low[u]=min(low[u],low[to[i]]);
			if(low[to[i]]>dfn[u]) bri[i]=bri[i^1]=1;
		}
		else if(i^pr^1) low[u]=min(low[u],dfn[to[i]]);
}
int f0[N+5],f1[N+5];
void rdfs(int u)
{
	sz[u]=1,f1[u]=0,f0[u]=1,vis[u]=1;
	for(int i(_hd[u]);i;i=_nx[i]) if(!vis[_to[i]])
	{
		rdfs(_to[i]),sz[u]+=sz[_to[i]];
		f1[u]=(1ll*(f0[u]+f1[u])*(f1[_to[i]])+1ll*f1[u]*(f0[_to[i]]<<1))%P;
		f0[u]=1ll*f0[u]*(f0[_to[i]]<<1)%P;
	}
	f1[u]=(1ll*f1[u]*pw[esz[u]]+1ll*f0[u]*(pw[esz[u]]-1))%P;
	(ans+=1ll*f1[u]*pw[eC-sz[u]-!rt[u]]%P)%=P;
}
void dfs(int u)
{
	++esz[ecc[u]=eC];
	for(int i(hd[u]);i;i=nx[i])
		if(!bri[i]&&!ecc[to[i]]) dfs(to[i]);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=rd(),m=rd();
	for(int i(1);i<=M;++i) pw[i]=(pw[i-1]<<1)%P;
	for(int i(1),u,v;i<=m;++i) u=rd(),v=rd(),add(u,v),add(v,u),edge[i]={u,v};
	for(int i(1);i<=n;++i) if(!dfn[i]) tarjan(i,0);
	for(int i(1);i<=n;++i) if(!ecc[i]) ++eC,dfs(i);
	for(int i(1);i<=m;++i)
	{
		int u(ecc[edge[i][0]]),v(ecc[edge[i][1]]);
		if (u!=v)_add(u,v),_add(v,u);
	}
	for(int i(1);i<=eC;++i) if(!vis[i]) rt[i]=1,rdfs(i);
	printf("%lld",1ll*ans*pw[m-(eC-1)]%P);
	return 0;
}//±ð¹Ò·Öqwq 
