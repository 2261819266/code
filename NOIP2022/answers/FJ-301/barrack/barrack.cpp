#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<random>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define I inline ll
#define ll long long 
using namespace std;
#define cht 1000000007
#define her1 20090115//I love her
#define IV inline void
#define ull unsigned long long
#define F(i,j,n)for(int i=j;i<=n;i++)
#define D(i,j,n)for(int i=j;i>=n;i--)
#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(ll i=j;i<=n;i++)
#define DL(i,j,n)for(ll i=j;i>=n;i--)
#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)
#define mem(x,val)memset(x,val,sizeof x)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
mt19937 rnd(her1);
const int maxn = 2e6+5;struct edge{ll to,nxt;}e[2*maxn];vector<ll>g[maxn];
ll n,m,dft,csp=1,first[maxn],bel[maxn],d[maxn],f[maxn],dep[maxn];bool vis[maxn];
IV add(ll u,ll v){e[++csp]=edge{v,first[u]};first[u]=csp;}ll U[maxn],V[maxn],siz[maxn],cm[maxn];
I find(ll x){return bel[x]==x?x:bel[x]=find(bel[x]);}ll dp[maxn][2][2],scm[maxn],p2[maxn*2];
IV dfs(ll u,ll F){
	vis[u]=1;dep[u]=dep[F]+1;
	E(i,u){
		ll v=e[i].to;
		if(v==F)continue;
		if(!vis[v]){
			f[v]=u;dfs(v,u);
		}
		else if(dep[v]<dep[u])d[u]++,d[v]--;
	}
}
IV dfs2(ll u){
	vis[u]=1;
	E(i,u){
		ll v=e[i].to;
		if(!vis[v])dfs2(v),d[u]+=d[v];
	}
}
IV cmul(ll&x,ll val){val%=cht;x=x*val%cht;}
IV dfs3(ll u,ll F){
	ll A=p2[scm[u]=cm[u]],B=(p2[cm[u]+siz[u]]-A+cht)%cht;
	dp[u][0][0]=A;dp[u][0][1]=A;dp[u][1][1]=B;
	for(ll v:g[u])if(v^F){
		dfs3(v,u);scm[u]+=scm[v]+1;
		dp[u][0][0]=dp[u][0][0]*dp[v][0][0]*2%cht;
		cmul(dp[u][1][1],dp[v][1][1]+dp[v][0][1]+2*dp[v][0][0]);
		cmul(dp[u][0][1],dp[v][0][0]*2+(dp[v][0][1]+dp[v][1][1]));
	}
	dp[u][0][1]=(dp[u][0][1]-dp[u][0][0]+cht)%cht;
//	for(ll v:g[u])if(v^F)dp[u][0][1]=(dp[u][0][1]+dp[v][0][1]+dp[v][1][1]+cht)%cht;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();F(i,1,n)siz[bel[i]=i]=1;
	p2[0]=1;F(i,1,n+m)p2[i]=p2[i-1]*2%cht;
	F(i,1,m){
		ll u=read(),v=read();
		add(u,v);add(v,u);U[i]=u;V[i]=v;
	}
	dfs(1,0);mem(vis,0);//F(i,1,n)cout<<d[i]<<' ';puts("");
	dfs2(1);//F(i,1,n)cout<<f[i]<<' '<<d[i]<<endl;puts("");
	F(i,1,m){
		if(f[V[i]]!=U[i])swap(V[i],U[i]);//cout<<U[i]<<' '<<V[i]<<endl;
		if(d[V[i]]||f[V[i]]!=U[i]){
			ll fu=find(U[i]),fv=find(V[i]);if(fu==fv){
				cm[fu]++;continue;
			}
			siz[fv]+=siz[fu];bel[fu]=fv;cm[fv]+=cm[fu]+1;
		}
	}
//	F(i,1,n)cout<<find(i)<<' '<<siz[i]<<endl;
	F(i,1,m){
		if(f[V[i]]!=U[i])swap(V[i],U[i]);
		if(d[V[i]]||f[V[i]]!=U[i])continue;
		g[find(U[i])].push_back(find(V[i]));
		g[find(V[i])].push_back(find(U[i]));
	}
	dfs3(find(1),0);ll ans=0;
//	F(i,1,n)cout<<dp[i][0][0]<<' '<<dp[i][0][1]<<' '<<dp[i][1][1]<<endl;
//	cout<<dp[find(1)][0][0]<<' '<<dp[find(1)][0][1]<<' '<<dp[find(1)][1][1]<<endl;
	F(i,1,n)ans=(ans+dp[i][1][1]*p2[scm[find(1)]-scm[i]])%cht;//,cout<<scm[find(1)]-scm[i]<<endl;
	return cout<<ans,0;
}
