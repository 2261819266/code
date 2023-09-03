#include<bits/stdc++.h>
using namespace std;
const long long MOD=4611686018427387904;
long long T,n;
long long a[250005],b[250005];
long long Q;
long long l,r;
long long ans=0;
long long findA(int x,int y)
{
	long long maxx=-1;
	for(int i=x;i<=y;i++)
	{
		maxx=max(maxx,a[i]);
	}
	return maxx;
}
long long findB(int x,int y)
{
	long long maxx=-1;
	for(int i=x;i<=y;i++)
	{
		maxx=max(maxx,b[i]);
	}
	return maxx;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	scanf("%lld",&Q);
	while(Q--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				ans+=((findA(i,j)%MOD)*(findB(i,j)%MOD))%MOD;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}