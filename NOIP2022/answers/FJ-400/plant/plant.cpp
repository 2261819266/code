#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
const int mod=998244353;
int read()
{
	int x=0,y=1;char ch;
	do{ch=getchar();
	if(ch=='-')y=-1;
	}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*y;
}
int n,m,c,f;
bool b[N][N];
int xxx[N][N],yyy[N][N];
int ccc[N][N],fff[N][N];
long long ansc,ansf;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	T=read(),id=read();
	id--;id++;
	while(T--)
	{
		n=read(),m=read();
		c=read(),f=read();
		char ch;
		ansc=ansf=0ll;
		for(int i=1;i<=n;i++)
		{
			do{ch=getchar();
			}while(ch!='0'&&ch!='1');
			for(int j=1;j<=m;j++)
			{
				if(ch=='1')b[i][j]=0;
				else b[i][j]=1;
				ch=getchar();
			}
		}
		for(int i=1;i<=n;i++)
			yyy[i][m]=0;
		for(int i=1;i<=n;i++)
			for(int j=m-1;j;j--)
				if(b[i][j+1]&&b[i][j])
					yyy[i][j]=yyy[i][j+1]+1;
				else yyy[i][j]=0;
		for(int i=1;i<=m;i++)
			xxx[n][i]=0;
		for(int i=n-1;i;i--)
			for(int j=1;j<=m;j++)
				if(b[i+1][j]&&b[i][j])
					xxx[i][j]=xxx[i+1][j]+1;
				else xxx[i][j]=0;
		for(int i=1;i<=m;i++)
		{
			ccc[n][i]=0;
			if(!b[n-1][i]||!b[n][i])
			ccc[n-1][i]=0;
			else
			ccc[n-1][i]=yyy[n][i];
		}
		for(int i=n-2;i;i--)
			for(int j=1;j<=m;j++)
			{
				if(b[i+1][j]&&b[i][j])
					ccc[i][j]=ccc[i+2][j]+yyy[i+2][j];
				else
					ccc[i][j]=0;
				ansc=(ansc+ccc[i][j]*yyy[i][j])%mod;
			}
		for(int i=1;i<=m;i++)
		{
			fff[n][i]=0;
			fff[n-1][i]=0;
		}
		for(int i=n-2;i;i--)
			for(int j=1;j<=m;j++)
			{
				if(b[i+1][j]&&b[i][j])
					fff[i][j]=fff[i+2][j]+yyy[i+2][j]*xxx[i+2][j];
				else
					fff[i][j]=0;
				ansf=(ansf+fff[i][j]*yyy[i][j])%mod;
			}
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<yyy[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<xxx[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<ccc[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<fff[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';*/
		ansc=(ansc*c)%mod;
		ansf=(ansf*f)%mod;
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}/*
1 0
4 3 1 1
001
010
000
000*/
