#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250005;
int t,n,q;
ll a[N],b[N];
ll aa[N*4],bb[N*4];

#define now int u,int l,int r
#define lson ls,l,mid
#define rson rs,mid+1,r
#define ls u*2
#define rs u*2+1
#define mid (l+r)/2
#define root 1,1,n

void build(now)
{
	if(l==r)
	{
		aa[u]=a[l]; bb[u]=b[l];
		return;
	}
	build(lson); build(rson);
	aa[u]=max(aa[ls],aa[rs]);
	bb[u]=max(bb[ls],bb[rs]);
}

ll querya(now,int L,int R)
{
	if(l>R || r<L) return 0;
	if(l>=L && r<=R)
	{
		return aa[u];
	}
	return max(querya(lson,L,R),querya(rson,L,R));
}

ll queryb(now,int L,int R)
{
	if(l>R || r<L) return 0;
	if(l>=L && r<=R)
	{
		return bb[u];
	}
	return max(queryb(lson,L,R),queryb(rson,L,R));
}

void solve(int l,int r)
{
	ll ans=0;
	for(int i=l;i<=r;i++)
	{
		for(int j=i;j<=r;j++)
		{
			ans+=querya(root,i,j)*queryb(root,i,j);
		}
	}
	printf("%lld",ans);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	build(root);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r; scanf("%d%d",&l,&r);
		solve(l,r);
	}
	
	return 0;
}
