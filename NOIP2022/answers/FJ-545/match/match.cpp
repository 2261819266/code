#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=250005;
struct node
{
	int l,r,w;
}tra[N<<2],trb[N<<2];
int T,n,q;
int a[N],b[N];
void build(node tr[],int a[],int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)
	{
		tr[u].w=a[l];
		return;
	}
	int mid=l+r>>1;
	build(tr,a,u<<1,l,mid);
	build(tr,a,u<<1|1,mid+1,r);
	tr[u].w=max(tr[u<<1].w,tr[u<<1|1].w);
}
int query(node tr[],int u,int l,int r,int L,int R)
{
	if(L<=tr[u].l&&tr[u].r<=R)return tr[u].w;
	int mid=l+r>>1,res=0;
	if(L<=mid)res=max(res,query(tr,u<<1,l,mid,L,R));
	if(R>mid)res=max(res,query(tr,u<<1|1,mid+1,r,L,R));
	return res;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	build(tra,a,1,1,n);
	build(trb,b,1,1,n);
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ULL res=0;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)res+=1ULL*query(tra,1,1,n,p,q)*query(trb,1,1,n,p,q);
		}
		printf("%llu\n",res);
	}
	return 0;
}
