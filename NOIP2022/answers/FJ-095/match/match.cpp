#include<iostream>
#include<cstdio>
#define int __int128
using namespace std;
const int p=((int)1<<64);
int T,n,Q,MAXN,a[250001],b[250001],sta[250001][20],stb[250001][20],loog[250001];
int read()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res;
}
int ak(int l,int r)
{
	int le=loog[r-l+1];
	return int(max(sta[l][le],sta[r-(1<<le)+1][le]));
}
int bk(int l,int r)
{
	int le=loog[r-l+1];
	return int(max(stb[l][le],stb[r-(1<<le)+1][le]));
}
void prt(int x)
{
	if(x>9)prt(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();n=read();
	for(int i=1;i<=n;++i)a[i]=read(),sta[i][0]=a[i];
	for(int i=1;i<=n;++i)b[i]=read(),stb[i][0]=b[i];
	for(int i=2;i<=n;++i)loog[i]=loog[i/2]+1;
	MAXN=loog[n];
	for(int i=1;i<=MAXN;++i)
		for(int j=1;j+(1<<(i-1))-1<=n;++j)
		{
			sta[j][i]=max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
			stb[j][i]=max(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
		}
	Q=read();
	int l,r;
	while(Q--)
	{
		l=read();r=read();
		int ans=0;
		for(int i=l;i<=r;++i)
			for(int j=i;j<=r;++j)
				ans=(ans+ak(i,j)*bk(i,j)%p)%p;
		prt(ans);putchar('\n');
	}
	return 0;
}
