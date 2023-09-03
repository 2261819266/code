#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int n,m;
int ok[101][101],fl[101];
struct edge{
	int fr,to;
	bool prt;
}e[100001];
int ans=0;
struct ufs{
	int f[101];
	void init(){for(int i=1;i<=n;i++)f[i]=i;}
	int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
	void hb(int x,int y){int u=gf(x),v=gf(y);if(u!=v)f[u]=v;}
}bcj;
bool checkk()
{
	bcj.init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ok[i][j])bcj.hb(i,j);
		}
	}
	int fath=-1;
	for(int i=1;i<=n;i++)
	{
		if(!fl[i])continue;
		if(fath==-1)fath=bcj.gf(i);
		else if(fath!=bcj.gf(i))return false;
	}
	return true;
}
bool check()
{
	bool all0=true;
	for(int i=1;i<=n;i++){if(fl[i]!=0)all0=false;}
	if(all0)return false;
	for(int i=1;i<=m;i++)
	{
		if(!e[i].prt)
		{
			ok[e[i].fr][e[i].to]=ok[e[i].to][e[i].fr]=0;
			bool yes=checkk();
			ok[e[i].fr][e[i].to]=ok[e[i].to][e[i].fr]=1;
			if(!yes)return false;
		}
	}
	return true;
}
void dfsnode(int now)
{
	if(now==n+1){if(check())ans=(ans+1)%1000000007;return;}
	fl[now]=1;dfsnode(now+1);
	fl[now]=0;dfsnode(now+1);
}
void dfsedge(int now)
{
	if(now==m+1){dfsnode(1);return;}
	e[now].prt=true;dfsedge(now+1);
	e[now].prt=false;dfsedge(now+1);
}
void force()
{
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].fr,&e[i].to);
		ok[e[i].fr][e[i].to]=ok[e[i].to][e[i].fr]=1;
	}
	dfsedge(1);
	printf("%d",ans);
}
const long long mod=1e9+7;
long long ksm(long long a,int b)
{
	long long res=1;
	while(b)
	{
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;b>>=1;
	}
	return res;
}
void line()
{
	long long tot=0;
	for(int i=0;i<n;i++)
	{
		long long num=(long long)(n-i);
		int edg=m-i,mid=max(0,i-1);
		long long ak1=ksm(2ll,mid);
		long long ak2=ksm(2ll,edg);
		tot=tot+((ak1*ak2)%mod*num)%mod;
		tot%=mod;
	}
	printf("%lld\n",tot);
}
void fortune()
{
	if(m==n-1)line();
	else
	{
		long long ak1=ksm(2ll,n);ak1=(ak1-1+mod)%mod;
		long long ak2=ksm(2ll,m);
		printf("%lld\n",(ak1*ak2)%mod);
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
//	fortune();
	if(n+m<=25)force();
	else fortune();
	return 0;
}
/*
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/
