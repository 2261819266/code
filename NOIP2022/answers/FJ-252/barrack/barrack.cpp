#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod =1e9+7;
ll qpow(ll base,ll poe){
	ll ans=1;
	while(poe>0){
		if(poe&1)ans=ans*base%mod;
		base=base*base%mod;
		poe>>=1;
	}
	return ans;
}
int n,m,x,y;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y);
	unsigned long long ans=qpow(2,m-1);
	ans=(ans*m*(m+1)/2)%mod;
	ans=(ans+mod)%mod;
	ans=(ans+qpow(2,m)%mod*(m+1)%mod+mod)%mod;
	printf("%llu",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
