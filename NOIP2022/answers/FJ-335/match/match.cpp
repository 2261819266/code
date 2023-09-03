#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,Q,l,r;
ll ans;
ll a[250005],b[250005];
ll ta[1000005],tb[1000005];
void build(int l,int r,int k)
{
	if(l==r)
	{
		ta[k]=a[l];
		tb[k]=b[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,k<<1);
	build(mid+1,r,(k<<1)+1);
	ta[k]=max(ta[k<<1],ta[(k<<1)+1]);
	tb[k]=max(tb[k<<1],tb[(k<<1)+1]);
}
ll querya(int L,int R,int l,int r,int k)
{
	if(L<=l&&r<=R)
		return ta[k];
	int mid=l+r>>1;
	if(mid<L)return querya(L,R,mid+1,r,(k<<1)+1);
	if(mid>=R)return querya(L,R,l,mid,k<<1);
	return max(querya(L,mid,l,mid,k<<1),querya(mid+1,R,mid+1,r,(k<<1)+1));
}
ll queryb(int L,int R,int l,int r,int k)
{
	if(L<=l&&r<=R)
		return tb[k];
	int mid=l+r>>1;
	if(mid<L)return queryb(L,R,mid+1,r,(k<<1)+1);
	if(mid>=R)return queryb(L,R,l,mid,k<<1);
	return max(queryb(L,mid,l,mid,k<<1),queryb(mid+1,R,mid+1,r,(k<<1)+1));
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	build(1,n,1);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		ans=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
			{
				ll xa=querya(p,q,1,n,1);
				ll xb=queryb(p,q,1,n,1);
				ans+=xa*xb;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
