#include<bits/stdc++.h>
#define N 1100
using namespace std;
bool p[N][N];
long long zhui[3][N][N],len[N][N],anc,anf;
const long long mod=998244353;
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	long long n,m,T,id,a,d,c,f;
	scanf("%lld%lld",&T,&id);
	while(T--)
	{
		anc=anf=0;
		memset(zhui,0,sizeof(zhui));
		memset(len,0,sizeof(len));
		memset(p,false,sizeof(p));
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		{
			scanf("%1d",&a);
			if(a)
			{
				p[i][j]=true;
			}
		}
		for(long long j=1;j<=m;j++)
		{
			d=0;
			for(long long i=n;i>=1;i--)
			{
				if(p[i][j])
				{
					d=0;
					continue;
				}
				d++;
				len[i][j]=d-1;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=m;j>=1;j--)
			{
				if(p[i][j])
				continue;
				zhui[0][i][j]=zhui[0][i][j+1]+1;
			}
		}
		for(long long j=1;j<=m;j++)
		for(long long i=n;i>=1;i--)
		{
			if(p[i][j])continue;
			zhui[1][i][j]=(zhui[1][i+1][j]+len[i][j]*(zhui[0][i][j]-1))%mod;
			zhui[2][i][j]=(zhui[2][i+1][j]+zhui[0][i][j]-1)%mod;
		}
		for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		if((!p[i][j])&&(!p[i+1][j])&&(!p[i+2][j]))
		{
			anc=(anc+(zhui[0][i][j]-1)*zhui[2][i+2][j])%mod;
			anf=(anf+(zhui[0][i][j]-1)*zhui[1][i+2][j])%mod;
		}
		printf("%lld %lld\n",anc,anf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}