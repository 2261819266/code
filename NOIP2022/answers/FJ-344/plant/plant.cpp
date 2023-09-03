#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1100,mod=998244353;
int t,n,m,c,f,dwn[N][N],ans_dc[N][N],ans_c[N][N],ans_df[N][N],ans_f[N][N],lft[N][N],ansc,ansf;
char mp[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%*d",&t);
	while (t--)
	{
		memset(dwn,0,sizeof(dwn));
		memset(ans_dc,0,sizeof(ans_dc));
		memset(ans_c,0,sizeof(ans_c));
		memset(ans_df,0,sizeof(ans_df));
		memset(ans_f,0,sizeof(ans_f));
		memset(lft,0,sizeof(lft));
		memset(mp,32,sizeof(mp));
		ansc=ansf=0;
		
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if (c==0&&f==0) {puts("0"); continue; }
		for (int i=1;i<=n;i++)
		{
			scanf("%*c");
			for (int j=1;j<=m;j++)
				scanf("%c",&mp[i][j]);
		}
		for (int i=n;i;i--)
			for (int j=m;j;j--)
				if (mp[i][j]=='0')
				{
					dwn[i][j]=dwn[i+1][j]+1,lft[i][j]=lft[i][j+1]+1;
				}
		
//		ans :C
		for (int i=n;i;i--)
			for (int j=m;j;j--)
			{
				if (mp[i][j]=='1') continue;
				ans_dc[i][j]=(ans_dc[i+1][j]+lft[i][j]-1)%mod;
				
				if (mp[i+1][j]=='0'&&mp[i+2][j]=='0')
					ans_c[i][j]=(ll)ans_dc[i+2][j]*(lft[i][j]-1)%mod;
			}
		
//		ans :F
		for (int i=n;i;i--)
			for (int j=m;j;j--)
			{
				if (mp[i][j]=='1') continue;
				ans_df[i][j]=(ans_df[i+1][j]+(ll)(lft[i][j]-1)*(dwn[i][j]-1)%mod)%mod;
				if (mp[i+1][j]=='0'&&mp[i+2][j]=='0')
					ans_f[i][j]=(ll)ans_df[i+2][j]*(lft[i][j]-1)%mod;
			}
		
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				ansc=(ansc+ans_c[i][j])%mod,ansf=(ansf+ans_f[i][j])%mod;
		
		printf("%d %d\n",ansc*c,ansf*f);
	}
	return 0;
}
