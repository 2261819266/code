#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
ll n,m,ans;
bool f;
ll power(ll a,ll b) {
	ll ans=1;
	for(; b; b>>=1) {
		if(b&1)
			ans=ans*a%P;
		a=a*a%P;
	}
	return ans;
}
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout); 
	ll a,b;
	scanf("%lld%lld",&n,&m);
	for(ll i=1; i<=m; i++) {
		scanf("%lld%lld",&a,&b);
//		add(a,b);
		if(b!=a+1)
			f=1;
	}
	if(f==0) {
		for(ll i=0; i<n; i++) {
			ans=(ans+(n-i)*power(2,n-1-i)%P)%P;
		}
		printf("%lld",ans);
	}
	return 0;
}
