#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	x*=f;
}
typedef long long ll;
const int N=5e5+10,M=1e6+10,E=M*2;
const ll mod=1e9+7;
ll qpow(ll x,ll y){
	ll z=1;
	while(y){
		if(y&1)z=z*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return z;
}
const int half=qpow(2,mod-2);
int n,m,deg[N];
struct T{
	int e=1,n[E],t[E],h[N];
	void lnk(int x,int y){
		n[++e]=h[x];
		t[e]=y;
		h[x]=e;
	}
}g,h;
int c,d[N],l[N];
int t,s[N];
int p,b[N],z[N],e[N];
void tarj(int x,int f){
	d[x]=l[x]=++c;
	s[t++]=x;
	for(int i=g.h[x];i;i=g.n[i]){
		int y=g.t[i];
		if(!d[y]){
			tarj(y,x);
			l[x]=min(l[x],l[y]);
		}else if(y!=f)l[x]=min(l[x],d[y]);
	}
	if(d[x]==l[x]){
		++p;
		do{
			--t;
			b[s[t]]=p;
			++z[p];
		}while(s[t]!=x);
	}
}
ll dp[N],ans;
void dfs(int x,int f){
	dp[x]=qpow(2,z[x]);
	if(x==1)--dp[x];
	for(int i=h.h[x];i;i=h.n[i]){
		int y=h.t[i];
		if(y==f)continue;
		dfs(y,x);
		dp[x]=dp[x]*(dp[y]+1)%mod;
	}
//	dp[x]=(dp[x]+mod-half)%mod;
	ans=(ans+dp[x])%mod;
//	printf("%d %d\n",x,dp[x]);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	rd(n);rd(m);
	for(int i=1,u,v;i<=m;++i)rd(u),rd(v),g.lnk(u,v),g.lnk(v,u),++deg[u],++deg[v];
	tarj(1,1);
	for(int x=1;x<=n;++x){
		for(int i=g.h[x];i;i=g.n[i]){
			int y=g.t[i];
			if(b[x]==b[y])++e[b[x]];
			else h.lnk(b[x],b[y]);
		}
	}
	dfs(1,1);
	printf("%lld",dp[1]*qpow(2,m)%mod);
}

