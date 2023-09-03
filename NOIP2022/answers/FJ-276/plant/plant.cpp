#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=1010;
const int MOD=998244353;

int a[N][N],fx[N][N],fy[N][N],sum[N][N],sum2[N][N];

char s[N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	int t,id,n,m,c,f;long long sc,sf;scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(int j=1;j<=n;j++)
			{
				if(s[j-1]=='1')a[i][j]=1;
				else a[i][j]=0;
			} 
		}
		
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==0)
				{
					fx[i][j]=1;
					if(j!=m)fx[i][j]+=fx[i][j+1];				
				}
				else fx[i][j]=0;
			}
		for(int j=1;j<=m;j++)
			for(int i=n;i>=1;i--)
			{
				if(a[i][j]==0)
				{
					fy[i][j]=1;
					if(i!=n)fy[i][j]+=fy[i+1][j];
				}
				else fy[i][j]=0;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(fx[i][j])fx[i][j]--;
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				sum[i][j]=(sum[i-1][j]+fx[i][j])%MOD; 
		
		sc=sf=0;
		if(c==1)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(fy[i][j]>2)
						sc=(sc+(long long)fx[i][j]*(sum[i+fy[i][j]-1][j]-sum[i+1][j]))%MOD;	
		}
		if(f==1)
		{
			for(int j=1;j<=m;j++)
				for(int i=1;i<=n;i++)
					sum2[i][j]=(sum2[i-1][j]+fx[i][j]*(fy[i][j]-1));
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(fy[i][j]>3)
						sf=(sf+(long long)fx[i][j]*(sum2[i+fy[i][j]-2][j]-sum2[i+1][j]))%MOD;
		}
		
		printf("%lld %lld",sc,sf);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
