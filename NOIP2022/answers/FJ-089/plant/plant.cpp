#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const long long mod=998244353;
int n,m,T,id;
long long c,f,dp[N][N][8],ansc,ansf;
char mp[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				for(int o=0;o<=4;++o)
					dp[i][j][o]=0;
		ansc=0;
		ansf=0;
		for(int i=1;i<=n;++i)
			scanf("%s",mp[i]+1);
		for(int i=n;i>=1;--i)
			for(int j=m;j>=1;--j)
			{
				if(mp[i][j]=='1')
					continue ;
				if(j!=m&&mp[i][j+1]=='0')
				{
					dp[i][j][0]=1;
					dp[i][j][0]=(dp[i][j][0]+dp[i][j+1][0])%mod;
				}
				if(i!=n&&mp[i+1][j]=='0')
				{
					dp[i][j][1]=1;
					dp[i][j][1]=(dp[i][j][1]+dp[i+1][j][1])%mod;
				}
//				printf("%d %d: %lld %lld\n",i,j,dp[i][j][0],dp[i][j][1]);
			}
		for(int i=3;i<=n;++i)
			for(int j=1;j<m;++j)
			{
				if(mp[i][j]=='1')
					continue ;
				if(mp[i-1][j]=='0'&&mp[i-2][j]=='0')
				{
					dp[i][j][2]=(dp[i][j][2]+dp[i-1][j][2])%mod;
					dp[i][j][2]=(dp[i][j][2]+dp[i-2][j][0])%mod;
				}
//				printf("%d %d : %lld \n",i,j,dp[i][j][2]);
				ansc=(ansc+dp[i][j][2]*dp[i][j][0])%mod;
				ansf=(ansf+(dp[i][j][2]*dp[i][j][0]%mod)*dp[i][j][1])%mod;
			}
		printf("%lld %lld\n",(ansc*c)%mod,(ansf*f)%mod);
	}
	return 0;
}
