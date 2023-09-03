#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,C,F;
char a[1100][1100];
long long hmax[1100][1100],lmax[1100][1100],sum[1100][1100],mod=998244353,f[1100][1100];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)
		{
			if(a[i][m]=='0')hmax[i][m]=1;
			else hmax[i][m]=0;
			for(int j=m-1;j>=1;--j)
			{
				if(a[i][j]=='1')hmax[i][j]=0;
				else hmax[i][j]=1+hmax[i][j+1];
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(a[n][i]=='0')lmax[i][n]=1;
			else lmax[i][n]=0;
			for(int j=n-1;j>=1;--j)
			{
				if(a[j][i]=='1')lmax[i][j]=0;
				else lmax[i][j]=1+lmax[i][j+1];
			}
		}
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)sum[i][j]=sum[i-1][j];
			for(int j=1;j<=m;++j)if(hmax[i][j])sum[i][j]=(sum[i][j]+hmax[i][j]-1)%mod;
		}
		long long ans=0;
		for(int i=1;i<=n-2;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(i+lmax[j][i]-1>=i+2&&hmax[i][j])ans=(ans+(hmax[i][j]-1LL)*((sum[i+lmax[j][i]-1][j]-sum[i+1][j])%mod+mod)%mod);
			}
		}
		if(C==1)printf("%lld ",ans);
		else printf("0 ");
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n-1;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(lmax[j][i]&&hmax[i][j])f[i][j]=((lmax[j][i]-1LL)*(hmax[i][j]-1LL))%mod;
			}
		}
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)sum[i][j]=sum[i-1][j];
			for(int j=1;j<=m;++j)sum[i][j]=(sum[i][j]+f[i][j])%mod;
		}
		for(int i=1;i<=n-2;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(i+lmax[j][i]-1>=i+2&&hmax[i][j])
				{
					ans=(ans+(hmax[i][j]-1LL)*((sum[i+lmax[j][i]-1][j]-sum[i+1][j])%mod+mod)%mod);
				}
			}
		}
		if(F)printf("%lld\n",ans);
		else printf("0\n");
	}
}