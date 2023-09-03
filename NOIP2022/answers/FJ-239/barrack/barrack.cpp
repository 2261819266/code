#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
using namespace std;
const int mod=1e9+7,N=5e5+5;
ll n,m,u,v,f[N],tot,head[N*2],sum;
struct node{
	int to,nxt;
}e[N];
void add(ll u,ll v){
	tot++;
	e[tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n) f[i]=(f[i-1]+i)%mod;
	rep(i,1,m){
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(m==n-1){
		sum+=2*n;
		sum+=f[n-1];
		n-=2;
		while(n>=1){
			rep(i,1,n) sum+=f[i];
			n--;
		}
		printf("%lld",sum%mod);
		return 0;
	}
	else{
		ll res=1;
		rep(i,1,n) res=(res*2)%mod;
		printf("%lld",f[n]*res%mod);
		return 0;
	}
}
