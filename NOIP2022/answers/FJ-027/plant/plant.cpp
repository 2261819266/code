#include<bits/stdc++.h>
#define MOD 998244353
#define N 1010
using namespace std;
int m,n,c,f,T,id,stk[N],tp,fo[N][N];
long long sum[2][N][N];
long long val[2][N][N];
long long ansc,ansf;
char g[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;++i) scanf("%s",g[i]+1);
		for(int i=1;i<=n;++i)
		{
			tp=0;
			for(int j=1;j<=m;++j)
			{
				if(g[i][j]=='0') stk[++tp]=j;
				else
				{
					int now=0;
					while(tp) val[0][i][stk[tp--]]=now++;
				}
			}	
			int now=0;
			while(tp) val[0][i][stk[tp--]]=now++;
		}
		for(int j=1;j<=m;++j)
		{
			tp=0;
			for(int i=1;i<=n;++i)
			{
				if(g[i][j]=='0') stk[++tp]=i;
				else
				{
					int now=0;
					while(tp) fo[stk[tp]][j]=i,val[1][stk[tp--]][j]=now++;
				}
			}	
			int now=0;
			while(tp) val[1][stk[tp--]][j]=now++;
		}
		for(int j=1;j<=m;++j)
		{
			for(int i=n;i>=1;--i)
			{
				sum[0][i][j]=(sum[0][i+1][j]+val[0][i][j])%MOD;
				sum[1][i][j]=(sum[1][i+1][j]+val[0][i][j]*val[1][i][j]%MOD)%MOD;
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(fo[i][j]<=i+2&&fo[i][j]) continue;
				ansc=(ansc+val[0][i][j]*(sum[0][i+2][j]-sum[0][fo[i][j]][j]+MOD)%MOD)%MOD;
				ansf=(ansf+val[0][i][j]*(sum[1][i+2][j]-sum[1][fo[i][j]][j]+MOD)%MOD)%MOD;
			}
		}
		printf("%lld %lld\n",1ll*c*ansc,1ll*f*ansf);
	}
	return 0;
}
