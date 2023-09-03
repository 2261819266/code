#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=25e4+5;
LL id,n,m,a[N],b[N],bz[N][25],bz1[N][25];
inline LL ask1(int l,int r){int t=__lg(r-l+1);return max(bz[l][t],bz[r-(1<<t)+1][t]);}
inline LL ask2(int l,int r){int t=__lg(r-l+1);return max(bz1[l][t],bz1[r-(1<<t)+1][t]);}
int main()
{
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	scanf("%lld%lld",&id,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&bz[i][0]);
	for(int i=1;i<=n;i++) scanf("%lld",&bz1[i][0]);
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			bz[j][i]=max(bz[j][i-1],bz[j+(1<<(i-1))][i-1]),
			bz1[j][i]=max(bz1[j][i-1],bz1[j+(1<<(i-1))][i-1]);
	scanf("%lld",&m);LL l,r;
	while(m--)
	{
		scanf("%lld%lld",&l,&r);LL ans=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
				ans+=ask1(p,q)*ask2(p,q);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
