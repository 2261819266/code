#include<bits/stdc++.h>
using namespace std;
long long t,id,n,m,c,f;
long long sum,ans,d[1005][1005],p[1005][1005],mod=998244353;
char a[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&id);
	while(t--)
	{
		sum=ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<=m;j++)
				if(a[i][j-1]-'0'==0)
				{
					d[i][j]++;
					p[i][j]++;
					if(d[i][j-1]!=0) d[i][j]+=d[i][j-1];
				}
		}
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=m;j++)
				if(a[i][j-1]-'0'==0)
					if(p[i+1][j]!=0) p[i][j]+=p[i+1][j];
		for(int i=1;i<=n-2;i++)
		{
			for(int k=m;k>=2;k--)
			{
				if(d[i][k]<=1) continue;
				for(int j=i+2;j<=n;j++)
				{
					for(int v=k-d[i][k]+1;v<=k-1;v++)
					{
						if(i+p[i][v]-1<j) continue;
						for(int u=m;u>=v+1;u--)
						{
							if(d[j][u]<=1) continue;
							if(u-d[j][u]+1<=k-d[i][k]+1)
							{
								sum=(sum+(k-v)%mod*((u-v)%mod))%mod;
								ans=(ans+(k-v)%mod*((u-v)%mod)*(i+p[i][v]-j-1))%mod;
								break;
							}
							u-=d[j][u];
						}
					}
				}
				k-=d[i][k];
			}
		}
		printf("%lld %lld\n",sum*c%mod,ans*f%mod);
	}
	return 0;
}
