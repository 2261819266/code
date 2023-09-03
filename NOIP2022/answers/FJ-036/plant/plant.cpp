#include<cstdio>
#include<cstring>
using namespace std;
int n,m,C,F,T,id;
long long sum[1010][1010],sum1[1010][1010],f[1010][1010],g[1010][1010];
char mp[1010][1010];
long long mod=998244353,ansc,ansf;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	for(int o=1;o<=T;++o) 
	{
		scanf("%d%d%d%d",&n,&m,&C,&F);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(sum,0,sizeof(sum));
		memset(sum1,0,sizeof(sum1));
		for(int i=1;i<=n;++i)  scanf("%s",mp[i]+1);
		for(int i=1;i<=n;++i) 
		{
			for(int j=m;j>=1;--j) 
			{
				if(mp[i][j]=='0') f[i][j]=f[i][j+1]+1;
				else f[i][j]=0;
			}	
		}
		for(int j=1;j<=m;++j) 
		{
			for(int i=n;i>=1;--i) 
			{
				if(f[i][j]>1) sum[i][j]=sum[i+1][j]+f[i][j]-1;
				else sum[i][j]=sum[i+1][j];
				if(mp[i][j]=='0') g[i][j]=g[i+1][j]+1;
				else g[i][j]=0;
			}
		}
		for(int j=1;j<=m;++j) 
		    for(int i=n-1;i>=1;--i) 
		    	if(mp[i][j]=='0') sum1[i][j]=(sum1[i+1][j]+(g[i][j]-1)*(f[i][j]-1)%mod)%mod;
		//‘§¥¶¿Ì
		for(int j=1;j<m;++j) 
		{
			for(int i=1;i<n-1;++i) 
			{
				if(g[i][j]>2&&f[i][j]>1) 
				{
				ansc=(ansc+(f[i][j]-1)*(sum[i+2][j]-sum[i+g[i][j]][j]%mod))%mod;	
			//	printf("%d %d %d \n",i,j,sum[i+g[i][j]-1][j]-sum[i+1][j]);
				}	
			    if(i+2<n&&f[i][j]>1&&g[i][j]>2) 
				{
					ansf=(ansf+sum1[i+2][j]*(f[i][j]-1)%mod)%mod;
				//	printf("%d %d ",sum1[i+2][j],sum1[i+2][j]*(f[i][j]-1));
				}
			}
		}
	    if(C==1) printf("%lld ",ansc);
	    else printf("0 ");
	    if(F==1) printf("%lld\n",ansf);
	    else printf("0\n");
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

1 0
6 6 1 1
000010
011000
000110
010000
011000
000000

*/
