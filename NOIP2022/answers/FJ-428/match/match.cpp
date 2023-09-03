#include<bits/stdc++.h>
using namespace std;
long long a[250001];
long long b[250001];
long long tree[3][1000001];
void build(long long u,long long l,long long r,long long o)
{
	if(l==r)
	{
		if(o==1)
		tree[o][u]=a[l];
		else tree[o][u]=b[l];
		return ;
	}
	long long mid=(l+r)/2;
	build(u*2,l,mid,o);
	build(u*2+1,mid+1,r,o);
	tree[o][u]=max(tree[o][u*2],tree[o][u*2+1]);
}
long long fin(long long u,long long l,long long r,long long p,long long q,long long o)
{
	if(l>=p&&r<=q)return tree[o][u];
	long long mid=(l+r)/2;
	long long maxn=-100000;
	if(mid>=p)
	maxn=max(maxn,fin(u*2,l,mid,p,q,o));
	if(mid+1<=q)
	maxn=max(maxn,fin(u*2+1,mid+1,r,p,q,o));
	return maxn;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long T,n;
	scanf("%lld%lld",&T,&n);
	for(long long i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	build(1,1,n,1);
	for(long long i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	build(1,1,n,2);
	long long Q,l,r;
	scanf("%lld",&Q);
	long long s;
	while(Q--)
	{
		s=0;
		scanf("%lld%lld",&l,&r);
		for(long long q=l;q<=r;q++)
		for(long long p=q;p<=r;p++)
			s+=fin(1,1,n,q,p,1)*fin(1,1,n,q,p,2);
		printf("%lld\n",s);
	}
	return 0;
}
