#include<bits/stdc++.h>
#define N 5000
#define inf 0x3f3f3f3f
#define mod 1000000007ll
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
LL n,m,u[N],v[N],is[N],cnt[N],c[N][N];
LL out;
int up[N];
int getup(int u_)
{
	if(up[u_]==u_)
		return u_;
	return up[u_]=getup(up[u_]);
}
void check()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		up[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(is[i])
		{
			if(getup(u[i])!=getup(v[i]))
				up[getup(u[i])]=getup(v[i]);
		}
	}
	for(int i=1;i<=n;i++)
		cnt[getup(i)]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=cnt[i];j++)
			out=(out+c[cnt[i]][j])%mod;
}
void dfs(int k)
{
	if(k>m)
	{
		check();
		return;
	}
	is[k]=1;
	dfs(k+1);
	is[k]=0;
	dfs(k+1);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read();
		v[i]=read();
	}
	for(int i=0;i<=n;i++)
		c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	dfs(1);
	printf("%lld\n",out);
}
/*
3 2 1 2 2 3
4 4
1 2
2 3
3 1
1 4
*/
