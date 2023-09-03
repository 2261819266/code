#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const ll mo=1e9+7;
int n,m;
ll fac[500010],ifac[500010];
ll fpm(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%mo;
		x=x*x%mo;
		y>>=1;
	}
	return res;
}
ll C(ll x,ll y){return fac[x]*ifac[y]%mo*ifac[x-y]%mo;}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d",&n,&m);
	fac[0]=fac[1]=ifac[0]=1;
	for(ll i=2;i<=n;i++) fac[i]=fac[i-1]*i%mo;
	ifac[n]=fpm(fac[n],mo-2);
	for(ll i=n-1;i>=1;i--) ifac[i]=fac[i+1]*(i+1)%mo;
	ll ans=(1<<m)%mo;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			for(int k=j+i;k<=n;k++)
				ans=(ans+C(k-j-1,i-2)*(1<<(n-(k-j+1)))%mo)%mo;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
