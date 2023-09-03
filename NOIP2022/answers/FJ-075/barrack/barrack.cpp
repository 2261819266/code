#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int read()
{
	char ch;
	int s=1;
	while((ch=getchar())<'0' || ch>'9')
	  if(ch=='-')
	    s=-1;
	int res=ch-'0';
	while((ch=getchar())>='0' && ch<='9')
	  res=(res<<3)+(res<<1)+ch-'0';
	return res*s;
}
struct haha
{
	int to,next;
}a[1000001];
int head[100001],num=0;
void add(int aa,int bb)
{
	a[++num].to=bb;
	a[num].next=head[aa];
	head[aa]=num;
}
int n,m;
ll ksm(ll x,ll y)
{
	ll sum=1;
	while(y)
	{
		if(y&1)
		  sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
ll f[1000001][2];
void dfs(int u,int fa)
{
	f[u][0]=f[u][1]=1;
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa)
		  continue;
		dfs(v,u);
		f[u][0]=f[u][0]*f[v][0]*2LL%mod;
		f[u][1]=f[u][1]*(f[v][1]+f[v][0]*2LL)%mod;
	}
	f[u][1]=(f[u][1]-f[u][0]+mod)%mod;
	f[u][1]=(f[u][1]*2+f[u][0])%mod;
}
void go1()
{
	dfs(1,0);
	printf("%lld",(f[1][1]+(ksm(2,n-1)-1)*(n-1))%mod);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int aa=read(),bb=read();
		add(aa,bb);
		add(bb,aa);
	}
	if(m==n-1)
	  go1();
	else
	  printf("%lld",ksm(2,n)*(ll)n%mod);
}
