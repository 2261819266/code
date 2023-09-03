#include<bits/stdc++.h>
#define N 1080
#define inf 0x3f3f3f3f
#define mod 998244353
#define LL long long
using namespace std;
int read()
{
	char c=getchar();
	int re=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		re=(re<<1)+(re<<3)+(c&15);
		c=getchar();
	}
	return re;
}
bool readbl()
{
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	return c&15;
}
int T,id;
int n,m,c,f,g[N][N],gi[N][N],gj[N][N];
LL gc[N][N],gf[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();
	id=read();
	if(id==1)
		while(T--)
			printf("0 0\n");
	while(T--)
	{
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				g[i][j]=readbl();
				gi[i][j]=g[i][j]?i:inf;
				gj[i][j]=g[i][j]?j:inf;
			}
		for(int i=1;i<=n;i++)
			gj[i][m+1]=m+1;
		for(int i=1;i<=m;i++)
			gi[n+1][i]=n+1;
		for(int i=n;i;i--)
			for(int j=m;j;j--)
			{
				gi[i][j]=min(gi[i][j],gi[i+1][j]);
				gj[i][j]=min(gj[i][j],gj[i][j+1]);
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				gi[i][j]=gi[i][j]-1-i;
				gj[i][j]=gj[i][j]-1-j;
			}
		for(int i=n-2;i;i--)
			for(int j=m;j;j--)
			{
				if(!g[i+1][j])
				{
					gc[i][j]=gj[i+2][j];
					gf[i][j]=gj[i+2][j];
					if(gc[i][j]>=0)
					{
						if(gc[i+1][j]>=0)
							gc[i][j]+=gc[i+1][j];
						gf[i][j]*=gi[i+2][j];
						if(gf[i+1][j]>=0)
							gf[i][j]+=gf[i+1][j];
					}
				}
			}
		LL vc=0,vf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				LL v1=gj[i][j];
				if(v1>0)
				{
					vc=(vc+v1*gc[i][j])%mod;
					vf=(vf+v1*gf[i][j])%mod;
				}
			}
		}
		printf("%lld %lld\n",vc*c,vf*f);
	}
}
