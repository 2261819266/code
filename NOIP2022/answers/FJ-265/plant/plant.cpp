#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

const int MOD=998244353;
const int MX=1015;
int T,id,n,m,c,f;
int MAP[MX][MX];
int r[MX][MX],dh[MX][MX];
long long ansc=0,ansf=0;

bool bcheck(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m)return true;
	return false;
}

void init()
{
	string str;
	n=read(),m=read(),c=read(),f=read();
	ansc=0,ansf=0;
	memset(MAP,0,sizeof(MAP));
	memset(r,0,sizeof(r));
	memset(dh,0,sizeof(dh));
	for(int i=1;i<=n;++i)
	{
		cin>>str;
		for(int j=0;j<m;++j)
		{
			MAP[i][j+1]=str[j]-'0';
		}
		
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=1;--j)
		{
			if(MAP[i][j]==1) r[i][j]=0;
			else r[i][j]=r[i][j+1]+1;
		}
	}
	for(int j=1;j<=m;++j)
	{
		for(int i=n;i>=1;--i)
		{
			if(MAP[i][j]==1)dh[i][j]=0;
			else dh[i][j]=dh[i+1][j]+1;
		}
	}
	return;	
}

void solvec()
{
	int upc,domnc;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(r[i][j]>=1&&r[i+1][j]>=1)
			{
				upc=r[i][j]-1;
				for(int k=i+2;k<=n && r[k][j]>=1;++k)
				{
					domnc=r[k][j]-1;
					ansc+=(upc*domnc);
					ansc%=MOD;
				}
			}
		}
	}
	printf("%lld ",ansc*c);
	return;
}

void solvef()
{
	int upf,domnf;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(r[i][j]>=1&&r[i+1][j]>=1)
			{
				upf=r[i][j]-1;
				for(int k=i+2;k<=n && r[k][j]>=1 && r[k+1][j]>=1;++k)
				{
					
					domnf=r[k][j]-1;
					ansf+=(upf*domnf*dh[k+1][j]);
					ansf%=MOD;
				}
			}
		}
	}
	printf("%lld\n",ansf*f);
	return;
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	for(int i=1;i<=T;++i)
	{
		init();
		if(c==0) printf("%d ",0);
		else solvec();
		if(f==0) printf("%d\n",0);
		else solvef();
	}
	return 0;
}
