#include <bits/stdc++.h>
#define ull unsigned long long
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
int t,n,a[250010],b[250010],q;
ull ans;
struct node
{
	int l,r,v;
}ta[1000010],tb[1000010];
void builda(int l,int r,int x)
{
	ta[x].l=l;ta[x].r=r;
	if (l==r){ta[x].v=a[l];return;}
	int mid=(l+r)>>1;
	builda(l,mid,x*2);builda(mid+1,r,x*2+1);
	ta[x].v=max(ta[ls].v,ta[rs].v);
}
void buildb(int l,int r,int x)
{
	tb[x].l=l;tb[x].r=r;
	if (l==r){tb[x].v=b[l];return;}
	int mid=(l+r)>>1;
	buildb(l,mid,x<<1);buildb(mid+1,r,x<<1|1);
	tb[x].v=max(tb[ls].v,tb[rs].v);
}
int querya(int l,int r,int x,int ql,int qr)
{
	if (qr<=l||ql>=r) return 0;
	if (qr>=r&&ql<=l) return ta[x].v;
	int mid=(l+r)>>1,res=0;
	if (ql<=mid) res=max(res,querya(l,mid,ls,ql,qr));
	if (qr>mid) res=max(res,querya(mid+1,r,rs,ql,qr));
	return res;
}
int queryb(int l,int r,int x,int ql,int qr)
{
	if (qr<=l||ql>=r) return 0;
	if (qr>=r&&ql<=l) return tb[x].v;
	int mid=(l+r)>>1,res=0;
	if (ql<=mid) res=max(res,queryb(l,mid,ls,ql,qr));
	if (qr>mid) res=max(res,queryb(mid+1,r,rs,ql,qr));
	return res;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	builda(1,n,1);buildb(1,n,1);
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		int l,r;scanf("%d%d",&l,&r);ans=0;
		for (int i=l;i<=r;i++) ans+=(ull)(a[i])*(ull)(b[i]);
		for (int i=l;i<r;i++)
			for (int j=i+1;j<=r;j++)
				ans+=(ull)(querya(1,n,1,i,j))*(ull)(queryb(1,n,1,i,j));
		printf("%lld\n",ans);
	}
}
