#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m,tot;
ll quick(ll x,ll y){
	ll ans=1;
	if(y==0) return 1;
	while(y!=1){
		if(y&1){
			ans*=x;
			ans%=mod;
			y--;
		}
		else{
			x=x*x;
			x%=mod;
			y/=2;
		}
	} 
	return (x*ans)%mod;
}
ll jy(ll x){
	ll ans=1;
	for(int i=1;i<=x;i++){
		ans*=(n-x-i+1+1);
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
	}
	for(ll i=1;i<=n;i++){
		tot+=(jy(i))*quick(2,m-i+1);
		tot%=mod;
	}
	printf("%lld",tot);
	return 0;
}
