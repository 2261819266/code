#include<cstdio>
#include<iostream>
#define root 1,n,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef unsigned long long ull;
const ull N=250010;
ull T,n,a[N],b[N],Q,ans,l,r,mod=1;
struct tree{ull maxn;};
tree t[N<<2][2];
void push_up(ull rt,ull d)
{
	t[rt][d].maxn=max(t[rt<<1][d].maxn,t[rt<<1|1][d].maxn);
	return;
}
void build(ull l,ull r,ull rt,ull d)
{
	if(l==r)
	{
		scanf("%lld",&t[rt][d].maxn);
		return;
	}
	ull mid=(l+r)>>1;
	build(lson,d);
	build(rson,d);
	push_up(rt,d);
	return;
}
ull query(ull l,ull r,ull rt,ull L,ull R,ull d)
{
	if(L<=l&&r<=R) return t[rt][d].maxn;
	ull mid=(l+r)>>1,f1=0,f2=0;
	if(L<=mid) f1=query(lson,L,R,d);
	if(R>mid) f2=query(rson,L,R,d);
	return max(f1,f2);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	build(root,0);
	build(root,1);
	scanf("%lld",&Q);
	while(Q--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(ull p=l;p<=r;p++)
			for(ull q=p;q<=r;q++)
				ans+=(query(root,p,q,0)*query(root,p,q,1));
		printf("%lld\n",ans);
	}
	return 0;
}
