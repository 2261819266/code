#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int f=1,x=0;char c=getchar();
	while(c<'0' or c>'9')
	{if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<=9)
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

const int N=1005;
const LL p=998244353;
int T,n,m,c,f;
bool mp[N][N];char ts[N];
int sumr[N][N],sumu[N][N];//right up
int asumr[N][N];
LL ansc,ansf;
//LL anscmp

signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();
	while(T--)
	{
		int n=read(),m=read(),c=read(),f=read();
		memset(mp,0,sizeof(mp));
		memset(sumr,0,sizeof(sumr));
		memset(sumu,0,sizeof(sumu));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",ts+1);
			for(int j=1;j<=m;++j)
			{
				mp[i][j]=ts[j]-'0';
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=m;j;--j)
			{
				if(!mp[i][j])
				{
					sumr[i][j]=sumr[i][j+1]+1;
				}
			}
		}
		for(int j=1;j<=m;++j)
		{
			for(int i=1;i<=n;++i)
			{
				if(!mp[i][j])
				{
					sumu[i][j]=sumu[i-1][j]+1;
				}
			}
		}
		for(int j=1;j<=m;++j)
		{
			for(int i=1;i<=n;++i)
			{
				if(!mp[i][j])
				{
					asumr[i][j]=asumr[i-1][j]+sumr[i][j];
				}
			}
		}
		for(int j=1;j<=n;++j)
		{
			int tail,head;
			for(int i=n;i;--i)
			{
				if(mp[i][j])
				{
					continue;
				}
				tail=i-sumu[i][j]+1;
				head=i;
				while(i>tail+1)
				{
					LL tans=(asumr[i-2][j]-(i-1-tail))*(sumr[i][j]-1)%p;
					ansc=(ansc+tans)%p;
					ansf=(ansf+(tans*(head-i)%p))%p;
					i++;
				}
			}
		}
	}
	cout<<ansc*c<<' '<<ansf*f;
	return 0;
}

