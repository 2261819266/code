#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,t,q,l,r;
ll a[1000001];
ll b[1000001];
ll tree1[4000001],tree2[4000001];
void build(ll node,ll l,ll r)
{
	if(l==r)
	{
		tree1[node]=a[l];
		tree2[node]=b[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(node*2+1,l,mid);
	build(node*2+2,mid+1,r);
	tree1[node]=max(tree1[node*2+1],tree1[node*2+2]);
	tree2[node]=max(tree2[node*2+1],tree2[node*2+2]);
}
ll maxx1(ll node,ll l,ll r,ll L,ll R)
{
	if(R<l||L>r||l>r)
		return 0;
	if(l==L&&r==R)
		return tree1[node];
	ll mid=(l+r)>>1;
	return max(maxx1(node*2+1,l,mid,L,min(R,mid)),maxx1(node*2+2,mid+1,r,max(mid+1,L),R));
}
ll maxx2(ll node,ll l,ll r,ll L,ll R)
{
	if(R<l||L>r||l>r)
		return 0;
	if(l==L&&r==R)
		return tree2[node];
	ll mid=(l+r)>>1;
	return max(maxx2(node*2+1,l,mid,L,min(R,mid)),maxx2(node*2+2,mid+1,r,max(mid+1,L),R));
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ll i,j,k;
	scanf("%lld%lld",&t,&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	build(0,1,n);
	scanf("%lld",&q);
	for(i=1;i<=q;i++)
	{	
		ll ans=0;
		scanf("%lld%lld",&l,&r);
		for(j=l;j<=r;j++)
			for(k=j;k<=r;k++)
				ans+=(maxx1(0,1,n,j,k)*maxx2(0,1,n,j,k));
		printf("%lld\n",ans);
	}
	return 0;
}
	
