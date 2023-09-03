#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
const int p=1e9+7;
int read()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m,ans,sum,x[30];
bool a[21][31][30],bj[30];
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++)
	{
		u=read(),v=read();
		for(int j=0;j<=m;++j)
			if(i!=j)a[u][v][j]=1,a[v][u][j]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][i][j]=1;
	for(int x=1;x<=m;++x)
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					a[i][j][x]=(a[i][k][x]&a[k][j][x])?1:a[i][j][x];
	for(int i=1;i<(1<<n);++i)
	{
		for(int j=1;j<=m;++j)bj[j]=0;
		for(int j=1;j<=n;++j)x[i]=0;x[0]=0;
		int tmp=i,jj=1;
		while(tmp)
		{
			if(tmp&1)x[++x[0]]=jj;
			tmp>>=1;++jj;
		}
		for(int j=1,zj;j<=x[0];++j)
		{
			zj=x[j];
			for(int k=1,zk;k<=x[0];++k)
			{
				zk=x[k];
				for(int l=1;l<=m;++l)
					if(!a[zj][zk][l])bj[l]=1;
			}
		}
		sum=0;
		for(int j=1;j<=m;++j)sum+=(bj[j]^1);
		ans=(ans+(1<<sum)%p)%p;
	}
	cout<<ans;
	return 0;
}
