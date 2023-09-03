#include<bits/stdc++.h>
using namespace std;
long long t,id,n,m,c,f,r[1005][1005],tp,md=998244353,smc[1005][1005],ok[1005][1005];
long long ansc,ansf;
char s[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&id);
	while(t--)
	{
		ansc=ansf=0;
		memset(smc,0,sizeof(smc));
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(long long i=1;i<=n;++i)
		for(long long j=1;j<=m;++j)
		scanf(" %c",&s[i][j]);
		for(long long i=1;i<=n;++i)
		{
			tp=m+1;
			for(long long j=m;j>=1;--j)
			{
				if(s[i][j]=='1')
				tp=j;
				r[i][j]=tp;
			}
		}
		for(long long i=1;i<=m;++i)
		{
			smc[i][1]=max(0LL,r[1][i]-i-1);
			for(long long j=2;j<=n;++j)
			{
				if(r[j][i]!=i)
				smc[i][j]=smc[i][j-1];
				smc[i][j]+=max(r[j][i]-i-1,0LL);
				if(j>=3&&r[j][i]-i>=2&&s[j-1][i]!='1')
				ansc+=(r[j][i]-i-1)*smc[i][j-2],ansc%=md;
			}	 
		}
		for(long long i=1;i<=m;++i)
		{
			tp=n+1;
			for(long long j=n;j>=1;--j)
			{
				if(s[j][i]=='1')
				tp=j;
				ok[j][i]=tp;
			}
		}
		memset(smc,0,sizeof(smc));
		for(long long i=1;i<=m;++i)
		{
			smc[i][1]=max(0LL,r[1][i]-i-1);
			for(long long j=2;j<=n;++j)
			{
				if(r[j][i]!=i)
				smc[i][j]=smc[i][j-1];
				smc[i][j]+=max(r[j][i]-i-1,0LL);
				if(j>=3&&r[j][i]-i>=2&&s[j-1][i]!='1'&&ok[j][i]>j+1)
				ansf+=(r[j][i]-i-1)*smc[i][j-2]*(ok[j][i]-j-1),ansf%=md;
			}	 
		}
		printf("%lld %lld\n",(1LL*c*ansc)%md,(1LL*f*ansf)%md);
	}
	return 0;
}