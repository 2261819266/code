#include <bits/stdc++.h>
typedef long long ll;
const int N=5e5+15,M=1e6+15;
const ll p=1e9+7;

inline ll rd(){
	ll w=1,r=0;char c=getchar();
	while(!isdigit(c)) ((c=='-')&&(w=-1)),c=getchar();
	while(isdigit(c)) r=r*10+c-'0',c=getchar();
	return w*r;
}

inline ll qpow(ll a,ll x){
	ll r=1;
	while(x){
		if(x&1) r=r*a%p;
		a=a*a%p;x>>=1;
	}
	return r;
}

int head[N],tt;
struct edge{
	int to,nxt;
	edge(int a=0,int b=0){to=a,nxt=b;}
}ed[M<<1];

inline void add(int u,int v){
	ed[++tt]=edge(v,head[u]),head[u]=tt;
}

int n,m;
ll ans;

int main(){
	freopen("barrack.in","r",stdin);freopen("barrack.out","w",stdout);
	n=rd(),m=rd();
	bool fl=1;
	for(int i=1,u,v;i<=m;++i){
		u=rd(),v=rd(),add(u,v),add(v,u);
		if(v!=u+1) fl=0;
	}
	if(fl){
		ans=(ans+qpow(2,n-1))%p;
		for(int i=2;i<=n;++i){
			ans=(ans+(n-i+1)*qpow(2,n-2)%p);
		}
		printf("%lld\n",ans);return 0;
	}
	 
	return 0;
}
