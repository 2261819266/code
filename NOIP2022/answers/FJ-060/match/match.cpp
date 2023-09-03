#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++) 
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 100500
using namespace std;
ll n,T,Q,l,r;
ll a[Nx],b[Nx];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) scanf("%lld",&b[i]);
	scanf("%lld",&Q);
	while(Q--){
		scanf("%lld%lld",&l,&r);
		ll ans=0;
		rep(i,l,r){
			rep(j,i,r){
				ll Maxa=-1,Maxb=-1;
				rep(k,i,j) Maxa=max(Maxa,a[k]),Maxb=max(Maxb,b[k]);
				ans+=(Maxa*Maxb);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
