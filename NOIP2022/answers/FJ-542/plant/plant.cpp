#include <bits/stdc++.h>

using namespace std;
const long long Mod = 998244353;
int n,m,c,f;
int a[1010][1010];
long long ansc,ansf;
int sum[1010][1010];
int dp[1010][1010];
int t;
int id;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while (t--){
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		ansc = 0,ansf = 0;
		for (int i=1;i<=n;++i)
	    {
	    	for (int j=1;j<=m;++j)
	    	{
	    		char ch;
	    		cin>>ch;
	    		a[i][j]=ch-'0';
			}
		}
		for (int i=1;i<=n;++i)
		{
			int k = 0;
			for (int j=m;j>=1;--j)
			{
				if (a[i][j] == 1)
			    	k=0;
				else k++;
				sum[i][j]=k;
			}
		}
		for (int j=1;j<=m;++j)
		{
			int k=0;
			for (int i=n;i>=0;--i)
			{
				if (a[i][j] == 1)
				    k=0;
				else k++;
				dp[i][j]=k;
			}
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				if (dp[i][j]<3)    continue;
				if (sum[i][j] < 2)    continue;
				for (int k = i+2;a[k][j] != 1 && k <= n;++k)
				{
					if (sum[k][j] < 2)   continue;
					long long node = 1LL*(sum[i][j]-1)*(sum[k][j]-1)%Mod;
					if (c != 0)    ansc = 1LL*(ansc+node)%Mod;
					if (f != 0)    ansf = 1LL*(ansf+(node*(dp[k][j]-1)%Mod)%Mod);
				}
			}
		}
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
