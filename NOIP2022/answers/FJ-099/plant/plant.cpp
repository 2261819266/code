#include <cstdio>
#include <iostream>
using namespace std;

const int mod=998244353;

int T,id,n,m,c,f;
long long vc,vf;
char map[1005][1005];
int ri[1005][1005],dn[1005][1005];
long long dp[1005][1005];

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for (int i=1; i<=n; i++)
			scanf("%s",map[i]+1);
			
		for (int i=1; i<=n; i++)
		{
			ri[i][m+1]=-1;
			for (int j=m; j>0; j--)
				if (map[i][j]=='1')
					ri[i][j]=-1;
				else
					ri[i][j]=ri[i][j+1]+1;
		}
		for (int j=1; j<=m; j++)
		{
			dn[n+1][j]=-1;
			for (int i=n; i>0; i--)
				if (map[i][j]=='1')
					dn[i][j]=-1;
				else
					dn[i][j]=dn[i+1][j]+1;
		}
		
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				if (map[i][j]=='1')
				{
					dp[i][j]=0;
					continue; 
				} 
				if (map[i-1][j]=='0')
				{
					dp[i][j]=dp[i-1][j];
					dp[i][j]+=ri[i-1][j];
				}
				dp[i][j]%=mod;
				vc+=dp[i-1][j]*ri[i][j],vc%=mod;
				vf+=dp[i-1][j]*ri[i][j]*dn[i][j],vf%=mod;
			}
		cout<<c*vc<<' '<<f*vf; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//什么精心构造的粪样例（恼） 
