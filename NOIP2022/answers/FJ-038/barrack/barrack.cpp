#include<bits/stdc++.h>
#define reg register
#define pb push_back
#define maxn 500010
#define mod 1000000007
#define cmin(a,b) ((a)>(b)?(a)=(b),1:0)
#define _A(x,y) (x)=((x)+(y))%mod
int read() {
	reg int s=0,f=1; reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=s*10+ch-'0',ch=getchar());
	return s*f;
}
int n,m,tim,tt,x[maxn<<1],y[maxn<<1],dfn[maxn],low[maxn],s[maxn];
int tot,ans,pw[maxn<<1],id[maxn],sizP[maxn],f0[maxn],f1[maxn],siz[maxn];
bool vis[maxn];
std::vector<int>e0[maxn],e1[maxn];
int&A(reg int&a,reg int b) {return (a+=b)>=mod?a-=mod:a;}
int A0(reg int a,reg int b) {return (a+=b)>=mod?a-mod:a;}
void tarjan(reg int x,reg int fa) {
	dfn[x]=low[x]=++tim,vis[s[++tt]=x]=1;
	for(reg auto i:e0[x]) if(i!=fa)
		if(!dfn[i]) {
			tarjan(i,x),cmin(low[x],low[i]);
			if(low[i]>dfn[x]) {
				++tot;
				do ++sizP[tot],id[s[tt]]=tot,vis[s[tt]]=0; while(s[tt--]!=i);
			}
		}
		else if(vis[i]) cmin(low[x],dfn[i]);
}
void dfs(reg int x,reg int fa) {
	reg int g1=0,g2=0; siz[x]=f0[x]=1;
	for(reg auto i:e1[x]) if(i!=fa)
		dfs(i,x),siz[x]+=siz[i],A(f0[i],f0[i]),
		g2=(1llu*g2*(f0[i]+f1[i])+1llu*g1*f1[i])%mod,
		g1=(1llu*g1*f0[i]+1llu*f0[x]*f1[i])%mod,f0[x]=1llu*f0[x]*f0[i]%mod;
	_A(ans,(g2+(0llu+g1+g2+f0[x])*(pw[sizP[x]]+mod-1))%mod*pw[tot-siz[x]]),
	f1[x]=(1llu*(g1+g2)*pw[sizP[x]]+1llu*f0[x]*(pw[sizP[x]]+mod-1))%mod;
}
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(reg int i=pw[0]=1;i<=m;++i)
		x[i]=read(),y[i]=read(),e0[x[i]].pb(y[i]),e0[y[i]].pb(x[i]),pw[i]=A0(pw[i-1],pw[i-1]);
	tarjan(1,0),++tot;
	while(tt) ++sizP[tot],id[s[tt]]=tot,--tt;
	for(reg int i=1;i<=m;++i) if(id[x[i]]!=id[y[i]]) e1[id[x[i]]].pb(id[y[i]]),e1[id[y[i]]].pb(id[x[i]]);
	dfs(1,0),printf("%d\n",1llu*ans*pw[m-tot+1]%mod);
	return 0;
}