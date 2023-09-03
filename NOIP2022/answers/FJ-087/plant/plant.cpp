#include<bits/stdc++.h>
#define R register
#define int long long
//printf("%lld\n",);
const int maxn=1005;
const int mod=998244353;//Don't forget
using namespace std;
int n,m,cnth[maxn][maxn],cntl[maxn][maxn];
int t,id,c,f;
int ansc,ansf;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	while(t--)
	{
		n=read(),m=read(),c=read(),f=read();
		for(R int i=0;i<=n+1;i++)
		for(R int j=0;j<=m+1;j++)
		{
			cnth[i][j]=0;
			cntl[i][j]=0;
		}
		ansc=0;
		ansf=0;
		for(R int i=1;i<=n;i++)
		{
			char s[maxn];
			scanf("%s",s+1);
			for(R int j=m;j>=1;j--)
			if(s[j]=='0')
			cnth[i][j]=cnth[i][j+1]+1;
		}
		for(R int i=n;i>=1;i--)
		for(R int j=1;j<=m;j++)
		if(cnth[i][j])
		cntl[i][j]=cntl[i+1][j]+1;
		/*for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		printf("%lld %lld %lld %lld\n",i,j,cnth[i][j],cntl[i][j]);*/
		if(c)
		{
			for(R int i=1;i<=n;i++)
			{
				for(R int j=1;j<=m;j++)
				if(cnth[i][j]>=2&&cntl[i][j]>=3)
				{
					//printf("%lld %lld\n",i,j);
					for(R int k=i+2;k<=n;k++)
					{
						if(!cnth[k][j])
						break;
						if(cnth[k][j]>=2)
						ansc=(ansc+(cnth[i][j]-1)*(cnth[k][j]-1)%mod)%mod;
					}
				}
			}
		}
		if(f)
		{
			for(R int i=1;i<=n;i++)
			{
				for(R int j=1;j<=m;j++)
				if(cnth[i][j]>=2&&cntl[i][j]>=4)
				{
					//printf("%lld %lld\n",i,j);
					for(R int k=i+2;k<=n;k++)
					{
						if(!cnth[k][j]||!cnth[k+1][j])
						break;
						if(cnth[k][j]>=2)
						ansf=(ansf+(cntl[k][j]-1)*(cnth[i][j]-1)*(cnth[k][j]-1)%mod)%mod;
					}
				}
			}
		}
		printf("%lld %lld\n",ansc%mod,ansf%mod);
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
*/
