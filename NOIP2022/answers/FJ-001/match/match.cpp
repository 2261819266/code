#include<bits/stdc++.h>
using namespace std;
long long sta[23][250005],stb[23][250005],a[250005],b[250005],T,n,Q;
long long MAX(long long x,long long y)
{
	if(x>y)return x;
	else return y;
}
long long mx1(long long l,long long r)
{
	long long len=log2(r-l+1);
	return MAX(sta[len][l],sta[len][l+r-(l-1+(1<<len))]);
}
long long mx2(long long l,long long r)
{
	long long len=log2(r-l+1);
	return MAX(stb[len][l],stb[len][l+r-(l-1+(1<<len))]);
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
	for(int i=1;i<=n;++i)
	{
		sta[0][i]=a[i];
		stb[0][i]=b[i];
	}
	for(int i=1;i<23;++i)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			sta[i][j]=MAX(sta[i-1][j],sta[i-1][j+(1<<i-1)]);
			stb[i][j]=MAX(stb[i-1][j],stb[i-1][j+(1<<i-1)]);
		}
	}
	while(Q--)
	{
		long long ans=0;
		long long l,r;
		scanf("%lld%lld",&l,&r);	
		for(long long k=0;k<=r-l;k++)
		{
			for(long long i=l;i+k<=r;i++)
			{
			
				long long _=mx1(i,i+k);
				long long __=mx2(i,k+i);
				ans+=_*__;
			}
		}
		printf("%lld\n",ans);
	}
}
