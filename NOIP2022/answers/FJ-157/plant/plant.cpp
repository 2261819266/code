#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1000+5;
const int Mod=998244353;
int T,n,m,iid,ansc,ansf,sum[N],a[N][N],c[N][N];
char s[N];
int main()
{	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&iid);
	while(T--)
	{	int cc,ff;
		ansc=ansf=0,memset(a,0,sizeof(a)),memset(c,0,sizeof(c));
		scanf("%d%d%d%d",&n,&m,&cc,&ff);
		for(int i=1;i<=n;i++)
		{	scanf("%s",s+1);
			for(int j=1;j<=m;j++)a[i][j]=s[j]-'0';
		}
		for(int i=1;i<=n;i++)
		{	c[i][m+1]=0;
			for(int j=m;j>=1;j--)
			{	if(a[i][j])c[i][j]=0;
				else c[i][j]=c[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++)
		{	for(int i=1;i<=n;i++)sum[i]=0;
			for(int i=1,r;i<=n;i++)
			{	if(c[i][j]==0)continue;
				r=i,sum[i]=c[i][j]-1;
				while(r<n&&c[r+1][j])r++;
				for(int k=i+1;k<=r;k++)sum[k]=sum[k-1]+c[k][j]-1;
				for(int k=i+2;k<=r;k++)ansc=(ansc+1ll*(c[k][j]-1)*sum[k-2]%Mod)%Mod;
				for(int k=i+2;k<r;k++)ansf=(ansf+1ll*(c[k][j]-1)*sum[k-2]%Mod*(r-k)%Mod)%Mod;
				i=r;
			}
		}
		printf("%d %d\n",ansc*cc,ansf*ff);
	}
	return 0;
}
