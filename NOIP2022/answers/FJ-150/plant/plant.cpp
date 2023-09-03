#include<bits/stdc++.h>
#define Re register
#define ll long long
using namespace std;

const int N=1005,mod=998244353;

int T,id;

int n,m,c,f;

char ch[N][N];

int a[N][N];

int p[N][N],q[N][N];

int xn[N][N],xm[N][N];

ll sn[N][N],tn[N][N];

ll ansc,ansf;

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(Re int i=1;i<=n;i++)
		{
			for(Re int j=1;j<=m;j++)
			{
				a[i][j]=0;
				p[i][j]=0;
				q[i][j]=0;
				xn[i][j]=0;
				xm[i][j]=0;
				sn[i][j]=0;
				tn[i][j]=0;
			}
		}
		ansc=0;
		ansf=0;
		for(Re int i=1;i<=n;i++)
		{
			scanf("%s",ch[i]+1);
			for(Re int j=1;j<=m;j++)
			{
				a[i][j]=ch[i][j]-'0';
			}
		}
		for(Re int i=1;i<=n;i++)
		{
			int now=0;
			for(Re int j=1;j<=m;j++)
			{
				if(a[i][j]==0&&(a[i][j-1]==1||j==1)) now=j;
				if(a[i][j]==0) p[i][now]++,xn[i][j]=now;
			}
		}
		for(Re int j=1;j<=m;j++)
		{
			int now=0;
			for(Re int i=1;i<=n;i++)
			{
				if(a[i][j]==0&&(a[i-1][j]==1||i==1)) now=i;
				if(a[i][j]==0) q[now][j]++,xm[i][j]=now;
			}
		}
		for(Re int j=1;j<=m;j++)
		{
			for(Re int i=1;i<=n;i++)
			{
				if(a[i][j]==0) sn[i][j]=(sn[i-1][j]+(p[i][xn[i][j]]-(j-xn[i][j])-1))%mod;
			}
		}
		for(Re int j=1;j<=m;j++)
		{
			for(Re int i=1;i<=n;i++)
			{
				if(a[i][j]==0) tn[i][j]=(tn[i-1][j]+1ll*(p[i][xn[i][j]]-(j-xn[i][j])-1)*(q[xm[i][j]][j]-(i-xm[i][j]+1))%mod)%mod;
			}
		}
		for(Re int i=1;i<=n;i++)
		{
			for(Re int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					if(q[xm[i][j]][j]-(i-xm[i][j])-1>1)
					{
						ansc=(ansc+1ll*(p[i][xn[i][j]]-(j-xn[i][j])-1)*(sn[i+(q[xm[i][j]][j]-(i-xm[i][j])-1)][j]-sn[i+1][j])%mod)%mod;
					}
				}
			}
		}
		for(Re int i=1;i<=n;i++)
		{
			for(Re int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					if(q[xm[i][j]][j]-(i-xm[i][j])-2>1)
					{
						ansf=(ansf+1ll*(p[i][xn[i][j]]-(j-xn[i][j])-1)*(tn[i+(q[xm[i][j]][j]-(i-xm[i][j])-2)][j]-tn[i+1][j])%mod)%mod;
					}
				}
			}
		}
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
	return 0;
}
