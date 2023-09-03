#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,t,a[500086],b[500086],n,q,l,r;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout); 
	scanf("%lld%lld",&t,&n);
	for(ll i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	scanf("%lld",&q);
	while(q--){
		ans=0;
	    scanf("%lld%lld",&l,&r);
	    for(ll i=l;i<=r;i++)
	    {
	    	ll maxa=a[i],maxb=b[i];
	    	for(ll j=i;j<=r;j++)
	    	{
	    		maxa=max(maxa,a[j]);
	    		maxb=max(maxb,b[j]);
	    		ans+=maxa*maxb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
