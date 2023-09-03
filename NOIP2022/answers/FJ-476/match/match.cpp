#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5,M=3e6,MOD=18446744073709551616;
ll T,n,a[N],b[N],Q,l,r,da[M],db[M],sum;
void build(int s,int t,int i)
{
	if(s==t)
	{
		da[i]=a[s];
		db[i]=b[s];
		return;
	}
	ll mid=(s+t)>>1;
	build(s,mid,i<<1);
	build(mid+1,t,i<<1|1);
	da[i]=max(da[i<<1],da[i<<1|1]);
	db[i]=max(db[i<<1],db[i<<1|1]);
	return;
}
ll getmaxa(int l,int r,int s,int t,int i)
{
	ll mid=(s+t)>>1;
	if(s>r||t<l)return 0;
	if(s<l||t>r)return max(getmaxa(l,r,s,mid,i<<1),getmaxa(l,r,mid+1,t,i<<1|1));
	return da[i];
}
ll getmaxb(int l,int r,int s,int t,int i)
{
	ll mid=(s+t)>>1;
	if(s>r||t<l)return 0;
	if(s<l||t>r)return max(getmaxb(l,r,s,mid,i<<1),getmaxb(l,r,mid+1,t,i<<1|1));
	else return db[i];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	build(1,n,1);
	scanf("%lld",&Q);
	for(int q=1;q<=Q;q++)
	{
		sum=0;
		scanf("%lld%lld",&l,&r);
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				ll ax=getmaxa(i,j,1,n,1);
				ll bx=getmaxb(i,j,1,n,1);
				sum=(sum+(ax*bx)%MOD)%MOD;
			}
		}
		printf("%lld",sum);
	}
	return 0;
}
