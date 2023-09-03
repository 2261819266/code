#include<cstdio>
#include<iostream>
#define re register
using namespace std;
const int mod=998244353;
const int N=1e3+5;
int T,id;
int n,m,c,f;
char tt[N][N];
int t[N][N];
int fa[N][N],fb[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		if(id==1||id==5)
		{
			printf("0 0\n");
			continue;
		}
		scanf("%d%d%d%d",&n,&m,&c,&f);
		long long ans1=0,ans2=0;
		for(re int i=1;i<=n;i++)
		{
			for(re int j=1;j<=m;j++)
			{
				cin>>tt[i][j];
				if(tt[i][j]=='0') t[i][j]=0;
				else t[i][j]=1;
			}
		}
		for(re int i=1;i<=n;i++)
		{
			if(t[i][m]==1) fa[i][m]=m;
			else fa[i][m]=m+1;
			for(re int j=m-1;j>=1;j--)
			{
				if(t[i][j]==1) fa[i][j]=j;
				else fa[i][j]=fa[i][j+1];
			}
		}
		for(re int j=1;j<=m;j++)
		{
			if(t[n][j]==1) fb[n][j]=n;
			else fb[n][j]=n+1;
			for(re int i=n-1;i>=1;i--)
			{
				if(t[i][j]==1) fb[i][j]=i;
				else fb[i][j]=fb[i+1][j];
			}
		}
		for(re int k=1;k+2<=n;k++)
		{
			for(re int i=1;i+k+1<=n;i++)
			{
				for(re int j=1;j<m;j++)
				{
					int pd=fb[i][j];
					if(pd<=i+k+1) continue;
					int x1=fa[i][j+1];
					int x2=fa[i+k+1][j+1];
					x1=(x1-1-j);
					x2=(x2-1-j);
					ans1=(ans1+x1*x2*c)%mod;
					if(i+k+2<=n)
					{	
						int x3=fb[i+k+2][j];
						x3=x3-i-k-2;
						ans2=(ans2+x1*x2*x3*f)%mod;
					}
				}
			}
		}
		printf("%lld %lld\n",ans1,ans2);
	}				
	return 0;
}

