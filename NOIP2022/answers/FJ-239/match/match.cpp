#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
using namespace std;
const long long N=250005;
ll T,n,a[N],b[N],Q,l,r; 
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) scanf("%lld",&b[i]);
	scanf("%lld",&Q);
	while(Q--){
		ll ans=0;
		scanf("%lld%lld",&l,&r);
		rep(i,l,r) rep(j,i,r){
			ll maxa=0,maxb=0;
			rep(k,i,j){
				maxa=max(a[k],maxa);
				maxb=max(b[k],maxb);
			}
			ans=(ans+maxa*maxb);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
