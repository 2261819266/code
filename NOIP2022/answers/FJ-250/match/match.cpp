#include<cstdio>
#define mid ((l+r)/2)
#define ls (thisp*2)
#define rs (thisp*2+1)
typedef unsigned long long ll;
const ll SIZE=1e5+10;
inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x*10)+(ch^48),ch=getchar();
	return x;
}
inline ll max(ll x,ll y){return x>y?x:y;}
ll t,n,q,a[SIZE],b[SIZE];
inline ll solve(ll l,ll r)
{
	ll ans=0;
	for(ll L=l;L<=r;L++)for(ll R=L;R<=r;R++)
	{
		ll maxa=0,maxb=0;
		for(ll i=L;i<=R;i++)maxa=max(maxa,a[i]),maxb=max(maxb,b[i]);
		ans+=maxa*maxb;
	}
	return ans;
}
int main()
{
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	t=read(),n=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	for(ll i=1;i<=n;i++)b[i]=read();
	q=read();
	for(ll i=1,l,r;i<=q;i++)l=read(),r=read(),printf("%lld\n",solve(l,r));
	return 0;
}
