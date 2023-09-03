#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int p=998244353;
int read()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res;
}
bool readb()
{
	bool res=0;char ch=getchar();
	while(ch<'0'||ch>'1')ch=getchar();
	res=ch-'0';
	return res;
}
int T,id,n,m,mx[1010][1010][2],qzc[1010][1010],qzf[1010][1010],ansc,ansf;
bool c,f,a[1010][1010];
void dfs1()
{
	for(int x=1;x<=n;++x)
		for(int i=1,j;i<=m;++i)
		{
			while(!a[x][i]&&i<=m)++i;
			if(i>m)break;
			j=i;
			while(a[x][j]&&j<=m)++j;--j;
			for(int k=i;k<=j;++k)mx[x][k][1]=j-k;
			i=j;
		}
}
void dfs2()
{
	for(int y=1;y<=m;++y)
		for(int i=1,j;i<=n;++i)
		{
			while(!a[i][y]&&i<=n)++i;
			if(i>n)break;
			j=i;
			while(a[j][y]&&j<=n)++j;--j;
			for(int k=i;k<=j;++k)mx[k][y][0]=j-k;
			i=j;
		}
}
void dfs(int x,int y)
{
	for(int i=y-1;i>=1;--i)
	{
		if(!a[x][i])return;
		ansc=(ansc+(qzc[x+mx[x][i][0]][i]-qzc[x+1][i])*(y-i))%p;
		ansf=(ansf+(qzf[x+mx[x][i][0]][i]-qzf[x+1][i])*(y-i))%p;
	}
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T--)
	{
		if(id==1){printf("0 0");continue;}
		n=read();m=read();c=readb();f=readb();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=readb()^1;
		dfs1();dfs2();
		for(int j=1;j<=m;++j)
			for(int i=1;i<=n;++i)
			{
				qzc[i][j]=qzc[i-1][j]+mx[i][j][1];
				qzf[i][j]=qzf[i-1][j]+mx[i][j][1]*mx[i][j][0];
			}
		for(int i=1;i<=n-2;++i)
			for(int j=1;j<=m;++j)
			{
				if(!mx[i][j][1])continue;
				dfs(i,j+mx[i][j][1]);
				j+=mx[i][j][1];
			}
		cout<<ansc*c<<" "<<ansf*f<<'\n';
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				qzc[i][j]=0,qzf[i][j]=0,mx[i][j][1]=0,mx[i][j][0]=0;
		ansc=0;ansf=0;
	}
	return 0;
}
